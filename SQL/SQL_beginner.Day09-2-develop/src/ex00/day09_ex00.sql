CREATE TABLE person_audit (
    created timestamp with time zone NOT NULL DEFAULT CURRENT_TIMESTAMP,
    type_event char(1) NOT NULL DEFAULT 'I' CHECK (type_event IN ('I', 'U', 'D')),
    row_id bigint NOT NULL,
    name varchar,
    age integer,
    gender varchar,
    address varchar
);
 
--Создание функции триггера
CREATE OR REPLACE FUNCTION fnc_trg_person_insert_audit()
RETURNS TRIGGER AS $$
BEGIN
    -- Вставка данных о новом INSERT-событии в таблицу person_audit
    INSERT INTO person_audit (created, type_event, row_id, name, age, gender, address)
    VALUES (CURRENT_TIMESTAMP, 'I', NEW.id, NEW.name, NEW.age, NEW.gender, NEW.address);
 
    RETURN NEW;
END;
$$ LANGUAGE plpgsql;
 
-- Создание триггера
CREATE TRIGGER trg_person_insert_audit
AFTER INSERT ON person
FOR EACH ROW
EXECUTE FUNCTION fnc_trg_person_insert_audit();
 
-- Проверка работы триггера
INSERT INTO person (id, name, age, gender, address)
VALUES (10, 'Damir', 22, 'male', 'Irkutsk');
 
-- Проверка содержимого таблицы person_audit
--SELECT * FROM person_audit;
