# Write your MySQL query statement below
SELECT id FROM(
    SELECT id, recordDate,temperature, 
    lag(temperature) OVER( ORDER BY recorddate) AS prev_day_temp, 
    lag(recorddate) OVER(ORDER BY recorddate) AS prev_date 
FROM weather
) AS e WHERE  
    temperature > prev_day_temp AND 
    DATEDIFF(recorddate, prev_date) = 1;