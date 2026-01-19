CREATE OR REPLACE FUNCTION fnc_fibonacci(pstop INTEGER DEFAULT 10)
RETURNS SETOF INTEGER
AS $BODY$
DECLARE
    a INTEGER := 0;
    b INTEGER := 1;
    next INTEGER;
BEGIN
    IF pstop <= 0 THEN
        RETURN; -- Ничего не возвращаем для pstop <= 0
    END IF;
 
    IF pstop > 0 THEN
        RETURN NEXT a; -- Возвращаем 0
    END IF;
 
    WHILE b < pstop LOOP
        RETURN NEXT b;
        next := a + b;
        a := b;
        b := next;
    END LOOP;
    RETURN;
END;
$BODY$ LANGUAGE plpgsql;
 
-- Примеры использования:
SELECT * FROM fnc_fibonacci(100);
SELECT * FROM fnc_fibonacci();
SELECT * FROM fnc_fibonacci(10);
