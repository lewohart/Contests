-- https://www.hackerrank.com/challenges/weather-observation-station-20/
select str((
    (select max(lat_n) from (select top 50 percent lat_n from station order by lat_n asc) as t) + 
    (select min(lat_n) from (select top 50 percent lat_n from station order by lat_n desc) as b)
    ) / 2.0, 10, 4);