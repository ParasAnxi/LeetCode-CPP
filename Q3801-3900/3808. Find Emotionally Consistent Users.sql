# Write your MySQL query statement below
WITH cte AS (
    SELECT *, count(*) AS cnt
    FROM reactions
    GROUP BY user_id
)
SELECT r.user_id, r.reaction AS dominant_reaction,
round(count(*) / cnt, 2) AS reaction_ratio
FROM reactions r
JOIN cte c
ON r.user_id = c.user_id
WHERE cnt >= 5
GROUP BY r.user_id, r.reaction
HAVING reaction_ratio >= 0.60
ORDER BY reaction_ratio DESC, user_id;
