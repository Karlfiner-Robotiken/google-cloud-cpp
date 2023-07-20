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
// source: google/devtools/cloudtrace/v2/tracing.proto

#ifndef GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_TRACE_V2_INTERNAL_TRACE_LOGGING_DECORATOR_H
#define GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_TRACE_V2_INTERNAL_TRACE_LOGGING_DECORATOR_H

#include "google/cloud/trace/v2/internal/trace_stub.h"
#include "google/cloud/tracing_options.h"
#include "google/cloud/version.h"
#include <memory>
#include <set>
#include <string>

namespace google {
namespace cloud {
namespace trace_v2_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

class TraceServiceLogging : public TraceServiceStub {
 public:
  ~TraceServiceLogging() override = default;
  TraceServiceLogging(std::shared_ptr<TraceServiceStub> child,
                      TracingOptions tracing_options,
                      std::set<std::string> const& components);

  Status BatchWriteSpans(
      grpc::ClientContext& context,
      google::devtools::cloudtrace::v2::BatchWriteSpansRequest const& request)
      override;

  StatusOr<google::devtools::cloudtrace::v2::Span> CreateSpan(
      grpc::ClientContext& context,
      google::devtools::cloudtrace::v2::Span const& request) override;

 private:
  std::shared_ptr<TraceServiceStub> child_;
  TracingOptions tracing_options_;
  bool stream_logging_;
};  // TraceServiceLogging

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace trace_v2_internal
}  // namespace cloud
}  // namespace google

#endif  // GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_TRACE_V2_INTERNAL_TRACE_LOGGING_DECORATOR_H
