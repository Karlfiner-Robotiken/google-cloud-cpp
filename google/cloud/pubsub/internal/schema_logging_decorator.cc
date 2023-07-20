// Copyright 2023 Google LLC
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
// source: google/pubsub/v1/schema.proto

#include "google/cloud/pubsub/internal/schema_logging_decorator.h"
#include "google/cloud/internal/log_wrapper.h"
#include "google/cloud/status_or.h"
#include <google/pubsub/v1/schema.grpc.pb.h>
#include <memory>

namespace google {
namespace cloud {
namespace pubsub_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

SchemaServiceLogging::SchemaServiceLogging(
    std::shared_ptr<SchemaServiceStub> child, TracingOptions tracing_options,
    std::set<std::string> const& components)
    : child_(std::move(child)),
      tracing_options_(std::move(tracing_options)),
      stream_logging_(components.find("rpc-streams") != components.end()) {}

StatusOr<google::pubsub::v1::Schema> SchemaServiceLogging::CreateSchema(
    grpc::ClientContext& context,
    google::pubsub::v1::CreateSchemaRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](grpc::ClientContext& context,
             google::pubsub::v1::CreateSchemaRequest const& request) {
        return child_->CreateSchema(context, request);
      },
      context, request, __func__, tracing_options_);
}

StatusOr<google::pubsub::v1::Schema> SchemaServiceLogging::GetSchema(
    grpc::ClientContext& context,
    google::pubsub::v1::GetSchemaRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](grpc::ClientContext& context,
             google::pubsub::v1::GetSchemaRequest const& request) {
        return child_->GetSchema(context, request);
      },
      context, request, __func__, tracing_options_);
}

StatusOr<google::pubsub::v1::ListSchemasResponse>
SchemaServiceLogging::ListSchemas(
    grpc::ClientContext& context,
    google::pubsub::v1::ListSchemasRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](grpc::ClientContext& context,
             google::pubsub::v1::ListSchemasRequest const& request) {
        return child_->ListSchemas(context, request);
      },
      context, request, __func__, tracing_options_);
}

StatusOr<google::pubsub::v1::ListSchemaRevisionsResponse>
SchemaServiceLogging::ListSchemaRevisions(
    grpc::ClientContext& context,
    google::pubsub::v1::ListSchemaRevisionsRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](grpc::ClientContext& context,
             google::pubsub::v1::ListSchemaRevisionsRequest const& request) {
        return child_->ListSchemaRevisions(context, request);
      },
      context, request, __func__, tracing_options_);
}

StatusOr<google::pubsub::v1::Schema> SchemaServiceLogging::CommitSchema(
    grpc::ClientContext& context,
    google::pubsub::v1::CommitSchemaRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](grpc::ClientContext& context,
             google::pubsub::v1::CommitSchemaRequest const& request) {
        return child_->CommitSchema(context, request);
      },
      context, request, __func__, tracing_options_);
}

StatusOr<google::pubsub::v1::Schema> SchemaServiceLogging::RollbackSchema(
    grpc::ClientContext& context,
    google::pubsub::v1::RollbackSchemaRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](grpc::ClientContext& context,
             google::pubsub::v1::RollbackSchemaRequest const& request) {
        return child_->RollbackSchema(context, request);
      },
      context, request, __func__, tracing_options_);
}

StatusOr<google::pubsub::v1::Schema> SchemaServiceLogging::DeleteSchemaRevision(
    grpc::ClientContext& context,
    google::pubsub::v1::DeleteSchemaRevisionRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](grpc::ClientContext& context,
             google::pubsub::v1::DeleteSchemaRevisionRequest const& request) {
        return child_->DeleteSchemaRevision(context, request);
      },
      context, request, __func__, tracing_options_);
}

Status SchemaServiceLogging::DeleteSchema(
    grpc::ClientContext& context,
    google::pubsub::v1::DeleteSchemaRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](grpc::ClientContext& context,
             google::pubsub::v1::DeleteSchemaRequest const& request) {
        return child_->DeleteSchema(context, request);
      },
      context, request, __func__, tracing_options_);
}

StatusOr<google::pubsub::v1::ValidateSchemaResponse>
SchemaServiceLogging::ValidateSchema(
    grpc::ClientContext& context,
    google::pubsub::v1::ValidateSchemaRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](grpc::ClientContext& context,
             google::pubsub::v1::ValidateSchemaRequest const& request) {
        return child_->ValidateSchema(context, request);
      },
      context, request, __func__, tracing_options_);
}

StatusOr<google::pubsub::v1::ValidateMessageResponse>
SchemaServiceLogging::ValidateMessage(
    grpc::ClientContext& context,
    google::pubsub::v1::ValidateMessageRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](grpc::ClientContext& context,
             google::pubsub::v1::ValidateMessageRequest const& request) {
        return child_->ValidateMessage(context, request);
      },
      context, request, __func__, tracing_options_);
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace pubsub_internal
}  // namespace cloud
}  // namespace google
