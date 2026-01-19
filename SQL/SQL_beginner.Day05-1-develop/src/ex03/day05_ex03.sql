SET ENABLE_SEQSCAN = OFF;
CREATE INDEX idx_person_order_multi ON person_order (person_id, menu_id, order_date); --если ранее создавал, то закомментить
EXPLAIN ANALYZE --для вывода результата тоже закоментить
SELECT person_id, menu_id,order_date
FROM person_order
WHERE person_id = 6 AND menu_id = 13;
