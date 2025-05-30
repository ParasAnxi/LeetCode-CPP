# Write your MySQL query statement below
WITH FirstLin AS (
    SELECT
        player_id,
        MIN(event_date) AS first_login
    FROM Activity
    GROUP BY player_id
),
ConsecutiveLogin AS (
    SELECT
        a.player_id
    FROM Activity a
    JOIN FirstLin fl
    ON a.player_id = fl.player_id
    AND a.event_date = DATE_ADD(fl.first_login, INTERVAL 1 DAY)
)
SELECT
    ROUND(
        COUNT(DISTINCT cl.player_id) * 1.0 / COUNT(DISTINCT fl.player_id),
        2
    ) AS fraction
FROM FirstLin fl
LEFT JOIN ConsecutiveLogin cl
ON fl.player_id = cl.player_id;