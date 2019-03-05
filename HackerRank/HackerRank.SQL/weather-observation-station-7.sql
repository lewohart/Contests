-- https://www.hackerrank.com/challenges/weather-observation-station-7/
select distinct city from station where lower(substr(city, -1)) in ('a', 'e', 'i', 'o', 'u');