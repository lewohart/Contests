-- https://www.hackerrank.com/challenges/weather-observation-station-10/
select distinct city
  from station
 where substr(lower(city), -1) not  in ('a', 'e', 'i', 'o', 'u')
order by 1 asc;