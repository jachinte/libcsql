/**
 * This file is part of the "FnordMetric" project
 *   Copyright (c) 2014 Paul Asmuth, Google Inc.
 *
 * Licensed under the MIT license (see LICENSE).
 */
#ifndef _FNORDMETRIC_STYLE_DEFAULT_H
#define _FNORDMETRIC_STYLE_DEFAULT_H
#include <stdlib.h>
#include <string.h>

namespace fnordmetric {

static const std::string kStyleSheetDefault = R"(
  .chart text {
    font-family: "Helvetica Neue", Helvetica, Arial, "Lucida Grande", sans-serif;
    font: 10pt sans-serif;
  }

  .axis .stroke {
    stroke: rgb(0,0,0);
    stroke-width: 1px;
  }

  .axis .tick {
    stroke: rgb(0,0,0);
    stroke-width: 1px;
  }

  .axis .label, .axis .title {
    fill: #000;
  }

  .axis .label {
    font-size: 9pt;
  }

  .axis .title {
    font-size: 11pt;
  }

  .chart .line {
    fill: none;
    stroke: #000;
  }

  .chart .area {
    opacity: 0.8;
  }

  .chart .bar,
  .chart .point,
  .chart .area {
    fill: #000;
  }

  .chart .bar.color6,
  .chart .point.color6,
  .chart .area.color6 {
    fill: #db843d;
  }

  .chart .lines .line.color6 {
    strok: #db843d;
  }

  .chart .bar.color5,
  .chart .point.color5,
  .chart .area.color5 {
    fill: #3d96ae;
  }

  .chart .lines .line.color5 {
    stroke: #3d96ae;
  }

  .chart .bar.color4,
  .chart .point.color4,
  .chart .area.color4 {
    fill: #80699b;
  }

  .chart .line.color4 {
    stroke: #80699b;
  }

  .chart .bar.color3,
  .chart .point.color3,
  .chart .area.color3 {
    fill: #89a54e;
  }

  .chart .line.color3 {
    stroke: #89a54e;
  }

  .chart .bar.color2,
  .chart .point.color2,
  .chart .area.color2 {
    fill: #aa4643;
  }

  .chart .line.color2 {
    stroke: #aa4643;
  }

  .chart .bar.color1,
  .chart .point.color1,
  .chart .area.color1 {
    fill: #4572a7;
  }

  .chart .line.color1 {
    stroke: #4572a7;
  }

  .chart.bar.vertical .axis.left .stroke,
  .chart.bar.vertical .axis.left .tick,
  .chart.bar.vertical .axis.right .stroke,
  .chart.bar.vertical .axis.right .tick {
    display: none;
  }
)";

}
#endif
