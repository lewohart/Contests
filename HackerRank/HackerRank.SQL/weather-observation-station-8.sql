-- https://www.hackerrank.com/challenges/weather-observation-station-8/
 select city
  from station
 where substr(lower(city), 1, 1) in ('a', 'e', 'i', 'o', 'u')
   and substr(lower(city), -1)   in ('a', 'e', 'i', 'o', 'u')
order by 1 desc;