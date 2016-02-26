/**
 * This file is part of the "FnordMetric" project
 *   Copyright (c) 2014 Paul Asmuth, Google Inc.
 *
 * FnordMetric is free software: you can redistribute it and/or modify it under
 * the terms of the GNU General Public License v3.0. You should have received a
 * copy of the GNU General Public License along with this program. If not, see
 * <http://www.gnu.org/licenses/>.
 */
#pragma once
#include <stx/stdtypes.h>
#include <stx/SHA1.h>
#include <csql/tasks/Task.h>
#include <csql/runtime/defaultruntime.h>

namespace csql {

class GroupBy : public Task {
public:

  GroupBy(
      Transaction* txn,
      const Vector<String>& column_names,
      Vector<ValueExpression> select_expressions,
      Vector<ValueExpression> group_expressions,
      RowSinkFn output,
      SHA1Hash qtree_fingerprint);

  //void executeRemote(
  //    ExecutionContext* context,
  //    OutputStream* os);

  //void getResult(
  //    const HashMap<String, Vector<VM::Instance >>* groups,
  //    Function<bool (int argc, const SValue* argv)> fn);

  //void freeResult(
  //    HashMap<String, Vector<VM::Instance >>* groups);

  //void mergeResult(
  //    const HashMap<String, Vector<VM::Instance >>* src,
  //    HashMap<String, Vector<VM::Instance >>* dst,
  //    ScratchMemory* scratch);

  Vector<String> columnNames() const override;

  size_t numColumns() const override;

protected:

  bool nextRow(
      HashMap<String, Vector<VM::Instance >>* groups,
      ScratchMemory* scratch,
      int argc,
      const SValue* argv);

  Transaction* txn_;
  Vector<String> column_names_;
  Vector<ValueExpression> select_exprs_;
  Vector<ValueExpression> group_exprs_;
  RowSinkFn output_;
  SHA1Hash qtree_fingerprint_;
};

//class RemoteGroupBy : public GroupByExpression {
//public:
//  typedef
//      Function<ScopedPtr<InputStream> (const RemoteAggregateParams& params)>
//      RemoteExecuteFn;
//
//  RemoteGroupBy(
//      Transaction* txn,
//      const Vector<String>& column_names,
//      Vector<ValueExpression> select_expressions,
//      const RemoteAggregateParams& params,
//      RemoteExecuteFn execute_fn);
//
//  void accumulate(
//      HashMap<String, Vector<VM::Instance >>* groups,
//      ScratchMemory* scratch,
//      ExecutionContext* context) override;
//
//protected:
//  RemoteAggregateParams params_;
//  RemoteExecuteFn execute_fn_;
//};
//
//class GroupByMerge : public Task {
//public:
//
//  GroupByMerge(Vector<ScopedPtr<GroupByExpression>> sources);
//
//  Vector<String> columnNames() const override;
//
//  size_t numColumns() const override;
//
//protected:
//  Vector<ScopedPtr<GroupByExpression>> sources_;
//};

}
