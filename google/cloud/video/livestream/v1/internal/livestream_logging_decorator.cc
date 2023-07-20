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
// source: google/cloud/video/livestream/v1/service.proto

#include "google/cloud/video/livestream/v1/internal/livestream_logging_decorator.h"
#include "google/cloud/internal/log_wrapper.h"
#include "google/cloud/status_or.h"
#include <google/cloud/video/livestream/v1/service.grpc.pb.h>
#include <memory>

namespace google {
namespace cloud {
namespace video_livestream_v1_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

LivestreamServiceLogging::LivestreamServiceLogging(
    std::shared_ptr<LivestreamServiceStub> child,
    TracingOptions tracing_options, std::set<std::string> const& components)
    : child_(std::move(child)),
      tracing_options_(std::move(tracing_options)),
      stream_logging_(components.find("rpc-streams") != components.end()) {}

future<StatusOr<google::longrunning::Operation>>
LivestreamServiceLogging::AsyncCreateChannel(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::video::livestream::v1::CreateChannelRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](google::cloud::CompletionQueue& cq,
             std::shared_ptr<grpc::ClientContext> context,
             google::cloud::video::livestream::v1::CreateChannelRequest const&
                 request) {
        return child_->AsyncCreateChannel(cq, std::move(context), request);
      },
      cq, std::move(context), request, __func__, tracing_options_);
}

StatusOr<google::cloud::video::livestream::v1::ListChannelsResponse>
LivestreamServiceLogging::ListChannels(
    grpc::ClientContext& context,
    google::cloud::video::livestream::v1::ListChannelsRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](grpc::ClientContext& context,
             google::cloud::video::livestream::v1::ListChannelsRequest const&
                 request) { return child_->ListChannels(context, request); },
      context, request, __func__, tracing_options_);
}

StatusOr<google::cloud::video::livestream::v1::Channel>
LivestreamServiceLogging::GetChannel(
    grpc::ClientContext& context,
    google::cloud::video::livestream::v1::GetChannelRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](grpc::ClientContext& context,
             google::cloud::video::livestream::v1::GetChannelRequest const&
                 request) { return child_->GetChannel(context, request); },
      context, request, __func__, tracing_options_);
}

future<StatusOr<google::longrunning::Operation>>
LivestreamServiceLogging::AsyncDeleteChannel(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::video::livestream::v1::DeleteChannelRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](google::cloud::CompletionQueue& cq,
             std::shared_ptr<grpc::ClientContext> context,
             google::cloud::video::livestream::v1::DeleteChannelRequest const&
                 request) {
        return child_->AsyncDeleteChannel(cq, std::move(context), request);
      },
      cq, std::move(context), request, __func__, tracing_options_);
}

future<StatusOr<google::longrunning::Operation>>
LivestreamServiceLogging::AsyncUpdateChannel(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::video::livestream::v1::UpdateChannelRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](google::cloud::CompletionQueue& cq,
             std::shared_ptr<grpc::ClientContext> context,
             google::cloud::video::livestream::v1::UpdateChannelRequest const&
                 request) {
        return child_->AsyncUpdateChannel(cq, std::move(context), request);
      },
      cq, std::move(context), request, __func__, tracing_options_);
}

future<StatusOr<google::longrunning::Operation>>
LivestreamServiceLogging::AsyncStartChannel(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::video::livestream::v1::StartChannelRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](google::cloud::CompletionQueue& cq,
             std::shared_ptr<grpc::ClientContext> context,
             google::cloud::video::livestream::v1::StartChannelRequest const&
                 request) {
        return child_->AsyncStartChannel(cq, std::move(context), request);
      },
      cq, std::move(context), request, __func__, tracing_options_);
}

future<StatusOr<google::longrunning::Operation>>
LivestreamServiceLogging::AsyncStopChannel(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::video::livestream::v1::StopChannelRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](google::cloud::CompletionQueue& cq,
             std::shared_ptr<grpc::ClientContext> context,
             google::cloud::video::livestream::v1::StopChannelRequest const&
                 request) {
        return child_->AsyncStopChannel(cq, std::move(context), request);
      },
      cq, std::move(context), request, __func__, tracing_options_);
}

future<StatusOr<google::longrunning::Operation>>
LivestreamServiceLogging::AsyncCreateInput(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::video::livestream::v1::CreateInputRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](google::cloud::CompletionQueue& cq,
             std::shared_ptr<grpc::ClientContext> context,
             google::cloud::video::livestream::v1::CreateInputRequest const&
                 request) {
        return child_->AsyncCreateInput(cq, std::move(context), request);
      },
      cq, std::move(context), request, __func__, tracing_options_);
}

StatusOr<google::cloud::video::livestream::v1::ListInputsResponse>
LivestreamServiceLogging::ListInputs(
    grpc::ClientContext& context,
    google::cloud::video::livestream::v1::ListInputsRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](grpc::ClientContext& context,
             google::cloud::video::livestream::v1::ListInputsRequest const&
                 request) { return child_->ListInputs(context, request); },
      context, request, __func__, tracing_options_);
}

StatusOr<google::cloud::video::livestream::v1::Input>
LivestreamServiceLogging::GetInput(
    grpc::ClientContext& context,
    google::cloud::video::livestream::v1::GetInputRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](grpc::ClientContext& context,
             google::cloud::video::livestream::v1::GetInputRequest const&
                 request) { return child_->GetInput(context, request); },
      context, request, __func__, tracing_options_);
}

future<StatusOr<google::longrunning::Operation>>
LivestreamServiceLogging::AsyncDeleteInput(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::video::livestream::v1::DeleteInputRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](google::cloud::CompletionQueue& cq,
             std::shared_ptr<grpc::ClientContext> context,
             google::cloud::video::livestream::v1::DeleteInputRequest const&
                 request) {
        return child_->AsyncDeleteInput(cq, std::move(context), request);
      },
      cq, std::move(context), request, __func__, tracing_options_);
}

future<StatusOr<google::longrunning::Operation>>
LivestreamServiceLogging::AsyncUpdateInput(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::video::livestream::v1::UpdateInputRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](google::cloud::CompletionQueue& cq,
             std::shared_ptr<grpc::ClientContext> context,
             google::cloud::video::livestream::v1::UpdateInputRequest const&
                 request) {
        return child_->AsyncUpdateInput(cq, std::move(context), request);
      },
      cq, std::move(context), request, __func__, tracing_options_);
}

StatusOr<google::cloud::video::livestream::v1::Event>
LivestreamServiceLogging::CreateEvent(
    grpc::ClientContext& context,
    google::cloud::video::livestream::v1::CreateEventRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](grpc::ClientContext& context,
             google::cloud::video::livestream::v1::CreateEventRequest const&
                 request) { return child_->CreateEvent(context, request); },
      context, request, __func__, tracing_options_);
}

StatusOr<google::cloud::video::livestream::v1::ListEventsResponse>
LivestreamServiceLogging::ListEvents(
    grpc::ClientContext& context,
    google::cloud::video::livestream::v1::ListEventsRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](grpc::ClientContext& context,
             google::cloud::video::livestream::v1::ListEventsRequest const&
                 request) { return child_->ListEvents(context, request); },
      context, request, __func__, tracing_options_);
}

StatusOr<google::cloud::video::livestream::v1::Event>
LivestreamServiceLogging::GetEvent(
    grpc::ClientContext& context,
    google::cloud::video::livestream::v1::GetEventRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](grpc::ClientContext& context,
             google::cloud::video::livestream::v1::GetEventRequest const&
                 request) { return child_->GetEvent(context, request); },
      context, request, __func__, tracing_options_);
}

Status LivestreamServiceLogging::DeleteEvent(
    grpc::ClientContext& context,
    google::cloud::video::livestream::v1::DeleteEventRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](grpc::ClientContext& context,
             google::cloud::video::livestream::v1::DeleteEventRequest const&
                 request) { return child_->DeleteEvent(context, request); },
      context, request, __func__, tracing_options_);
}

future<StatusOr<google::longrunning::Operation>>
LivestreamServiceLogging::AsyncGetOperation(
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

future<Status> LivestreamServiceLogging::AsyncCancelOperation(
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
}  // namespace video_livestream_v1_internal
}  // namespace cloud
}  // namespace google
