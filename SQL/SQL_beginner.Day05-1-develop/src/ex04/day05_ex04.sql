SET ENABLE_SEQSCAN = OFF;
CREATE UNIQUE INDEX idx_person_order_unique ON menu (pizzeria_id, pizza_name); --если ранее создавал, то закомментить
EXPLAIN ANALYZE --для вывода результата тоже закоментить
SELECT pizzeria_id, pizza_name
FROM menu
WHERE pizzeria_id=4 and pizza_name='pepperoni pizza';
