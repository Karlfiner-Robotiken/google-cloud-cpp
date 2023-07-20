// Copyright 2022 Google LLC
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

// Generated by the Codegen C++ plugin.
// If you make any local changes, they will be lost.
// source: google/api/apikeys/v2/apikeys.proto

#include "google/cloud/apikeys/v2/internal/api_keys_logging_decorator.h"
#include "google/cloud/internal/log_wrapper.h"
#include "google/cloud/status_or.h"
#include <google/api/apikeys/v2/apikeys.grpc.pb.h>
#include <memory>

namespace google {
namespace cloud {
namespace apikeys_v2_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

ApiKeysLogging::ApiKeysLogging(std::shared_ptr<ApiKeysStub> child,
                               TracingOptions tracing_options,
                               std::set<std::string> const& components)
    : child_(std::move(child)),
      tracing_options_(std::move(tracing_options)),
      stream_logging_(components.find("rpc-streams") != components.end()) {}

future<StatusOr<google::longrunning::Operation>> ApiKeysLogging::AsyncCreateKey(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::api::apikeys::v2::CreateKeyRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](google::cloud::CompletionQueue& cq,
             std::shared_ptr<grpc::ClientContext> context,
             google::api::apikeys::v2::CreateKeyRequest const& request) {
        return child_->AsyncCreateKey(cq, std::move(context), request);
      },
      cq, std::move(context), request, __func__, tracing_options_);
}

StatusOr<google::api::apikeys::v2::ListKeysResponse> ApiKeysLogging::ListKeys(
    grpc::ClientContext& context,
    google::api::apikeys::v2::ListKeysRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](grpc::ClientContext& context,
             google::api::apikeys::v2::ListKeysRequest const& request) {
        return child_->ListKeys(context, request);
      },
      context, request, __func__, tracing_options_);
}

StatusOr<google::api::apikeys::v2::Key> ApiKeysLogging::GetKey(
    grpc::ClientContext& context,
    google::api::apikeys::v2::GetKeyRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](grpc::ClientContext& context,
             google::api::apikeys::v2::GetKeyRequest const& request) {
        return child_->GetKey(context, request);
      },
      context, request, __func__, tracing_options_);
}

StatusOr<google::api::apikeys::v2::GetKeyStringResponse>
ApiKeysLogging::GetKeyString(
    grpc::ClientContext& context,
    google::api::apikeys::v2::GetKeyStringRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](grpc::ClientContext& context,
             google::api::apikeys::v2::GetKeyStringRequest const& request) {
        return child_->GetKeyString(context, request);
      },
      context, request, __func__, tracing_options_);
}

future<StatusOr<google::longrunning::Operation>> ApiKeysLogging::AsyncUpdateKey(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::api::apikeys::v2::UpdateKeyRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](google::cloud::CompletionQueue& cq,
             std::shared_ptr<grpc::ClientContext> context,
             google::api::apikeys::v2::UpdateKeyRequest const& request) {
        return child_->AsyncUpdateKey(cq, std::move(context), request);
      },
      cq, std::move(context), request, __func__, tracing_options_);
}

future<StatusOr<google::longrunning::Operation>> ApiKeysLogging::AsyncDeleteKey(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::api::apikeys::v2::DeleteKeyRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](google::cloud::CompletionQueue& cq,
             std::shared_ptr<grpc::ClientContext> context,
             google::api::apikeys::v2::DeleteKeyRequest const& request) {
        return child_->AsyncDeleteKey(cq, std::move(context), request);
      },
      cq, std::move(context), request, __func__, tracing_options_);
}

future<StatusOr<google::longrunning::Operation>>
ApiKeysLogging::AsyncUndeleteKey(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::api::apikeys::v2::UndeleteKeyRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](google::cloud::CompletionQueue& cq,
             std::shared_ptr<grpc::ClientContext> context,
             google::api::apikeys::v2::UndeleteKeyRequest const& request) {
        return child_->AsyncUndeleteKey(cq, std::move(context), request);
      },
      cq, std::move(context), request, __func__, tracing_options_);
}

StatusOr<google::api::apikeys::v2::LookupKeyResponse> ApiKeysLogging::LookupKey(
    grpc::ClientContext& context,
    google::api::apikeys::v2::LookupKeyRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](grpc::ClientContext& context,
             google::api::apikeys::v2::LookupKeyRequest const& request) {
        return child_->LookupKey(context, request);
      },
      context, request, __func__, tracing_options_);
}

future<StatusOr<google::longrunning::Operation>>
ApiKeysLogging::AsyncGetOperation(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::longrunning::GetOperationRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](google::cloud::CompletionQueue& cq,
             std::shared_ptr<grpc::ClientContext> context,
             google::longrunning::GetOperationRequest const& request) {
        return child_->AsyncGetOperation(cq, std::move(context), request);
      },
      cq, std::move(context), request, __func__, tracing_options_);
}

future<Status> ApiKeysLogging::AsyncCancelOperation(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::longrunning::CancelOperationRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](google::cloud::CompletionQueue& cq,
             std::shared_ptr<grpc::ClientContext> context,
             google::longrunning::CancelOperationRequest const& request) {
        return child_->AsyncCancelOperation(cq, std::move(context), request);
      },
      cq, std::move(context), request, __func__, tracing_options_);
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace apikeys_v2_internal
}  // namespace cloud
}  // namespace google
