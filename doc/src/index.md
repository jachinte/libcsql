FnordMetric v1.2.8 Documentation
--------------------------------

FnordMetric is a framework for collecting and visualizing timeseries data. It enables
you to build beautiful real-time analytics dashboards within minutes.

### FnordMetric UI

FnordMetric UI is a HTML5 / JavaScript API that lets you plug real-time data and charts into any
webpage without writing a single line of code. It gives you maximum flexiblitiy as you have full
control over layout and style with HTML and CSS.

FnordMetric UI uses WebSockets to communicate with a backend server. There are two backend
implementations: FnordMetric Classic (ruby + redis) and FnordMetric Enterprise (JVM).

You can use FnordMetric UI as a white label solution to power your custom real-time analytics apps.

<a href="/documentation/ui_index">Getting Started with FnordMetric UI &rarr;</a>
<br /><br />


### FnordMetric Enterprise

FnordMetric Enterprise is a JVM based timeseries database which serves as a backend for FnordMetric
UI. It can handle thousands of gauges and years worth of historical data. FnordMetric Enterprise runs
stand-alone, i.e. it does not depend on a backend store like redis.

FnordMetric Enterprise features disk persistence, a HTTP, TCP and UDP API, native WebSockets support
and CSV/JSON Export. FnordMetric Enterprise can be used as a drop-in replacement for StatsD+Graphite
(it is a lot faster, see Benchmarks).

<a href="/documentation/enterprise_index">Getting Started with FnordMetric Enterprise &rarr;</a>
<br /><br />


### FnordMetric Classic

FnordMetric Classic is powered by ruby and redis. It offers a ruby DSL for processing data
streams and building beautiful web dashboards from a collection of pre-made UI widgets.

You can also use the FnordMetric UI HTML5 API to display the data collected with FnordMetric
Classic on another website or build highly customized / white label views.

<a href="/documentation/classic_index">Getting Started with FnordMetric Classic &rarr;</a>

