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
// source: google/cloud/automl/v1/prediction_service.proto

#ifndef GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_AUTOML_PREDICTION_CLIENT_H
#define GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_AUTOML_PREDICTION_CLIENT_H

#include "google/cloud/automl/prediction_connection.h"
#include "google/cloud/future.h"
#include "google/cloud/options.h"
#include "google/cloud/polling_policy.h"
#include "google/cloud/status_or.h"
#include "google/cloud/version.h"
#include <google/longrunning/operations.grpc.pb.h>
#include <map>
#include <memory>

namespace google {
namespace cloud {
namespace automl {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

///
/// AutoML Prediction API.
///
/// On any input that is documented to expect a string parameter in
/// snake_case or dash-case, either of those cases is accepted.
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
class PredictionServiceClient {
 public:
  explicit PredictionServiceClient(
      std::shared_ptr<PredictionServiceConnection> connection,
      Options opts = {});
  ~PredictionServiceClient();

  ///@{
  /// @name Copy and move support
  PredictionServiceClient(PredictionServiceClient const&) = default;
  PredictionServiceClient& operator=(PredictionServiceClient const&) = default;
  PredictionServiceClient(PredictionServiceClient&&) = default;
  PredictionServiceClient& operator=(PredictionServiceClient&&) = default;
  ///@}

  ///@{
  /// @name Equality
  friend bool operator==(PredictionServiceClient const& a,
                         PredictionServiceClient const& b) {
    return a.connection_ == b.connection_;
  }
  friend bool operator!=(PredictionServiceClient const& a,
                         PredictionServiceClient const& b) {
    return !(a == b);
  }
  ///@}

  ///
  /// Perform an online prediction. The prediction result is directly
  /// returned in the response.
  /// Available for following ML scenarios, and their expected request payloads:
  ///
  /// AutoML Vision Classification
  ///
  /// * An image in .JPEG, .GIF or .PNG format, image_bytes up to 30MB.
  ///
  /// AutoML Vision Object Detection
  ///
  /// * An image in .JPEG, .GIF or .PNG format, image_bytes up to 30MB.
  ///
  /// AutoML Natural Language Classification
  ///
  /// * A TextSnippet up to 60,000 characters, UTF-8 encoded or a document in
  /// .PDF, .TIF or .TIFF format with size upto 2MB.
  ///
  /// AutoML Natural Language Entity Extraction
  ///
  /// * A TextSnippet up to 10,000 characters, UTF-8 NFC encoded or a document
  ///  in .PDF, .TIF or .TIFF format with size upto 20MB.
  ///
  /// AutoML Natural Language Sentiment Analysis
  ///
  /// * A TextSnippet up to 60,000 characters, UTF-8 encoded or a document in
  /// .PDF, .TIF or .TIFF format with size upto 2MB.
  ///
  /// AutoML Translation
  ///
  /// * A TextSnippet up to 25,000 characters, UTF-8 encoded.
  ///
  /// AutoML Tables
  ///
  /// * A row with column values matching
  ///   the columns of the model, up to 5MB. Not available for FORECASTING
  ///   `prediction_type`.
  ///
  /// @param name  Required. Name of the model requested to serve the
  /// prediction.
  /// @param payload  Required. Payload to perform a prediction on. The payload
  /// must match the
  ///  problem type that the model was trained to solve.
  /// @param params  Additional domain-specific parameters, any string must be
  /// up to 25000
  ///  characters long.
  ///  AutoML Vision Classification
  ///  `score_threshold`
  ///  : (float) A value from 0.0 to 1.0. When the model
  ///    makes predictions for an image, it will only produce results that have
  ///    at least this confidence score. The default is 0.5.
  ///  AutoML Vision Object Detection
  ///  `score_threshold`
  ///  : (float) When Model detects objects on the image,
  ///    it will only produce bounding boxes which have at least this
  ///    confidence score. Value in 0 to 1 range, default is 0.5.
  ///  `max_bounding_box_count`
  ///  : (int64) The maximum number of bounding
  ///    boxes returned. The default is 100. The
  ///    number of returned bounding boxes might be limited by the server.
  ///  AutoML Tables
  ///  `feature_importance`
  ///  : (boolean) Whether
  ///  [feature_importance][google.cloud.automl.v1.TablesModelColumnInfo.feature_importance]
  ///    is populated in the returned list of
  ///    [TablesAnnotation][google.cloud.automl.v1.TablesAnnotation]
  ///    objects. The default is false.
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return
  /// @googleapis_link{google::cloud::automl::v1::PredictResponse,google/cloud/automl/v1/prediction_service.proto#L164}
  ///
  /// [google.cloud.automl.v1.PredictRequest]:
  /// @googleapis_reference_link{google/cloud/automl/v1/prediction_service.proto#L117}
  /// [google.cloud.automl.v1.PredictResponse]:
  /// @googleapis_reference_link{google/cloud/automl/v1/prediction_service.proto#L164}
  ///
  StatusOr<google::cloud::automl::v1::PredictResponse> Predict(
      std::string const& name,
      google::cloud::automl::v1::ExamplePayload const& payload,
      std::map<std::string, std::string> const& params, Options opts = {});

  ///
  /// Perform an online prediction. The prediction result is directly
  /// returned in the response.
  /// Available for following ML scenarios, and their expected request payloads:
  ///
  /// AutoML Vision Classification
  ///
  /// * An image in .JPEG, .GIF or .PNG format, image_bytes up to 30MB.
  ///
  /// AutoML Vision Object Detection
  ///
  /// * An image in .JPEG, .GIF or .PNG format, image_bytes up to 30MB.
  ///
  /// AutoML Natural Language Classification
  ///
  /// * A TextSnippet up to 60,000 characters, UTF-8 encoded or a document in
  /// .PDF, .TIF or .TIFF format with size upto 2MB.
  ///
  /// AutoML Natural Language Entity Extraction
  ///
  /// * A TextSnippet up to 10,000 characters, UTF-8 NFC encoded or a document
  ///  in .PDF, .TIF or .TIFF format with size upto 20MB.
  ///
  /// AutoML Natural Language Sentiment Analysis
  ///
  /// * A TextSnippet up to 60,000 characters, UTF-8 encoded or a document in
  /// .PDF, .TIF or .TIFF format with size upto 2MB.
  ///
  /// AutoML Translation
  ///
  /// * A TextSnippet up to 25,000 characters, UTF-8 encoded.
  ///
  /// AutoML Tables
  ///
  /// * A row with column values matching
  ///   the columns of the model, up to 5MB. Not available for FORECASTING
  ///   `prediction_type`.
  ///
  /// @param request
  /// @googleapis_link{google::cloud::automl::v1::PredictRequest,google/cloud/automl/v1/prediction_service.proto#L117}
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return
  /// @googleapis_link{google::cloud::automl::v1::PredictResponse,google/cloud/automl/v1/prediction_service.proto#L164}
  ///
  /// [google.cloud.automl.v1.PredictRequest]:
  /// @googleapis_reference_link{google/cloud/automl/v1/prediction_service.proto#L117}
  /// [google.cloud.automl.v1.PredictResponse]:
  /// @googleapis_reference_link{google/cloud/automl/v1/prediction_service.proto#L164}
  ///
  StatusOr<google::cloud::automl::v1::PredictResponse> Predict(
      google::cloud::automl::v1::PredictRequest const& request,
      Options opts = {});

  ///
  /// Perform a batch prediction. Unlike the online
  /// [Predict][google.cloud.automl.v1.PredictionService.Predict], batch
  /// prediction result won't be immediately available in the response. Instead,
  /// a long running operation object is returned. User can poll the operation
  /// result via [GetOperation][google.longrunning.Operations.GetOperation]
  /// method. Once the operation is done,
  /// [BatchPredictResult][google.cloud.automl.v1.BatchPredictResult] is
  /// returned in the [response][google.longrunning.Operation.response] field.
  /// Available for following ML scenarios:
  ///
  /// * AutoML Vision Classification
  /// * AutoML Vision Object Detection
  /// * AutoML Video Intelligence Classification
  /// * AutoML Video Intelligence Object Tracking * AutoML Natural Language
  /// Classification
  /// * AutoML Natural Language Entity Extraction
  /// * AutoML Natural Language Sentiment Analysis
  /// * AutoML Tables
  ///
  /// @param name  Required. Name of the model requested to serve the batch
  /// prediction.
  /// @param input_config  Required. The input configuration for batch
  /// prediction.
  /// @param output_config  Required. The Configuration specifying where output
  /// predictions should
  ///  be written.
  /// @param params  Additional domain-specific parameters for the predictions,
  /// any string must
  ///  be up to 25000 characters long.
  ///  AutoML Natural Language Classification
  ///  `score_threshold`
  ///  : (float) A value from 0.0 to 1.0. When the model
  ///    makes predictions for a text snippet, it will only produce results
  ///    that have at least this confidence score. The default is 0.5.
  ///
  ///  AutoML Vision Classification
  ///  `score_threshold`
  ///  : (float) A value from 0.0 to 1.0. When the model
  ///    makes predictions for an image, it will only produce results that
  ///    have at least this confidence score. The default is 0.5.
  ///  AutoML Vision Object Detection
  ///  `score_threshold`
  ///  : (float) When Model detects objects on the image,
  ///    it will only produce bounding boxes which have at least this
  ///    confidence score. Value in 0 to 1 range, default is 0.5.
  ///  `max_bounding_box_count`
  ///  : (int64) The maximum number of bounding
  ///    boxes returned per image. The default is 100, the
  ///    number of bounding boxes returned might be limited by the server.
  ///  AutoML Video Intelligence Classification
  ///  `score_threshold`
  ///  : (float) A value from 0.0 to 1.0. When the model
  ///    makes predictions for a video, it will only produce results that
  ///    have at least this confidence score. The default is 0.5.
  ///  `segment_classification`
  ///  : (boolean) Set to true to request
  ///    segment-level classification. AutoML Video Intelligence returns
  ///    labels and their confidence scores for the entire segment of the
  ///    video that user specified in the request configuration.
  ///    The default is true.
  ///  `shot_classification`
  ///  : (boolean) Set to true to request shot-level
  ///    classification. AutoML Video Intelligence determines the boundaries
  ///    for each camera shot in the entire segment of the video that user
  ///    specified in the request configuration. AutoML Video Intelligence
  ///    then returns labels and their confidence scores for each detected
  ///    shot, along with the start and end time of the shot.
  ///    The default is false.
  ///    WARNING: Model evaluation is not done for this classification type,
  ///    the quality of it depends on training data, but there are no metrics
  ///    provided to describe that quality.
  ///  `1s_interval_classification`
  ///  : (boolean) Set to true to request
  ///    classification for a video at one-second intervals. AutoML Video
  ///    Intelligence returns labels and their confidence scores for each
  ///    second of the entire segment of the video that user specified in the
  ///    request configuration. The default is false.
  ///    WARNING: Model evaluation is not done for this classification
  ///    type, the quality of it depends on training data, but there are no
  ///    metrics provided to describe that quality.
  ///  AutoML Video Intelligence Object Tracking
  ///  `score_threshold`
  ///  : (float) When Model detects objects on video frames,
  ///    it will only produce bounding boxes which have at least this
  ///    confidence score. Value in 0 to 1 range, default is 0.5.
  ///  `max_bounding_box_count`
  ///  : (int64) The maximum number of bounding
  ///    boxes returned per image. The default is 100, the
  ///    number of bounding boxes returned might be limited by the server.
  ///  `min_bounding_box_size`
  ///  : (float) Only bounding boxes with shortest edge
  ///    at least that long as a relative value of video frame size are
  ///    returned. Value in 0 to 1 range. Default is 0.
  ///
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return
  /// @googleapis_link{google::cloud::automl::v1::BatchPredictResult,google/cloud/automl/v1/prediction_service.proto#L308}
  ///
  /// [google.cloud.automl.v1.BatchPredictRequest]:
  /// @googleapis_reference_link{google/cloud/automl/v1/prediction_service.proto#L202}
  /// [google.cloud.automl.v1.BatchPredictResult]:
  /// @googleapis_reference_link{google/cloud/automl/v1/prediction_service.proto#L308}
  /// [google.cloud.automl.v1.PredictionService.Predict]:
  /// @googleapis_reference_link{google/cloud/automl/v1/prediction_service.proto#L80}
  /// [google.longrunning.Operation.response]:
  /// @googleapis_reference_link{google/longrunning/operations.proto#L160}
  /// [google.longrunning.Operations.GetOperation]:
  /// @googleapis_reference_link{google/longrunning/operations.proto#L77}
  ///
  future<StatusOr<google::cloud::automl::v1::BatchPredictResult>> BatchPredict(
      std::string const& name,
      google::cloud::automl::v1::BatchPredictInputConfig const& input_config,
      google::cloud::automl::v1::BatchPredictOutputConfig const& output_config,
      std::map<std::string, std::string> const& params, Options opts = {});

  ///
  /// Perform a batch prediction. Unlike the online
  /// [Predict][google.cloud.automl.v1.PredictionService.Predict], batch
  /// prediction result won't be immediately available in the response. Instead,
  /// a long running operation object is returned. User can poll the operation
  /// result via [GetOperation][google.longrunning.Operations.GetOperation]
  /// method. Once the operation is done,
  /// [BatchPredictResult][google.cloud.automl.v1.BatchPredictResult] is
  /// returned in the [response][google.longrunning.Operation.response] field.
  /// Available for following ML scenarios:
  ///
  /// * AutoML Vision Classification
  /// * AutoML Vision Object Detection
  /// * AutoML Video Intelligence Classification
  /// * AutoML Video Intelligence Object Tracking * AutoML Natural Language
  /// Classification
  /// * AutoML Natural Language Entity Extraction
  /// * AutoML Natural Language Sentiment Analysis
  /// * AutoML Tables
  ///
  /// @param request
  /// @googleapis_link{google::cloud::automl::v1::BatchPredictRequest,google/cloud/automl/v1/prediction_service.proto#L202}
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return
  /// @googleapis_link{google::cloud::automl::v1::BatchPredictResult,google/cloud/automl/v1/prediction_service.proto#L308}
  ///
  /// [google.cloud.automl.v1.BatchPredictRequest]:
  /// @googleapis_reference_link{google/cloud/automl/v1/prediction_service.proto#L202}
  /// [google.cloud.automl.v1.BatchPredictResult]:
  /// @googleapis_reference_link{google/cloud/automl/v1/prediction_service.proto#L308}
  /// [google.cloud.automl.v1.PredictionService.Predict]:
  /// @googleapis_reference_link{google/cloud/automl/v1/prediction_service.proto#L80}
  /// [google.longrunning.Operation.response]:
  /// @googleapis_reference_link{google/longrunning/operations.proto#L160}
  /// [google.longrunning.Operations.GetOperation]:
  /// @googleapis_reference_link{google/longrunning/operations.proto#L77}
  ///
  future<StatusOr<google::cloud::automl::v1::BatchPredictResult>> BatchPredict(
      google::cloud::automl::v1::BatchPredictRequest const& request,
      Options opts = {});

 private:
  std::shared_ptr<PredictionServiceConnection> connection_;
  Options options_;
};

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace automl
}  // namespace cloud
}  // namespace google

#endif  // GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_AUTOML_PREDICTION_CLIENT_H
