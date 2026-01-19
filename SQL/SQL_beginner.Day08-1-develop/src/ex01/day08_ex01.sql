-- Session #1
BEGIN;

-- Проверяем начальное значение рейтинга
SELECT * FROM pizzeria WHERE name = 'Pizza Hut';

-- Обновляем рейтинг до 4
UPDATE pizzeria SET rating = 4 WHERE name = 'Pizza Hut';

-- Ждём, пока Session #2 выполнит COMMIT

-- Фиксируем изменения
COMMIT;

-- Проверяем финальное значение рейтинга
SELECT * FROM pizzeria WHERE name = 'Pizza Hut';


-- Session #2
BEGIN;

-- Проверяем начальное значение рейтинга
SELECT * FROM pizzeria WHERE name = 'Pizza Hut';

-- Обновляем рейтинг до 3.6
UPDATE pizzeria SET rating = 3.6 WHERE name = 'Pizza Hut';

-- Фиксируем изменения
COMMIT;

-- Проверяем финальное значение рейтинга
SELECT * FROM pizzeria WHERE name = 'Pizza Hut';
