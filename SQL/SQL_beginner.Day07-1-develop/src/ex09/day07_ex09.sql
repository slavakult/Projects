WITH temp AS (
    SELECT 
        address,
        (CAST(MAX(age) AS NUMERIC) - CAST(MIN(age) AS NUMERIC) / CAST(MAX(age) AS NUMERIC)) AS formula, -- Не округляем formula
        ROUND(AVG(age), 2) AS average -- Округляем average до двух знаков после запятой
    FROM 
        person
    GROUP BY 
        address
)
SELECT 
    *, 
    (formula > average) AS comparison -- Добавляем логическое сравнение
FROM 
    temp
ORDER BY 
    address; -- Сортируем по address
