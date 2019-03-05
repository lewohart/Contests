-- https://www.hackerrank.com/challenges/weather-observation-station-5/submissions/database/13962013select * from (
    select * from(
        select city, length(city)
          from station
         order by length(city), city)
         where rownum = 1)
union all
select * from (
    select * from(
        select city, length(city)
          from station
         order by length(city)desc, city desc)
         where rownum = 1);