-- Удаление существующих функций (если они есть)
DROP FUNCTION IF EXISTS fnc_persons_female();
DROP FUNCTION IF EXISTS fnc_persons_male();
 
-- Создание параметризованной функции fnc_persons
CREATE OR REPLACE FUNCTION fnc_persons(pgender VARCHAR DEFAULT 'female')
RETURNS TABLE (
    id BIGINT,
    name VARCHAR,
    age INTEGER,
    gender VARCHAR,
    address VARCHAR
) AS $$
    SELECT id, name, age, gender, address
    FROM person
    WHERE gender = pgender;
$$ LANGUAGE SQL;
 
-- Примеры использования (раскомментируйте для проверки)
-- SELECT * FROM fnc_persons(pgender := 'male');
-- SELECT * FROM fnc_persons();
 
-- Создание функций fnc_persons_female и fnc_persons_male (если они нужны)
-- Эти функции теперь вызывают параметризованную функцию fnc_persons
CREATE OR REPLACE FUNCTION fnc_persons_female()
RETURNS TABLE(
    id BIGINT,
    name VARCHAR,
    age INTEGER,
    gender VARCHAR,
    address VARCHAR
) AS $$
    SELECT * FROM fnc_persons(pgender := 'female');
$$ LANGUAGE sql;
 
CREATE OR REPLACE FUNCTION fnc_persons_male()
RETURNS TABLE(
    id BIGINT,
    name VARCHAR,
    age INTEGER,
    gender VARCHAR,
    address VARCHAR
) AS $$
    SELECT * FROM fnc_persons(pgender := 'male');
$$ LANGUAGE sql;
 
-- Примеры использования
SELECT * FROM fnc_persons_male();
SELECT * FROM fnc_persons_female();
