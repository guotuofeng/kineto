/*
 * Copyright (c) Facebook, Inc. and its affiliates.
 * All rights reserved.
 * This source code is licensed under the BSD-style license found in the
 * LICENSE file in the root directory of this source tree.
 */

#include <fmt/format.h>

#include "GenericTraceActivity.h"
#include "output_base.h"

namespace libkineto {
void GenericTraceActivity::log(ActivityLogger& logger) const {
  logger.handleGenericActivity(*this);
}

void GenericTraceActivity::addMetadata(
    const std::string& key,
    const std::string& value) {
  metadata_.push_back(fmt::format("\"{}\": {}", key, value));
}

const std::string GenericTraceActivity::getMetadata() const {
  return fmt::format("{}", fmt::join(metadata_, ", "));
}
} // namespace libkineto
