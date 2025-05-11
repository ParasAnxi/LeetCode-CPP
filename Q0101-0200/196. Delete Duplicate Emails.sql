# Write your MySQL query statement below
DELETE t1 FROM Person t1, Person t2
WHERE t1.email = t2.email
AND t1.id > t2.id