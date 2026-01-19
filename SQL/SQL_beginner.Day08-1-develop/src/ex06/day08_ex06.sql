-- Session #1
BEGIN; -- Начало транзакции
SET TRANSACTION ISOLATION LEVEL REPEATABLE READ; -- Установка уровня изоляции
SELECT SUM(rating) FROM pizzeria; -- Первый запрос
--Session 2 обновляет рейтинг "Pizza Hut" до 5
SELECT SUM(rating) FROM pizzeria; -- Второй запрос
COMMIT; 

--Session #2
BEGIN; -- Начало транзакции
SET TRANSACTION ISOLATION LEVEL REPEATABLE READ; -- Установка уровня изоляции
UPDATE pizzeria SET rating = 5 WHERE name = 'Pizza Hut'; -- Обновление рейтинга
COMMIT; 
