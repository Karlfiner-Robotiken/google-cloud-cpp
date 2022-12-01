// Copyright 2020 Google LLC
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//      https://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "generator/internal/client_generator.h"
#include "google/cloud/internal/absl_str_cat_quiet.h"
#include "absl/memory/memory.h"
#include "generator/internal/codegen_utils.h"
#include "generator/internal/descriptor_utils.h"
#include "generator/internal/predicate_utils.h"
#include "generator/internal/printer.h"
#include <google/api/client.pb.h>
#include <google/protobuf/descriptor.h>

namespace google {
namespace cloud {
namespace generator_internal {

ClientGenerator::ClientGenerator(
    google::protobuf::ServiceDescriptor const* service_descriptor,
    VarsDictionary service_vars,
    std::map<std::string, VarsDictionary> service_method_vars,
    google::protobuf::compiler::GeneratorContext* context)
    : ServiceCodeGenerator("client_header_path", "client_cc_path",
                           service_descriptor, std::move(service_vars),
                           std::move(service_method_vars), context) {
  // Remember if there are methods from google.iam.v1.GetIamPolicyRequest and
  // google.iam.v1.SetIamPolicyRequest to google.iam.v1.Policy with signature
  // extensions. If so, we'll generate a "set" wrapper method to help prevent
  // simultaneous updates of a policy from overwriting each other.
  for (google::protobuf::MethodDescriptor const& method : methods()) {
    auto const& method_signature_extension =
        method.options().GetRepeatedExtension(google::api::method_signature);
    if (method.output_type()->full_name() == "google.iam.v1.Policy") {
      auto const& input_type = method.input_type()->full_name();
      for (auto const& extension : method_signature_extension) {
        if (input_type == "google.iam.v1.GetIamPolicyRequest" &&
            extension == "resource") {
          get_iam_policy_extension_ = &method;
        }
        if (input_type == "google.iam.v1.SetIamPolicyRequest" &&
            extension == "resource,policy") {
          set_iam_policy_extension_ = &method;
        }
      }
    }
  }
}

Status ClientGenerator::GenerateHeader() {
  HeaderPrint(CopyrightLicenseFileHeader());
  HeaderPrint(  // clang-format off
    "\n"
    "// Generated by the Codegen C++ plugin.\n"
    "// If you make any local changes, they will be lost.\n"
    "// source: $proto_file_name$\n"
    "\n"
    "#ifndef $header_include_guard$\n"
    "#define $header_include_guard$\n");
  // clang-format on

  // includes
  HeaderPrint("\n");
  HeaderLocalIncludes(
      {vars("connection_header_path"),
       IsExperimental() ? "google/cloud/experimental_tag.h" : "",
       "google/cloud/future.h", "google/cloud/options.h",
       "google/cloud/polling_policy.h", "google/cloud/status_or.h",
       "google/cloud/version.h"});
  if (get_iam_policy_extension_ && set_iam_policy_extension_) {
    HeaderLocalIncludes({"google/cloud/iam_updater.h"});
  }
  HeaderSystemIncludes(MethodSignatureWellKnownProtobufTypeIncludes());
  HeaderSystemIncludes(
      {HasLongrunningMethod() ? "google/longrunning/operations.grpc.pb.h" : "",
       HasMessageWithMapField() ? "map" : "", "memory"});

  auto result = HeaderOpenNamespaces();
  if (!result.ok()) return result;

  // Client Class
  HeaderPrint(
      R"""(
$class_comment_block$
class $client_class_name$ {
 public:
  explicit $client_class_name$()""");
  if (IsExperimental()) HeaderPrint("ExperimentalTag, ");
  HeaderPrint(
      R"""(std::shared_ptr<$connection_class_name$> connection, Options opts = {});
  ~$client_class_name$();

  ///@{
  // @name Copy and move support
  $client_class_name$($client_class_name$ const&) = default;
  $client_class_name$& operator=($client_class_name$ const&) = default;
  $client_class_name$($client_class_name$&&) = default;
  $client_class_name$& operator=($client_class_name$&&) = default;
  ///@}

  ///@{
  // @name Equality
  friend bool operator==($client_class_name$ const& a, $client_class_name$ const& b) {
    return a.connection_ == b.connection_;
  }
  friend bool operator!=($client_class_name$ const& a, $client_class_name$ const& b) {
    return !(a == b);
  }
  ///@}
)""");

  for (google::protobuf::MethodDescriptor const& method : methods()) {
    if (IsBidirStreaming(method)) {
      HeaderPrintMethod(
          method, __FILE__, __LINE__,
          absl::StrCat(
              "\n", FormatMethodComments(method, ""),
              // clang-format off
R"""(  std::unique_ptr<::google::cloud::AsyncStreamingReadWriteRpc<
      $request_type$,
      $response_type$>>
  Async$method_name$(Options opts = {});
)"""));
      // clang-format on
      continue;
    }
    auto method_signature_extension =
        method.options().GetRepeatedExtension(google::api::method_signature);
    for (int i = 0; i < method_signature_extension.size(); ++i) {
      if (OmitMethodSignature(method, i)) continue;
      std::string const method_string = absl::StrCat(
          "  $method_name$($method_signature", i, "$Options opts = {});\n");
      std::string const signature = method_signature_extension[i];
      HeaderPrintMethod(
          method,
          {MethodPattern(
               {{"\n"},
                {FormatMethodCommentsMethodSignature(method, signature)},
                {IsResponseTypeEmpty,
                 // clang-format off
                   "  Status\n",
                   "  StatusOr<$response_type$>\n"},
                // clang-format on
                {method_string}},
               All(IsNonStreaming, Not(IsLongrunningOperation),
                   Not(IsPaginated))),
           MethodPattern(
               {{"\n"},
                {FormatMethodCommentsMethodSignature(method, signature)},
                {IsResponseTypeEmpty,
                 // clang-format off
                    "  future<Status>\n",
                    "  future<StatusOr<$longrunning_deduced_response_type$>>\n"},
                // clang-format on
                {method_string}},
               All(IsNonStreaming, IsLongrunningOperation, Not(IsPaginated))),
           MethodPattern(
               {
                   {"\n"},
                   {FormatMethodCommentsMethodSignature(method, signature)},
                   {"  StreamRange<$range_output_type$>\n"},
                   {method_string},
               },
               All(IsNonStreaming, Not(IsLongrunningOperation), IsPaginated)),
           MethodPattern(
               {
                   {"\n"},
                   {FormatMethodCommentsMethodSignature(method, signature)},
                   {"  StreamRange<$response_type$>\n"},
                   {method_string},
               },
               IsStreamingRead)},
          __FILE__, __LINE__);

      if (get_iam_policy_extension_ && set_iam_policy_extension_ == &method) {
        auto response_type = ProtoNameToCppName(
            set_iam_policy_extension_->output_type()->full_name());
        auto set_method_name = set_iam_policy_extension_->name();
        auto get_method_name = get_iam_policy_extension_->name();
        HeaderPrint({
            PredicatedFragment<void>(""),
            {R"""(
  /**
   * Updates the IAM policy for @p resource using an optimistic concurrency
   * control loop.
   *
   * The loop fetches the current policy for @p resource, and passes it to @p
   * updater, which should return the new policy. This new policy should use the
   * current etag so that the read-modify-write cycle can detect races and rerun
   * the update when there is a mismatch. If the new policy does not have an
   * etag, the existing policy will be blindly overwritten. If @p updater does
   * not yield a policy, the control loop is terminated and kCancelled is
   * returned.
   *
   * @param resource  Required. The resource for which the policy is being
   * specified. See the operation documentation for the appropriate value for
   * this field.
   * @param updater  Required. Functor to map the current policy to a new one.
   * @param opts  Optional. Override the class-level options, such as retry and
   *    backoff policies.
)"""},
            {"   * @return " + response_type + "\n"},
            {"   */\n"},
            {"  StatusOr<" + response_type + ">\n"},
            {"  " + set_method_name},
            {"(std::string const& resource,"
             " IamUpdater const& updater,"
             " Options opts = {});\n"},
        });
      }
    }
    HeaderPrintMethod(
        method,
        {MethodPattern(
             {
                 {"\n"},
                 {FormatMethodCommentsProtobufRequest(method)},
                 {IsResponseTypeEmpty,
                  // clang-format off
    "  Status\n",
    "  StatusOr<$response_type$>\n"},
   {"  $method_name$($request_type$ const& request, Options opts = {});\n"}
                 // clang-format on
             },
             All(IsNonStreaming, Not(IsLongrunningOperation),
                 Not(IsPaginated))),
         MethodPattern(
             {
                 {"\n"},
                 {FormatMethodCommentsProtobufRequest(method)},
                 {IsResponseTypeEmpty,
                  // clang-format off
    "  future<Status>\n",
    "  future<StatusOr<$longrunning_deduced_response_type$>>\n"},
   {"  $method_name$($request_type$ const& request, Options opts = {});\n"}
                 // clang-format on
             },
             All(IsNonStreaming, IsLongrunningOperation, Not(IsPaginated))),
         MethodPattern(
             {
                 {"\n"},
                 {FormatMethodCommentsProtobufRequest(method)},
                 // clang-format off
   {"  StreamRange<$range_output_type$>\n"
    "  $method_name$($request_type$ request, Options opts = {});\n"},
                 // clang-format on
             },
             All(IsNonStreaming, Not(IsLongrunningOperation), IsPaginated)),
         MethodPattern(
             {
                 {"\n"},
                 {FormatMethodCommentsProtobufRequest(method)},
                 // clang-format off
   {"  StreamRange<$response_type$>\n"
    "  $method_name$($request_type$ const& request, Options opts = {});\n"},
                 // clang-format on
             },
             IsStreamingRead)},
        __FILE__, __LINE__);
  }

  for (google::protobuf::MethodDescriptor const& method : async_methods()) {
    if (IsStreamingRead(method)) continue;
    if (IsStreamingWrite(method)) continue;
    auto method_signature_extension =
        method.options().GetRepeatedExtension(google::api::method_signature);
    for (int i = 0; i < method_signature_extension.size(); ++i) {
      std::string const method_string =
          absl::StrCat("  Async$method_name$($method_signature", i,
                       "$Options opts = {});\n");
      std::string const signature = method_signature_extension[i];
      HeaderPrintMethod(
          method,
          {MethodPattern(
              {{"\n"},
               {FormatMethodCommentsMethodSignature(method, signature)},
               {IsResponseTypeEmpty,
                // clang-format off
                   "  future<Status>\n",
                   "  future<StatusOr<$response_type$>>\n"},
               // clang-format on
               {method_string}},
              All(IsNonStreaming, Not(IsLongrunningOperation),
                  Not(IsPaginated)))},
          __FILE__, __LINE__);
    }
    HeaderPrintMethod(
        method,
        {MethodPattern(
            {
                {"\n"},
                {FormatMethodCommentsProtobufRequest(method)},
                {IsResponseTypeEmpty,
                 // clang-format off
    "  future<Status>\n",
    "  future<StatusOr<$response_type$>>\n"},
   {"  Async$method_name$($request_type$ const& request, Options opts = {});\n"}
                // clang-format on
            },
            All(IsNonStreaming, Not(IsLongrunningOperation),
                Not(IsPaginated)))},
        __FILE__, __LINE__);
  }

  HeaderPrint(  // clang-format off
    "\n"
    " private:\n"
    "  std::shared_ptr<$connection_class_name$> connection_;\n"
    "  Options options_;\n");
  // clang-format on

  // close Client class
  HeaderPrint("};\n");

  HeaderCloseNamespaces();
  // close header guard
  HeaderPrint("\n#endif  // $header_include_guard$\n");
  return {};
}

Status ClientGenerator::GenerateCc() {
  CcPrint(CopyrightLicenseFileHeader());
  CcPrint(  // clang-format off
    "\n"
    "// Generated by the Codegen C++ plugin.\n"
    "// If you make any local changes, they will be lost.\n"
    "// source: $proto_file_name$\n");
  // clang-format on

  // includes
  CcPrint("\n");
  CcLocalIncludes({vars("client_header_path")});
  CcSystemIncludes({"memory"});
  if (get_iam_policy_extension_ && set_iam_policy_extension_) {
    CcLocalIncludes({vars("options_header_path")});
    CcSystemIncludes({"thread"});
  }

  auto result = CcOpenNamespaces();
  if (!result.ok()) return result;

  CcPrint(R"""(
$client_class_name$::$client_class_name$()""");
  if (IsExperimental()) CcPrint("ExperimentalTag,");
  CcPrint(R"""(
    std::shared_ptr<$connection_class_name$> connection, Options opts)
    : connection_(std::move(connection)),
      options_(internal::MergeOptions(std::move(opts),
      connection_->options())) {}
$client_class_name$::~$client_class_name$() = default;
)""");
  // clang-format on

  for (google::protobuf::MethodDescriptor const& method : methods()) {
    if (IsBidirStreaming(method)) {
      CcPrintMethod(method, __FILE__, __LINE__,
                    R"""(
std::unique_ptr<::google::cloud::AsyncStreamingReadWriteRpc<
    $request_type$,
    $response_type$>>
$client_class_name$::Async$method_name$(Options opts) {
  internal::OptionsSpan span(
      internal::MergeOptions(std::move(opts), options_));
  return connection_->Async$method_name$();
}
)""");
      continue;
    }
    auto method_signature_extension =
        method.options().GetRepeatedExtension(google::api::method_signature);
    for (int i = 0; i < method_signature_extension.size(); ++i) {
      if (OmitMethodSignature(method, i)) continue;
      std::string method_string =
          absl::StrCat("$client_class_name$::$method_name$($method_signature",
                       i, "$Options opts) {\n");
      std::string method_request_string =
          absl::StrCat("$method_request_setters", i, "$");
      CcPrintMethod(
          method,
          {MethodPattern(
               {
                   {IsResponseTypeEmpty,
                    // clang-format off
                   "\nStatus\n",
                   "\nStatusOr<$response_type$>\n"},
                  {method_string},
                  {"  internal::OptionsSpan span(internal::MergeOptions("
                   "std::move(opts), options_));\n"},
                  {"  $request_type$ request;\n"},
                   {method_request_string},
                  {"  return connection_->$method_name$(request);\n"
                   "}\n"}
                   // clang-format on
               },
               All(IsNonStreaming, Not(IsLongrunningOperation),
                   Not(IsPaginated))),
           MethodPattern(
               {
                   {IsResponseTypeEmpty,
                    // clang-format off
                    "\nfuture<Status>\n",
                    "\nfuture<StatusOr<$longrunning_deduced_response_type$>>\n"},
                  {method_string},
                  {"  internal::OptionsSpan span(internal::MergeOptions("
                   "std::move(opts), options_));\n"},
                  {"  $request_type$ request;\n"},
                   {method_request_string},
                  {"  return connection_->$method_name$(request);\n"
                  "}\n"}
                   // clang-format on
               },
               All(IsNonStreaming, IsLongrunningOperation, Not(IsPaginated))),
           MethodPattern(
               {
                   // clang-format off
                   {"\nStreamRange<$range_output_type$>\n"},
                  {method_string},
                  {"  internal::OptionsSpan span(internal::MergeOptions("
                   "std::move(opts), options_));\n"},
                  {"  $request_type$ request;\n"},
                   {method_request_string},
                  {"  return connection_->$method_name$(request);\n"
                  "}\n"}
                   // clang-format on
               },
               All(IsNonStreaming, Not(IsLongrunningOperation), IsPaginated)),
           MethodPattern(
               {
                   // clang-format off
                   {"\nStreamRange<$response_type$>\n"},
                  {method_string},
                  {"  internal::OptionsSpan span(internal::MergeOptions("
                   "std::move(opts), options_));\n"},
                  {"  $request_type$ request;\n"},
                   {method_request_string},
                  {"  return connection_->$method_name$(request);\n"
                  "}\n"}
                   // clang-format on
               },
               IsStreamingRead)},
          __FILE__, __LINE__);

      if (get_iam_policy_extension_ && set_iam_policy_extension_ == &method) {
        auto response_type = ProtoNameToCppName(
            set_iam_policy_extension_->output_type()->full_name());
        auto set_method_name = set_iam_policy_extension_->name();
        auto get_method_name = get_iam_policy_extension_->name();
        CcPrint({
            PredicatedFragment<void>(""),
            {"\nStatusOr<" + response_type + ">\n"},
            {"$client_class_name$::" + set_method_name},
            {"(std::string const& resource,"
             " IamUpdater const& updater,"
             " Options opts) {\n"
             "  internal::CheckExpectedOptions<$service_name$"
             "BackoffPolicyOption>(opts, __func__);\n"
             "  internal::OptionsSpan span(internal::MergeOptions("
             "std::move(opts), options_));\n"},
            {"  "},
            {ProtoNameToCppName(
                get_iam_policy_extension_->input_type()->full_name())},
            {" get_request;\n"},
            {"  get_request.set_resource(resource);\n"},
            {"  "},
            {ProtoNameToCppName(
                set_iam_policy_extension_->input_type()->full_name())},
            {" set_request;\n"
             "  set_request.set_resource(resource);\n"
             "  auto backoff_policy = internal::CurrentOptions()"
             ".get<$service_name$BackoffPolicyOption>();\n"
             "  if (backoff_policy != nullptr) {\n"
             "    backoff_policy = backoff_policy->clone();\n"
             "  }\n"
             "  for (;;) {\n"
             "    auto recent = connection_->"},
            {get_method_name + "(get_request);\n"},
            {"    if (!recent) {\n"
             "      return recent.status();\n"
             "    }\n"
             "    auto policy = updater(*std::move(recent));\n"
             "    if (!policy) {\n"
             "      return Status(StatusCode::kCancelled,"
             " \"updater did not yield a policy\");\n"
             "    }\n"
             "    *set_request.mutable_policy() = *std::move(policy);\n"
             "    auto result = connection_->"},
            {set_method_name + "(set_request);\n"},
            {"    if (result ||\n"
             "        result.status().code() != StatusCode::kAborted ||\n"
             "        backoff_policy == nullptr) {\n"
             "      return result;\n"
             "    }\n"
             "    std::this_thread::sleep_for("
             "backoff_policy->OnCompletion());\n"
             "  }\n"
             "}\n"},
        });
      }
    }
    CcPrintMethod(
        method,
        {MethodPattern(
             {
                 {IsResponseTypeEmpty,
                  // clang-format off
    "\nStatus\n",
    "\nStatusOr<$response_type$>\n"},
   {"$client_class_name$::$method_name$($request_type$ const& request"
    ", Options opts) {\n"
    "  internal::OptionsSpan span(internal::MergeOptions("
    "std::move(opts), options_));\n"
    "  return connection_->$method_name$(request);\n"
    "}\n"}
                 // clang-format on
             },
             All(IsNonStreaming, Not(IsLongrunningOperation),
                 Not(IsPaginated))),
         MethodPattern(
             {
                 {IsResponseTypeEmpty,
                  // clang-format off
    "\nfuture<Status>\n",
    "\nfuture<StatusOr<$longrunning_deduced_response_type$>>\n"},
   {"$client_class_name$::$method_name$($request_type$ const& request"
    ", Options opts) {\n"
    "  internal::OptionsSpan span(internal::MergeOptions("
    "std::move(opts), options_));\n"
    "  return connection_->$method_name$(request);\n"
    "}\n"}
                 // clang-format on
             },
             All(IsNonStreaming, IsLongrunningOperation, Not(IsPaginated))),
         MethodPattern(
             {
                 // clang-format off
   {"\nStreamRange<$range_output_type$>\n"
    "$client_class_name$::$method_name$($request_type$ request"
    ", Options opts) {\n"
    "  internal::OptionsSpan span(internal::MergeOptions("
    "std::move(opts), options_));\n"
    "  return connection_->$method_name$(std::move(request));\n"
    "}\n"}
                 // clang-format on
             },
             All(IsNonStreaming, Not(IsLongrunningOperation), IsPaginated)),
         MethodPattern(
             {
                 // clang-format off
   {"\nStreamRange<$response_type$>\n"
    "$client_class_name$::$method_name$($request_type$ const& request"
    ", Options opts) {\n"
    "  internal::OptionsSpan span(internal::MergeOptions("
    "std::move(opts), options_));\n"
    "  return connection_->$method_name$(request);\n"
    "}\n"}
                 // clang-format on
             },
             IsStreamingRead)},
        __FILE__, __LINE__);
  }

  for (google::protobuf::MethodDescriptor const& method : async_methods()) {
    if (IsStreamingRead(method)) continue;
    if (IsStreamingWrite(method)) continue;
    auto method_signature_extension =
        method.options().GetRepeatedExtension(google::api::method_signature);
    for (int i = 0; i < method_signature_extension.size(); ++i) {
      std::string method_string = absl::StrCat(
          "$client_class_name$::Async$method_name$($method_signature", i,
          "$Options opts) {\n");
      std::string method_request_string =
          absl::StrCat("$method_request_setters", i, "$");
      CcPrintMethod(
          method,
          {MethodPattern(
              {
                  {IsResponseTypeEmpty,
                   // clang-format off
                   "\nfuture<Status>\n",
                   "\nfuture<StatusOr<$response_type$>>\n"},
                  {method_string},
                  {"  internal::OptionsSpan span(internal::MergeOptions("
                   "std::move(opts), options_));\n"},
                  {"  $request_type$ request;\n"},
                   {method_request_string},
                  {"  return connection_->Async$method_name$(request);\n"
                   "}\n"}
                  // clang-format on
              },
              All(IsNonStreaming, Not(IsLongrunningOperation),
                  Not(IsPaginated)))},
          __FILE__, __LINE__);
    }
    CcPrintMethod(
        method,
        {MethodPattern(
            {
                {IsResponseTypeEmpty,
                 // clang-format off
    "\nfuture<Status>\n",
    "\nfuture<StatusOr<$response_type$>>\n"},
   {"$client_class_name$::Async$method_name$($request_type$ const& request"
    ", Options opts) {\n"
    "  internal::OptionsSpan span(internal::MergeOptions("
    "std::move(opts), options_));\n"
    "  return connection_->Async$method_name$(request);\n"
    "}\n"}
                // clang-format on
            },
            All(IsNonStreaming, Not(IsLongrunningOperation),
                Not(IsPaginated)))},
        __FILE__, __LINE__);
  }

  CcCloseNamespaces();
  return {};
}

}  // namespace generator_internal
}  // namespace cloud
}  // namespace google
