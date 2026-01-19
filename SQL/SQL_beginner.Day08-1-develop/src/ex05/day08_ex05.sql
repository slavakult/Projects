-- Session #1
BEGIN;

--Первый запрос: Подсчет начальной суммы рейтингов
SELECT SUM(rating) AS total_rating FROM pizzeria;

--Ждём пока Session 2 выполнит UPDATE и COMMIT

-- Второй запрос: Подсчет суммы рейтингов после изменений
SELECT SUM(rating) AS total_rating FROM pizzeria;


COMMIT;

-- Session #2
BEGIN;

-- Обновляем рейтинг пиццерии 'Pizza Hut'
UPDATE pizzeria SET rating = 1 WHERE name = 'Pizza Hut';


COMMIT;
