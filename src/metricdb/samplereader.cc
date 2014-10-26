/**
 * This file is part of the "FnordMetric" project
 *   Copyright (c) 2014 Paul Asmuth, Google Inc.
 *
 * FnordMetric is free software: you can redistribute it and/or modify it under
 * the terms of the GNU General Public License v3.0. You should have received a
 * copy of the GNU General Public License along with this program. If not, see
 * <http://www.gnu.org/licenses/>.
 */
#include <fnordmetric/metricdb/tokenindex.h>
#include <fnordmetric/metricdb/samplereader.h>
#include <fnordmetric/util/ieee754.h>

namespace fnordmetric {
namespace metricdb {

AbstractSampleReader::AbstractSampleReader(
    void* data,
    size_t size,
    TokenIndex* token_index) :
    fnord::util::BinaryMessageReader(data, size),
    token_index_(token_index),
    labels_read_(false) {}

const std::vector<std::pair<std::string, std::string>>&
    AbstractSampleReader::labels() {
  if (!labels_read_) {
    labels_read_ = true;

    while (pos_ < size_) {
      auto key = readToken();
      auto value = readToken();
      labels_.emplace_back(key, value);
    }
  }

  return labels_;
}

const std::vector<std::pair<uint32_t, std::string>>&
    AbstractSampleReader::tokenDefinitions() {
  labels();
  return token_definitions_;
}

std::string AbstractSampleReader::readToken() {
  auto token_ref = *readUInt32();
  uint32_t string_len;
  uint32_t token_def = 0;

  if (token_ref == 0xffffffff) {
    token_def = *readUInt32();
    string_len = *readUInt32();
  } else if (token_ref >= TokenIndex::kMinTokenID) {
    return token_index_->resolveToken(token_ref);
  } else {
    string_len = token_ref;
  }

  auto token = std::string(readString(string_len), string_len);

  if (token_def > 0) {
    token_definitions_.emplace_back(token_def, token);
  }

  return token;
}

template <> double SampleReader<double>::readValue() {
  return fnord::util::IEEE754::fromBytes(*readUInt64());
}

}
}

