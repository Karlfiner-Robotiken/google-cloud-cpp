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
// source: google/cloud/dialogflow/cx/v3/session.proto

#ifndef GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_DIALOGFLOW_CX_SESSIONS_CLIENT_H
#define GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_DIALOGFLOW_CX_SESSIONS_CLIENT_H

#include "google/cloud/dialogflow_cx/sessions_connection.h"
#include "google/cloud/future.h"
#include "google/cloud/options.h"
#include "google/cloud/polling_policy.h"
#include "google/cloud/status_or.h"
#include "google/cloud/version.h"
#include <memory>

namespace google {
namespace cloud {
namespace dialogflow_cx {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

///
/// A session represents an interaction with a user. You retrieve user input
/// and pass it to the
/// [DetectIntent][google.cloud.dialogflow.cx.v3.Sessions.DetectIntent] method
/// to determine user intent and respond.
///
/// @par Equality
///
/// Instances of this class created via copy-construction or copy-assignment
/// always compare equal. Instances created with equal
/// `std::shared_ptr<*Connection>` objects compare equal. Objects that compare
/// equal share the same underlying resources.
///
/// @par Performance
///
/// Creating a new instance of this class is a relatively expensive operation,
/// new objects establish new connections to the service. In contrast,
/// copy-construction, move-construction, and the corresponding assignment
/// operations are relatively efficient as the copies share all underlying
/// resources.
///
/// @par Thread Safety
///
/// Concurrent access to different instances of this class, even if they compare
/// equal, is guaranteed to work. Two or more threads operating on the same
/// instance of this class is not guaranteed to work. Since copy-construction
/// and move-construction is a relatively efficient operation, consider using
/// such a copy when using this class from multiple threads.
///
class SessionsClient {
 public:
  explicit SessionsClient(std::shared_ptr<SessionsConnection> connection,
                          Options opts = {});
  ~SessionsClient();

  ///@{
  /// @name Copy and move support
  SessionsClient(SessionsClient const&) = default;
  SessionsClient& operator=(SessionsClient const&) = default;
  SessionsClient(SessionsClient&&) = default;
  SessionsClient& operator=(SessionsClient&&) = default;
  ///@}

  ///@{
  /// @name Equality
  friend bool operator==(SessionsClient const& a, SessionsClient const& b) {
    return a.connection_ == b.connection_;
  }
  friend bool operator!=(SessionsClient const& a, SessionsClient const& b) {
    return !(a == b);
  }
  ///@}

  ///
  /// Processes a natural language query and returns structured, actionable data
  /// as a result. This method is not idempotent, because it may cause session
  /// entity types to be updated, which in turn might affect results of future
  /// queries.
  ///
  /// Note: Always use agent versions for production traffic.
  /// See [Versions and
  /// environments](https://cloud.google.com/dialogflow/cx/docs/concept/version).
  ///
  /// @param request
  /// @googleapis_link{google::cloud::dialogflow::cx::v3::DetectIntentRequest,google/cloud/dialogflow/cx/v3/session.proto#L119}
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return
  /// @googleapis_link{google::cloud::dialogflow::cx::v3::DetectIntentResponse,google/cloud/dialogflow/cx/v3/session.proto#L154}
  ///
  /// [google.cloud.dialogflow.cx.v3.DetectIntentRequest]:
  /// @googleapis_reference_link{google/cloud/dialogflow/cx/v3/session.proto#L119}
  /// [google.cloud.dialogflow.cx.v3.DetectIntentResponse]:
  /// @googleapis_reference_link{google/cloud/dialogflow/cx/v3/session.proto#L154}
  ///
  StatusOr<google::cloud::dialogflow::cx::v3::DetectIntentResponse>
  DetectIntent(
      google::cloud::dialogflow::cx::v3::DetectIntentRequest const& request,
      Options opts = {});

  ///
  /// Processes a natural language query in audio format in a streaming fashion
  /// and returns structured, actionable data as a result. This method is only
  /// available via the gRPC API (not REST).
  ///
  /// Note: Always use agent versions for production traffic.
  /// See [Versions and
  /// environments](https://cloud.google.com/dialogflow/cx/docs/concept/version).
  ///
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return A bidirectional streaming interface with request (write) type:
  /// @googleapis_link{google::cloud::dialogflow::cx::v3::StreamingDetectIntentRequest,google/cloud/dialogflow/cx/v3/session.proto#L234}
  /// and response (read) type:
  /// @googleapis_link{google::cloud::dialogflow::cx::v3::StreamingDetectIntentResponse,google/cloud/dialogflow/cx/v3/session.proto#L300}
  ///
  /// [google.cloud.dialogflow.cx.v3.StreamingDetectIntentRequest]:
  /// @googleapis_reference_link{google/cloud/dialogflow/cx/v3/session.proto#L234}
  /// [google.cloud.dialogflow.cx.v3.StreamingDetectIntentResponse]:
  /// @googleapis_reference_link{google/cloud/dialogflow/cx/v3/session.proto#L300}
  ///
  std::unique_ptr<::google::cloud::AsyncStreamingReadWriteRpc<
      google::cloud::dialogflow::cx::v3::StreamingDetectIntentRequest,
      google::cloud::dialogflow::cx::v3::StreamingDetectIntentResponse>>
  AsyncStreamingDetectIntent(Options opts = {});

  ///
  /// Returns preliminary intent match results, doesn't change the session
  /// status.
  ///
  /// @param request
  /// @googleapis_link{google::cloud::dialogflow::cx::v3::MatchIntentRequest,google/cloud/dialogflow/cx/v3/session.proto#L811}
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return
  /// @googleapis_link{google::cloud::dialogflow::cx::v3::MatchIntentResponse,google/cloud/dialogflow/cx/v3/session.proto#L839}
  ///
  /// [google.cloud.dialogflow.cx.v3.MatchIntentRequest]:
  /// @googleapis_reference_link{google/cloud/dialogflow/cx/v3/session.proto#L811}
  /// [google.cloud.dialogflow.cx.v3.MatchIntentResponse]:
  /// @googleapis_reference_link{google/cloud/dialogflow/cx/v3/session.proto#L839}
  ///
  StatusOr<google::cloud::dialogflow::cx::v3::MatchIntentResponse> MatchIntent(
      google::cloud::dialogflow::cx::v3::MatchIntentRequest const& request,
      Options opts = {});

  ///
  /// Fulfills a matched intent returned by
  /// [MatchIntent][google.cloud.dialogflow.cx.v3.Sessions.MatchIntent]. Must be
  /// called after
  /// [MatchIntent][google.cloud.dialogflow.cx.v3.Sessions.MatchIntent], with
  /// input from
  /// [MatchIntentResponse][google.cloud.dialogflow.cx.v3.MatchIntentResponse].
  /// Otherwise, the behavior is undefined.
  ///
  /// @param request
  /// @googleapis_link{google::cloud::dialogflow::cx::v3::FulfillIntentRequest,google/cloud/dialogflow/cx/v3/session.proto#L875}
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return
  /// @googleapis_link{google::cloud::dialogflow::cx::v3::FulfillIntentResponse,google/cloud/dialogflow/cx/v3/session.proto#L888}
  ///
  /// [google.cloud.dialogflow.cx.v3.FulfillIntentRequest]:
  /// @googleapis_reference_link{google/cloud/dialogflow/cx/v3/session.proto#L875}
  /// [google.cloud.dialogflow.cx.v3.FulfillIntentResponse]:
  /// @googleapis_reference_link{google/cloud/dialogflow/cx/v3/session.proto#L888}
  /// [google.cloud.dialogflow.cx.v3.MatchIntentResponse]:
  /// @googleapis_reference_link{google/cloud/dialogflow/cx/v3/session.proto#L839}
  /// [google.cloud.dialogflow.cx.v3.Sessions.MatchIntent]:
  /// @googleapis_reference_link{google/cloud/dialogflow/cx/v3/session.proto#L88}
  ///
  StatusOr<google::cloud::dialogflow::cx::v3::FulfillIntentResponse>
  FulfillIntent(
      google::cloud::dialogflow::cx::v3::FulfillIntentRequest const& request,
      Options opts = {});

 private:
  std::shared_ptr<SessionsConnection> connection_;
  Options options_;
};

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace dialogflow_cx
}  // namespace cloud
}  // namespace google

#endif  // GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_DIALOGFLOW_CX_SESSIONS_CLIENT_H
