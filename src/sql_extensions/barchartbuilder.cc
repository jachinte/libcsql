/**
 * This file is part of the "FnordMetric" project
 *   Copyright (c) 2011-2014 Paul Asmuth, Google Inc.
 *
 * FnordMetric is free software: you can redistribute it and/or modify it under
 * the terms of the GNU General Public License v3.0. You should have received a
 * copy of the GNU General Public License along with this program. If not, see
 * <http://www.gnu.org/licenses/>.
 */
#include <fnordmetric/sql_extensions/barchartbuilder.h>
#include <fnordmetric/sql_extensions/drawstatement.h>
#include <fnordmetric/ui/barchart.h>

namespace fnordmetric {
namespace query {

BarChartBuilder::BarChartBuilder(
    ui::Canvas* canvas,
    DrawStatement const* draw_stmt) :
    ChartBuilder(canvas, draw_stmt) {}

ui::Drawable* BarChartBuilder::getChart() const {
  auto chart = dynamic_cast<ui::BarChart*>(findChartType());
  setOrientation(chart);
  return chart;
}

ui::Drawable* BarChartBuilder::findChartType() const {
  if (auto c = tryType2D<ui::BarChart2D<std::string, int>>())
    return c;

  if (auto c = tryType2D<ui::BarChart2D<std::string, double>>())
    return c;

  if (auto c = tryType3D<ui::BarChart3D<std::string, int, int>>())
    return c;

  if (auto c = tryType3D<ui::BarChart3D<std::string, double, double>>())
    return c;

  invalidType();
  return nullptr;
}

void BarChartBuilder::setOrientation(ui::BarChart* chart) const {
  auto prop = draw_stmt_->getProperty(Token::T_ORIENTATION);

  if (prop == nullptr) {
    return;
  }

  chart->setOrientation(ui::BarChart::O_HORIZONTAL);
}

}
}
