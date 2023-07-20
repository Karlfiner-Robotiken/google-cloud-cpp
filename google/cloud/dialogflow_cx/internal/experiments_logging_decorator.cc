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
// source: google/cloud/dialogflow/cx/v3/experiment.proto

#include "google/cloud/dialogflow_cx/internal/experiments_logging_decorator.h"
#include "google/cloud/internal/log_wrapper.h"
#include "google/cloud/status_or.h"
#include <google/cloud/dialogflow/cx/v3/experiment.grpc.pb.h>
#include <memory>

namespace google {
namespace cloud {
namespace dialogflow_cx_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

ExperimentsLogging::ExperimentsLogging(std::shared_ptr<ExperimentsStub> child,
                                       TracingOptions tracing_options,
                                       std::set<std::string> const& components)
    : child_(std::move(child)),
      tracing_options_(std::move(tracing_options)),
      stream_logging_(components.find("rpc-streams") != components.end()) {}

StatusOr<google::cloud::dialogflow::cx::v3::ListExperimentsResponse>
ExperimentsLogging::ListExperiments(
    grpc::ClientContext& context,
    google::cloud::dialogflow::cx::v3::ListExperimentsRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](grpc::ClientContext& context,
             google::cloud::dialogflow::cx::v3::ListExperimentsRequest const&
                 request) { return child_->ListExperiments(context, request); },
      context, request, __func__, tracing_options_);
}

StatusOr<google::cloud::dialogflow::cx::v3::Experiment>
ExperimentsLogging::GetExperiment(
    grpc::ClientContext& context,
    google::cloud::dialogflow::cx::v3::GetExperimentRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](grpc::ClientContext& context,
             google::cloud::dialogflow::cx::v3::GetExperimentRequest const&
                 request) { return child_->GetExperiment(context, request); },
      context, request, __func__, tracing_options_);
}

StatusOr<google::cloud::dialogflow::cx::v3::Experiment>
ExperimentsLogging::CreateExperiment(
    grpc::ClientContext& context,
    google::cloud::dialogflow::cx::v3::CreateExperimentRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](grpc::ClientContext& context,
             google::cloud::dialogflow::cx::v3::CreateExperimentRequest const&
                 request) {
        return child_->CreateExperiment(context, request);
      },
      context, request, __func__, tracing_options_);
}

StatusOr<google::cloud::dialogflow::cx::v3::Experiment>
ExperimentsLogging::UpdateExperiment(
    grpc::ClientContext& context,
    google::cloud::dialogflow::cx::v3::UpdateExperimentRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](grpc::ClientContext& context,
             google::cloud::dialogflow::cx::v3::UpdateExperimentRequest const&
                 request) {
        return child_->UpdateExperiment(context, request);
      },
      context, request, __func__, tracing_options_);
}

Status ExperimentsLogging::DeleteExperiment(
    grpc::ClientContext& context,
    google::cloud::dialogflow::cx::v3::DeleteExperimentRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](grpc::ClientContext& context,
             google::cloud::dialogflow::cx::v3::DeleteExperimentRequest const&
                 request) {
        return child_->DeleteExperiment(context, request);
      },
      context, request, __func__, tracing_options_);
}

StatusOr<google::cloud::dialogflow::cx::v3::Experiment>
ExperimentsLogging::StartExperiment(
    grpc::ClientContext& context,
    google::cloud::dialogflow::cx::v3::StartExperimentRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](grpc::ClientContext& context,
             google::cloud::dialogflow::cx::v3::StartExperimentRequest const&
                 request) { return child_->StartExperiment(context, request); },
      context, request, __func__, tracing_options_);
}

StatusOr<google::cloud::dialogflow::cx::v3::Experiment>
ExperimentsLogging::StopExperiment(
    grpc::ClientContext& context,
    google::cloud::dialogflow::cx::v3::StopExperimentRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](grpc::ClientContext& context,
             google::cloud::dialogflow::cx::v3::StopExperimentRequest const&
                 request) { return child_->StopExperiment(context, request); },
      context, request, __func__, tracing_options_);
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace dialogflow_cx_internal
}  // namespace cloud
}  // namespace google
