/**
 * This file is part of the "libfnord" project
 *   Copyright (c) 2015 Paul Asmuth
 *
 * FnordMetric is free software: you can redistribute it and/or modify it under
 * the terms of the GNU General Public License v3.0. You should have received a
 * copy of the GNU General Public License along with this program. If not, see
 * <http://www.gnu.org/licenses/>.
 */
#include <csql/qtree/UnionNode.h>

using namespace stx;

namespace csql {

UnionNode::UnionNode(const UnionNode& other) {
  for (const auto& tbl : other.tables_) {
    tables_.emplace_back(tbl->deepCopy());
  }

  for (auto& table : tables_) {
    addChild(&table);
  }
}

UnionNode::UnionNode(
    Vector<RefPtr<QueryTreeNode>> tables) :
    tables_(tables) {
  for (auto& table : tables_) {
    addChild(&table);
  }
}

Vector<RefPtr<QueryTreeNode>> UnionNode::inputTables() const {
  return tables_;
}

Vector<String> UnionNode::columnNames() const {
  if (tables_.empty()) {
    return Vector<String>{};
  } else {
    return tables_[0].asInstanceOf<TableExpressionNode>()->columnNames();
  }
}

RefPtr<QueryTreeNode> UnionNode::deepCopy() const {
  return new UnionNode(*this);
}

String UnionNode::toString() const {
  String str = "(union";

  for (const auto& tbl : tables_) {
    str += " (subexpr " + tbl->toString() + ")";
  }

  str += ")";
  return str;
}

} // namespace csql
