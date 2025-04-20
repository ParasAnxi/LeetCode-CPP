/* Write your T-SQL query statement below */
SELECT product_id, product_name, description
FROM products
WHERE description LIKE '%SN____-____' or description like '%SN____-____ %'
