--Создание функции триггера
CREATE OR REPLACE FUNCTION fnc_trg_person_update_audit()
RETURNS TRIGGER AS $$
BEGIN
    -- Сохраняем старое состояние записи в таблицу аудита
    INSERT INTO person_audit (created, type_event, row_id, name, age, gender, address)
    VALUES (CURRENT_TIMESTAMP, 'U', OLD.id, OLD.name, OLD.age, OLD.gender, OLD.address);

    -- Возвращаем новое значение, чтобы обновление продолжилось
    RETURN NEW;
END;
$$ LANGUAGE plpgsql;

-- Создание триггера
CREATE TRIGGER trg_person_update_audit
AFTER UPDATE ON person
FOR EACH ROW
EXECUTE FUNCTION fnc_trg_person_update_audit();

--Применение операций UPDATE - применять после использования основного запроса
--UPDATE person SET name = 'Bulat' WHERE id = 10;
--UPDATE person SET name = 'Damir' WHERE id = 10;

--Проверка содержимого таблицы аудита
SELECT * FROM person_audit;
