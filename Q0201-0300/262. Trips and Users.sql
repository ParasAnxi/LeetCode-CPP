# Write your MySQL query statement below
SELECT request_at 
AS Day, ROUND(sum(status LIKE 'cancelled%')/count(*), 2) 
AS 'Cancellation Rate' 
FROM Trips 
WHERE (client_id,driver_id) IN 
(SELECT U1.users_id, U2.users_id 
FROM Users U1 
JOIN Users U2 
WHERE U1.banned = 'No' 
AND U2.banned = 'No')
AND request_at 
BETWEEN '2013-10-01' AND '2013-10-03'
GROUP BY request_at;