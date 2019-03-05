-- https://www.hackerrank.com/challenges/weather-observation-station-18/
with points as (select min(lat_n)  a, max(lat_n)  c, min(long_w) b, max(long_w) d from station)
select round(abs(a - b) + abs(c - d), 4) from points;
