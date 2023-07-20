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
// source: google/logging/v2/logging.proto

#include "google/cloud/logging/v2/internal/logging_service_v2_logging_decorator.h"
#include "google/cloud/internal/async_read_write_stream_logging.h"
#include "google/cloud/internal/log_wrapper.h"
#include "google/cloud/status_or.h"
#include <google/logging/v2/logging.grpc.pb.h>
#include <memory>

namespace google {
namespace cloud {
namespace logging_v2_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

LoggingServiceV2Logging::LoggingServiceV2Logging(
    std::shared_ptr<LoggingServiceV2Stub> child, TracingOptions tracing_options,
    std::set<std::string> const& components)
    : child_(std::move(child)),
      tracing_options_(std::move(tracing_options)),
      stream_logging_(components.find("rpc-streams") != components.end()) {}

Status LoggingServiceV2Logging::DeleteLog(
    grpc::ClientContext& context,
    google::logging::v2::DeleteLogRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](grpc::ClientContext& context,
             google::logging::v2::DeleteLogRequest const& request) {
        return child_->DeleteLog(context, request);
      },
      context, request, __func__, tracing_options_);
}

StatusOr<google::logging::v2::WriteLogEntriesResponse>
LoggingServiceV2Logging::WriteLogEntries(
    grpc::ClientContext& context,
    google::logging::v2::WriteLogEntriesRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](grpc::ClientContext& context,
             google::logging::v2::WriteLogEntriesRequest const& request) {
        return child_->WriteLogEntries(context, request);
      },
      context, request, __func__, tracing_options_);
}

StatusOr<google::logging::v2::ListLogEntriesResponse>
LoggingServiceV2Logging::ListLogEntries(
    grpc::ClientContext& context,
    google::logging::v2::ListLogEntriesRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](grpc::ClientContext& context,
             google::logging::v2::ListLogEntriesRequest const& request) {
        return child_->ListLogEntries(context, request);
      },
      context, request, __func__, tracing_options_);
}

StatusOr<google::logging::v2::ListMonitoredResourceDescriptorsResponse>
LoggingServiceV2Logging::ListMonitoredResourceDescriptors(
    grpc::ClientContext& context,
    google::logging::v2::ListMonitoredResourceDescriptorsRequest const&
        request) {
  return google::cloud::internal::LogWrapper(
      [this](grpc::ClientContext& context,
             google::logging::v2::ListMonitoredResourceDescriptorsRequest const&
                 request) {
        return child_->ListMonitoredResourceDescriptors(context, request);
      },
      context, request, __func__, tracing_options_);
}

StatusOr<google::logging::v2::ListLogsResponse>
LoggingServiceV2Logging::ListLogs(
    grpc::ClientContext& context,
    google::logging::v2::ListLogsRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](grpc::ClientContext& context,
             google::logging::v2::ListLogsRequest const& request) {
        return child_->ListLogs(context, request);
      },
      context, request, __func__, tracing_options_);
}

std::unique_ptr<::google::cloud::AsyncStreamingReadWriteRpc<
    google::logging::v2::TailLogEntriesRequest,
    google::logging::v2::TailLogEntriesResponse>>
LoggingServiceV2Logging::AsyncTailLogEntries(
    google::cloud::CompletionQueue const& cq,
    std::shared_ptr<grpc::ClientContext> context) {
  using LoggingStream =
      ::google::cloud::internal::AsyncStreamingReadWriteRpcLogging<
          google::logging::v2::TailLogEntriesRequest,
          google::logging::v2::TailLogEntriesResponse>;

  auto request_id = google::cloud::internal::RequestIdForLogging();
  GCP_LOG(DEBUG) << __func__ << "(" << request_id << ")";
  auto stream = child_->AsyncTailLogEntries(cq, std::move(context));
  if (stream_logging_) {
    stream = std::make_unique<LoggingStream>(
        std::move(stream), tracing_options_, std::move(request_id));
  }
  return stream;
}

future<StatusOr<google::logging::v2::WriteLogEntriesResponse>>
LoggingServiceV2Logging::AsyncWriteLogEntries(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::logging::v2::WriteLogEntriesRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](google::cloud::CompletionQueue& cq,
             std::shared_ptr<grpc::ClientContext> context,
             google::logging::v2::WriteLogEntriesRequest const& request) {
        return child_->AsyncWriteLogEntries(cq, std::move(context), request);
      },
      cq, std::move(context), request, __func__, tracing_options_);
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace logging_v2_internal
}  // namespace cloud
}  // namespace google
