/**
 * This file is part of the "FnordMetric" project
 *   Copyright (c) 2014 Paul Asmuth, Google Inc.
 *
 * FnordMetric is free software: you can redistribute it and/or modify it under
 * the terms of the GNU General Public License v3.0. You should have received a
 * copy of the GNU General Public License along with this program. If not, see
 * <http://www.gnu.org/licenses/>.
 */
#include <fnordmetric/sstable/cursor.h>

namespace fnord {
namespace sstable {

Cursor::Cursor() {}

std::string Cursor::getKey() {
  void* data;
  size_t size;
  getKey(&data, &size);
  return std::string((char *) data, size);
}

std::string Cursor::getData() {
  void* data;
  size_t size;
  getData(&data, &size);
  return std::string((char *) data, size);
}

}
}

