IMPORT TABLE gdp_per_country
   FROM CSV 'test/fixtures/gbp_per_country_simple.csv' HEADER;

DRAW BAR CHART;
DRAW BOTTOM AXIS;
DRAW LEFT AXIS;

SELECT
  'gross domestic product per country' AS series,
  country AS x,
  gdp AS y
FROM
  gdp_per_country
LIMIT 30;
