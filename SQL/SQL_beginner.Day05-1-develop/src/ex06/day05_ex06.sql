SET enable_seqscan = OFF;
DROP INDEX IF EXISTS idx_1; -- удаление индекса, если он есть (при повторном запуске без этой команды будут ошибки)
-- Создание индекса
CREATE INDEX idx_1 ON pizzeria (rating);
 
-- Проверка производительности после создания индекса
EXPLAIN ANALYZE
SELECT
    m.pizza_name AS pizza_name,
    max(rating) OVER (PARTITION BY rating ORDER BY rating ROWS BETWEEN UNBOUNDED PRECEDING AND UNBOUNDED FOLLOWING) AS k
FROM  menu m
INNER JOIN pizzeria pz ON m.pizzeria_id = pz.id
ORDER BY 1,2;
