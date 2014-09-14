IMPORT TABLE example_data
   FROM CSV 'doc/examples/data/point_example.csv' HEADER;

DRAW POINTCHART WITH
   AXIS BOTTOM
   AXIS LEFT
   AXIS TOP
   AXIS RIGHT
   YDOMAIN -40, 60
   LABELS;

SELECT series AS series, x AS x, y AS y, z as z, z as label
   FROM example_data;
