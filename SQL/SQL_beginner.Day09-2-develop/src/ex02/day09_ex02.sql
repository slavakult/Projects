CREATE OR REPLACE FUNCTION fnc_trg_person_delete_audit()
RETURNS TRIGGER AS $$
BEGIN
    --Вставляем данные удаленной строки в таблицу аудита
    INSERT INTO person_audit (created, type_event, row_id, name, age, gender, address)
    VALUES (CURRENT_TIMESTAMP, 'D', OLD.id, OLD.name, OLD.age, OLD.gender, OLD.address);
 
    --0Возвращаем удаленную строку (OLD)
    RETURN OLD;
END;
$$ LANGUAGE plpgsql;
 
--Создание триггера
CREATE TRIGGER trg_person_delete_audit
BEFORE DELETE ON person
FOR EACH ROW
EXECUTE FUNCTION fnc_trg_person_delete_audit();
 
--Проверка работы триггера
DELETE FROM person WHERE id = 10;
 
--Проверка содержимого таблицы аудита
SELECT * FROM person_audit;
