// Copyright 2021 Google LLC
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
// source: google/cloud/pubsublite/v1/admin.proto

#ifndef GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_PUBSUBLITE_INTERNAL_ADMIN_LOGGING_DECORATOR_H
#define GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_PUBSUBLITE_INTERNAL_ADMIN_LOGGING_DECORATOR_H

#include "google/cloud/pubsublite/internal/admin_stub.h"
#include "google/cloud/tracing_options.h"
#include "google/cloud/version.h"
#include <google/longrunning/operations.grpc.pb.h>
#include <memory>
#include <set>
#include <string>

namespace google {
namespace cloud {
namespace pubsublite_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

class AdminServiceLogging : public AdminServiceStub {
 public:
  ~AdminServiceLogging() override = default;
  AdminServiceLogging(std::shared_ptr<AdminServiceStub> child,
                      TracingOptions tracing_options,
                      std::set<std::string> const& components);

  StatusOr<google::cloud::pubsublite::v1::Topic> CreateTopic(
      grpc::ClientContext& context,
      google::cloud::pubsublite::v1::CreateTopicRequest const& request)
      override;

  StatusOr<google::cloud::pubsublite::v1::Topic> GetTopic(
      grpc::ClientContext& context,
      google::cloud::pubsublite::v1::GetTopicRequest const& request) override;

  StatusOr<google::cloud::pubsublite::v1::TopicPartitions> GetTopicPartitions(
      grpc::ClientContext& context,
      google::cloud::pubsublite::v1::GetTopicPartitionsRequest const& request)
      override;

  StatusOr<google::cloud::pubsublite::v1::ListTopicsResponse> ListTopics(
      grpc::ClientContext& context,
      google::cloud::pubsublite::v1::ListTopicsRequest const& request) override;

  StatusOr<google::cloud::pubsublite::v1::Topic> UpdateTopic(
      grpc::ClientContext& context,
      google::cloud::pubsublite::v1::UpdateTopicRequest const& request)
      override;

  Status DeleteTopic(grpc::ClientContext& context,
                     google::cloud::pubsublite::v1::DeleteTopicRequest const&
                         request) override;

  StatusOr<google::cloud::pubsublite::v1::ListTopicSubscriptionsResponse>
  ListTopicSubscriptions(
      grpc::ClientContext& context,
      google::cloud::pubsublite::v1::ListTopicSubscriptionsRequest const&
          request) override;

  StatusOr<google::cloud::pubsublite::v1::Subscription> CreateSubscription(
      grpc::ClientContext& context,
      google::cloud::pubsublite::v1::CreateSubscriptionRequest const& request)
      override;

  StatusOr<google::cloud::pubsublite::v1::Subscription> GetSubscription(
      grpc::ClientContext& context,
      google::cloud::pubsublite::v1::GetSubscriptionRequest const& request)
      override;

  StatusOr<google::cloud::pubsublite::v1::ListSubscriptionsResponse>
  ListSubscriptions(
      grpc::ClientContext& context,
      google::cloud::pubsublite::v1::ListSubscriptionsRequest const& request)
      override;

  StatusOr<google::cloud::pubsublite::v1::Subscription> UpdateSubscription(
      grpc::ClientContext& context,
      google::cloud::pubsublite::v1::UpdateSubscriptionRequest const& request)
      override;

  Status DeleteSubscription(
      grpc::ClientContext& context,
      google::cloud::pubsublite::v1::DeleteSubscriptionRequest const& request)
      override;

  future<StatusOr<google::longrunning::Operation>> AsyncSeekSubscription(
      google::cloud::CompletionQueue& cq,
      std::shared_ptr<grpc::ClientContext> context,
      google::cloud::pubsublite::v1::SeekSubscriptionRequest const& request)
      override;

  StatusOr<google::cloud::pubsublite::v1::Reservation> CreateReservation(
      grpc::ClientContext& context,
      google::cloud::pubsublite::v1::CreateReservationRequest const& request)
      override;

  StatusOr<google::cloud::pubsublite::v1::Reservation> GetReservation(
      grpc::ClientContext& context,
      google::cloud::pubsublite::v1::GetReservationRequest const& request)
      override;

  StatusOr<google::cloud::pubsublite::v1::ListReservationsResponse>
  ListReservations(grpc::ClientContext& context,
                   google::cloud::pubsublite::v1::ListReservationsRequest const&
                       request) override;

  StatusOr<google::cloud::pubsublite::v1::Reservation> UpdateReservation(
      grpc::ClientContext& context,
      google::cloud::pubsublite::v1::UpdateReservationRequest const& request)
      override;

  Status DeleteReservation(
      grpc::ClientContext& context,
      google::cloud::pubsublite::v1::DeleteReservationRequest const& request)
      override;

  StatusOr<google::cloud::pubsublite::v1::ListReservationTopicsResponse>
  ListReservationTopics(
      grpc::ClientContext& context,
      google::cloud::pubsublite::v1::ListReservationTopicsRequest const&
          request) override;

  future<StatusOr<google::cloud::pubsublite::v1::TopicPartitions>>
  AsyncGetTopicPartitions(
      google::cloud::CompletionQueue& cq,
      std::shared_ptr<grpc::ClientContext> context,
      google::cloud::pubsublite::v1::GetTopicPartitionsRequest const& request)
      override;

  future<StatusOr<google::longrunning::Operation>> AsyncGetOperation(
      google::cloud::CompletionQueue& cq,
      std::shared_ptr<grpc::ClientContext> context,
      google::longrunning::GetOperationRequest const& request) override;

  future<Status> AsyncCancelOperation(
      google::cloud::CompletionQueue& cq,
      std::shared_ptr<grpc::ClientContext> context,
      google::longrunning::CancelOperationRequest const& request) override;

 private:
  std::shared_ptr<AdminServiceStub> child_;
  TracingOptions tracing_options_;
  bool stream_logging_;
};  // AdminServiceLogging

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace pubsublite_internal
}  // namespace cloud
}  // namespace google

#endif  // GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_PUBSUBLITE_INTERNAL_ADMIN_LOGGING_DECORATOR_H
