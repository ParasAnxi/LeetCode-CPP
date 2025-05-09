# Write your MySQL query statement below
SELECT name 
AS Customers
FROM customers c 
LEFT JOIN orders o 
ON c.id = o.customerid
WHERE customerid IS NULL;