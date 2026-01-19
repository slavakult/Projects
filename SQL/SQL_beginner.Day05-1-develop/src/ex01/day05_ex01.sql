SET ENABLE_SEQSCAN = OFF; -- при комментировании можно посмотреть, что без запроса время выполнения больше
EXPLAIN ANALYZE -- в зависимости от необходимости снимается коммент и проверяется запрос
SELECT pizza_name, pizzeria.name AS pizzeria_name
FROM menu
JOIN pizzeria ON menu.pizzeria_id = pizzeria.id;
