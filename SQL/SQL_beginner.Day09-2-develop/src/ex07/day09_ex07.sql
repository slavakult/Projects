CREATE OR REPLACE FUNCTION func_minimum(VARIADIC arr NUMERIC[] DEFAULT '{}')
RETURNS NUMERIC
AS $BODY$
DECLARE
    minimum_value NUMERIC;
    num NUMERIC;
BEGIN
    IF array_length(arr, 1) IS NULL THEN
        RETURN NULL; -- Или какое-то другое значение по умолчанию, если массив пуст
    END IF;
 
    minimum_value := arr[1]; -- Инициализируем первым элементом массива
 
    FOREACH num IN ARRAY arr
    LOOP
        IF minimum_value > num THEN
            minimum_value := num;
        END IF;
    END LOOP;
 
    RETURN minimum_value;
END;
$BODY$ LANGUAGE plpgsql;
 
-- Примеры использования:
SELECT func_minimum(10.0, -1.0, 5.0, 4.4);  -- VARIADIC вызов
SELECT func_minimum();  -- Вызов с параметром по умолчанию (пустой массив)
SELECT func_minimum(VARIADIC ARRAY[10.0, -1.0, 5.0, 4.4]); --Явный VARIADIC массив
