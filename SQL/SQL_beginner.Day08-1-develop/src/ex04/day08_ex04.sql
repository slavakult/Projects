-- Session #1
BEGIN; -- Начало транзакции
SET TRANSACTION ISOLATION LEVEL SERIALIZABLE; -- Установка уровня изоляции
SELECT * FROM pizzeria WHERE name = 'Pizza Hut';
-- Здесь Session #2 обновляет рейтинг до 3.0 (use after update)
SELECT * FROM pizzeria WHERE name = 'Pizza Hut'; 
COMMIT; -- Завершение транзакции

-- Session #2
BEGIN; -- Начало транзакции
SET TRANSACTION ISOLATION LEVEL SERIALIZABLE; -- Установка уровня изоляции
UPDATE pizzeria SET rating = 3.0 WHERE name = 'Pizza Hut'; -- Обновление рейтинга
COMMIT; -- Завершение транзакции
