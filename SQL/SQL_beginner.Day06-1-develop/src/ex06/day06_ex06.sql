-- Проверяем существование последовательности и создаём её, если её нет
CREATE SEQUENCE IF NOT EXISTS seq_person_discounts START WITH 1;
 
-- Устанавливаем начальное значение последовательности равным MAX(id) + 1 из таблицы person_discounts
SELECT SETVAL('seq_person_discounts', COALESCE((SELECT MAX(id) FROM person_discounts), 0) + 1);
 
-- Устанавливаем значение по умолчанию для столбца id как NEXTVAL('seq_person_discounts')
ALTER TABLE person_discounts ALTER COLUMN id SET DEFAULT NEXTVAL('seq_person_discounts');
