# Write your MySQL query statement below
SELECT e.name AS Employee
FROM employee e JOIN employee e1
ON e1.id=e.managerid
WHERE e.salary > e1.salary;