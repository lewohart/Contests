-- https://www.hackerrank.com/challenges/weather-observation-station-17/
select round(long_w, 4)
  from station
 where rownum = 1
   and lat_n in (
    select min(lat_n)
      from station
     where lat_n > 38.7780);