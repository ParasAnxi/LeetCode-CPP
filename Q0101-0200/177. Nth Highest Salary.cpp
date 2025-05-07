CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT BEGIN RETURN(
#Write your MySQL query statement below.
    SELECT salary FROM(SELECT salary,
                       rank() OVER(ORDER BY salary DESC)
                           AS ran FROM(SELECT DISTINCT salary FROM Employee)
                               AS check_1) AS check_2 WHERE ran = N);
END