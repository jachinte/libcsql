/**
 * This file is part of the "FnordMetric" project
 *   Copyright (c) 2014 Paul Asmuth, Google Inc.
 *
 * Licensed under the MIT license (see LICENSE).
 */
#ifndef _FNORDMETRIC_FILEBACKEND_STREAMREF_H
#define _FNORDMETRIC_FILEBACKEND_STREAMREF_H

#include <stdlib.h>
#include <stdint.h>
#include <string>
#include <memory>
#include <atomic>
#include <mutex>
#include "pagemanager.h"
#include "../record.h"

namespace fnordmetric {
namespace database {

class Database;
class Cursor;

struct PageAlloc {
  PageAlloc(
      const PageManager::Page& page,
      uint64_t time,
      uint64_t logical_offset);
  const PageManager::Page page_;
  std::atomic_size_t used_; /* number of used bytes in the page */
  std::atomic_size_t num_rows_; /* number of rows in the page */
  const uint64_t time_; /* time of the first row in the page */
  const uint64_t logical_offset_; /* logical offset of the page */
};

struct StreamPosition {
  uint64_t unix_millis;
  uint64_t logical_offset;
  uint64_t next_offset;
  bool operator==(const StreamPosition& other);
};

struct __attribute__((__packed__)) RowHeader {
  uint32_t checksum;
  uint32_t size;
  uint64_t time;
  uint8_t data[];
  uint32_t computeChecksum();
};

/**
 * A stream descriptor is a handle to a single stream. It can be used to
 * append rows to the stream and to receive a cursor for reading from the
 * stream.
 *
 * The appendRow and getCursor methods on the descriptor are threadsafe.
 */
class StreamRef {
  friend class DatabaseTest;
  friend class Cursor;
public:
  explicit StreamRef(
      Database* backed,
      uint64_t stream_id,
      const std::string& stream_key);

  explicit StreamRef(
      Database* backed,
      uint64_t stream_id,
      const std::string& stream_key,
      std::vector<std::shared_ptr<PageAlloc>>&& pages);

  StreamRef(const StreamRef& copy) = delete;
  StreamRef& operator=(const StreamRef& copy) = delete;

  /**
   * Append a new row to the very end of the opened stream. Returns the UTC
   * millisecond timestamp at which the row was inserted.
   *
   * This method is threadsafe.
   */
  StreamPosition appendRow(const RecordWriter& row);

  /**
   * Append a new row to the very end of the opened stream with an explicit
   * insert time. This should only be used for importing data as the insert
   * time must be monotonically increasing.
   *
   * This method is threadsafe but you need to make sure that insert_time is
   * monotonically increasing.
   */
  StreamPosition appendRow(const RecordWriter& row, uint64_t insert_time);

  /**
   * Return a cursor to this stream for reading. The initial position of the
   * cursor is undefined.
   *
   * This is threadsafe
   */
  std::unique_ptr<Cursor> getCursor();

protected:

  /**
   * Access the StreamRefs internal page storage (do not call this method unless
   * you know what you are doing)
   */
  void accessPages(std::function<void(
      const std::vector<std::shared_ptr<PageAlloc>>&)> func);

  StreamPosition appendRow(const void* data, size_t size, uint64_t time);
  uint64_t estimatePageSize(size_t last_page_avg_size, size_t row_size) const;

  // this is suboptimal as it will force us to do random memory accesses when
  // trying to binary search over the pages first row times
  std::vector<std::shared_ptr<PageAlloc>> pages_;
  std::atomic_size_t num_pages_;
  std::mutex pages_mutex_;
  std::mutex append_mutex_;

  Database* backend_;
  const uint64_t stream_id_;
  const std::string stream_key_;
};

}
}
#endif
