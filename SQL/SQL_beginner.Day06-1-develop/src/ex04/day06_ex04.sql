--Добавление ограничения NOT NULL для столбца person_id
ALTER TABLE person_discounts
ADD CONSTRAINT ch_nn_person_id CHECK (person_id IS NOT NULL);
 
--Добавление ограничения NOT NULL для столбца pizzeria_id
ALTER TABLE person_discounts
ADD CONSTRAINT ch_nn_pizzeria_id CHECK (pizzeria_id IS NOT NULL);
 
-- Добавление ограничения NOT NULL для столбца discount
ALTER TABLE person_discounts
ADD CONSTRAINT ch_nn_discount CHECK (discount IS NOT NULL);
 
-- Установка значения по умолчанию 0 для столбца discount
ALTER TABLE person_discounts
ALTER COLUMN discount SET DEFAULT 0;
 
--Добавление ограничения на диапазон значений для столбца discount
ALTER TABLE person_discounts
ADD CONSTRAINT ch_range_discount CHECK (discount BETWEEN 0 AND 100);
