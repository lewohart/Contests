-- https://www.hackerrank.com/challenges/weather-observation-station-19/
with points as (
select min(lat_n)  x, max(lat_n)  y,
       min(long_w) a, max(long_w) b
  from station)
select to_char(round(sqrt( ((x - a) * (x - a))  +  ((y - b) *(y - b)) ) , 4), '9999999999999.9999') from points;
