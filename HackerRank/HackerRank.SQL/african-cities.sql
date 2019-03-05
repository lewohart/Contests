-- https://www.hackerrank.com/challenges/african-cities/
select city.name
  from city inner join country on city.countrycode = country.code
 where continent = 'Africa';