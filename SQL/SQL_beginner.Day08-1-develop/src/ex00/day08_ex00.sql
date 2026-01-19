--Session #1: Обновление рейтинга пиццерии в транзакции
BEGIN;
--Обновляем рейтинг пиццерии 'Pizza Hut' до 5
UPDATE pizzeria SET rating = 5 WHERE name = 'Pizza Hut';
--Проверяем изменения в Session #1
SELECT * FROM pizzeria WHERE name = 'Pizza Hut';
--Фиксируем изменения
COMMIT;

--Session #2: Проверка видимости изменений
--Перед фиксацией в Session #1
SELECT * FROM pizzeria WHERE name = 'Pizza Hut';
--После фиксации в Session #1
SELECT * FROM pizzeria WHERE name = 'Pizza Hut';
