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
// source: google/cloud/compute/image_family_views/v1/image_family_views.proto

#include "google/cloud/compute/image_family_views/v1/image_family_views_connection_idempotency_policy.h"
#include <memory>

namespace google {
namespace cloud {
namespace compute_image_family_views_v1 {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

using ::google::cloud::Idempotency;

ImageFamilyViewsConnectionIdempotencyPolicy::
    ~ImageFamilyViewsConnectionIdempotencyPolicy() = default;

std::unique_ptr<ImageFamilyViewsConnectionIdempotencyPolicy>
ImageFamilyViewsConnectionIdempotencyPolicy::clone() const {
  return std::make_unique<ImageFamilyViewsConnectionIdempotencyPolicy>(*this);
}

Idempotency ImageFamilyViewsConnectionIdempotencyPolicy::GetImageFamilyViews(
    google::cloud::cpp::compute::image_family_views::v1::
        GetImageFamilyViewsRequest const&) {
  return Idempotency::kIdempotent;
}

std::unique_ptr<ImageFamilyViewsConnectionIdempotencyPolicy>
MakeDefaultImageFamilyViewsConnectionIdempotencyPolicy() {
  return std::make_unique<ImageFamilyViewsConnectionIdempotencyPolicy>();
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace compute_image_family_views_v1
}  // namespace cloud
}  // namespace google
