-- Session #1
BEGIN; -- Начало транзакции
SET TRANSACTION ISOLATION LEVEL READ COMMITTED; -- Установка уровня изоляции
SELECT * FROM pizzeria WHERE name = 'Pizza Hut';
-- Здесь Session #2 обновляет рейтинг до 3.6 - (after update input this)
SELECT * FROM pizzeria WHERE name = 'Pizza Hut'; -- Второй запрос (рейтинг 3.6)
COMMIT; -- Завершение транзакции

-- Session #2
BEGIN; -- Начало транзакции
SET TRANSACTION ISOLATION LEVEL READ COMMITTED; -- Установка уровня изоляции
UPDATE pizzeria SET rating = 3.6 WHERE name = 'Pizza Hut'; -- Обновление рейтинга
COMMIT; -- Завершение транзакции
