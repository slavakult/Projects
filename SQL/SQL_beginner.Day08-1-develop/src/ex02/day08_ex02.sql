-- Session # 1
BEGIN; -- Начало транзакции
SET TRANSACTION ISOLATION LEVEL REPEATABLE READ; 
SELECT * FROM pizzeria WHERE name = 'Pizza Hut';
UPDATE pizzeria SET rating = 4 WHERE name = 'Pizza Hut'; -- Обновление рейтинга
SELECT * FROM pizzeria WHERE name = 'Pizza Hut'; -- Проверка изменений
COMMIT; --  Завершение транзакции
 
-- Session #2
BEGIN; -- Начало транзакции
SET TRANSACTION ISOLATION LEVEL REPEATABLE READ; 
SELECT * FROM pizzeria WHERE name = 'Pizza Hut'; 
UPDATE pizzeria SET rating = 3.6 WHERE name = 'Pizza Hut'; -- Попытка обновления рейтинга
SELECT * FROM pizzeria WHERE name = 'Pizza Hut'; -- Проверка изменений
COMMIT; --Завершение транзакции
