IMPORT TABLE gdp_per_capita
   FROM CSV 'doc/examples/data/gdp_per_capita.csv' HEADER;

DRAW BARCHART WITH
    ORIENTATION VERTICAL
    AXIS LEFT
    AXIS BOTTOM
    LEGEND TOP RIGHT INSIDE;

SELECT year AS series, isocode AS x, gdp AS y
    FROM gdp_per_capita
    WHERE year = "2010" OR year = '2009' or year = '2008'
    LIMIT 20 OFFSET 40;

