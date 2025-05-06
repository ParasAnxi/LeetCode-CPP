# Write your MySQL query statement below
SELECT Max(salary) AS SecondHighestSalary
FROM (SELECT salary, DENSE_RANK() 
OVER(ORDER BY salary DESC) 
AS salrank
FROM employee) 
AS emp
where salrank = 2;