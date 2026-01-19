-- Session 1
BEGIN; -- Начало транзакции
UPDATE pizzeria SET rating = 5 WHERE id = 1; -- Обновление строки с id = 1
--Здесь Session 2 обновляет строку с id = 2
UPDATE pizzeria SET rating = 4.9 WHERE id = 2; -- Попытка обновления строки с id = 2 (deadlock)
COMMIT;

--Session2
BEGIN;
UPDATE pizzeria SET rating = 4.8 WHERE id = 2; -- Обновление строки с id = 2
-- Здесь Session 1 обновляет строку с id = 1
UPDATE pizzeria SET rating = 4.7 WHERE id = 1; -- Попытка обновления строки с id = 1 (deadlock)
COMMIT; 
