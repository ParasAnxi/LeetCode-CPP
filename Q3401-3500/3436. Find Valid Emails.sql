# Write your MySQL query statement below
select * from Users 
WHERE email REGEXP '^[a-zA-Z0-9_]*@[a-zA-Z]*\.com'
