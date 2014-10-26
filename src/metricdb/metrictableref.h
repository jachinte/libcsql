/**
 * This file is part of the "FnordMetric" project
 *   Copyright (c) 2011-2014 Paul Asmuth, Google Inc.
 *
 * FnordMetric is free software: you can redistribute it and/or modify it under
 * the terms of the GNU General Public License v3.0. You should have received a
 * copy of the GNU General Public License along with this program. If not, see
 * <http://www.gnu.org/licenses/>.
 */
#ifndef _FNORDMETRIC_METRICDB_METRICTABLEREF_H
#define _FNORDMETRIC_METRICDB_METRICTABLEREF_H
#include <fnordmetric/metricdb/metric.h>
#include <fnordmetric/sql/backends/tableref.h>
#include <stdlib.h>
#include <string>
#include <memory>

namespace fnordmetric {
namespace query {
class TableScan;
}

namespace metricdb {

class MetricTableRef : public query::TableRef {
public:
  MetricTableRef(Metric* metric);

  int getColumnIndex(const std::string& name) override;
  void executeScan(query::TableScan* scan) override;

protected:
  Metric* metric_;
  std::vector<std::string> fields_;
};

}
}
#endif
