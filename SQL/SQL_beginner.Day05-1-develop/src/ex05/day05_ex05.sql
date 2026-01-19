SET ENABLE_SEQSCAN = OFF;
CREATE UNIQUE INDEX idx_person_order_order_date 
ON person_order (person_id, menu_id)
WHERE order_date = '2022-01-01';
EXPLAIN ANALYZE --для вывода результата тоже закоментить
SELECT person_id, menu_id
FROM person_order
where person_id=1 or person_id=2 and menu_id BETWEEN 1 and 8;
