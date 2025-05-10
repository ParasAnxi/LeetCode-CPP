# Write your MySQL query statement below
SELECT d.name AS Department , e1.name AS Employee ,e1.salary AS Salary 
FROM Employee e1
INNER JOIN Department d
ON e1.departmentID = d.id
WHERE 3> (
    SELECT count(DISTINCT(e2.salary))
    FROM Employee e2
    WHERE e2.Salary > e1.Salary AND
    e1.DepartmentID = e2.DepartmentID
)