-- Вставляем данные о валюте в таблицу currency
INSERT INTO currency VALUES 
(100, 'EUR', 0.85, '2022-01-01 13:29'),  -- Вставляем запись о курсе евро на 1 января 2022 года
(100, 'EUR', 0.79, '2022-01-08 13:29');  -- Вставляем запись о курсе евро на 8 января 2022 года

-- Выбираем данные о пользователях и их балансах в валюте, конвертированных в доллары США
SELECT
    COALESCE("user".name, 'not defined') AS name,  -- Если имя пользователя отсутствует, заменяем на 'not defined'
    COALESCE("user".lastname, 'not defined') AS lastname,  -- Если фамилия отсутствует, заменяем на 'not defined'
    tcur.name AS currency_name,  -- Название валюты
    tcur.money * COALESCE(tcur.rate_min, tcur.rate_max) AS currency_in_usd  -- Конвертируем сумму в доллары США, используя ближайший доступный курс
FROM (
    -- Подзапрос для получения данных о балансе пользователя и курсах валют
    SELECT
        balance.user_id,  -- ID пользователя
        currency.id,  -- ID валюты
        currency.name,  -- Название валюты
        balance.money,  -- Сумма денег на балансе
        -- Находим ближайший курс валюты к доллару США, который был актуален до обновления баланса
        (SELECT currency.rate_to_usd 
         FROM currency
         WHERE currency.id = balance.currency_id AND currency.updated < balance.updated
         ORDER BY rate_to_usd LIMIT 1) AS rate_min,
        -- Находим ближайший курс валюты к доллару США, который стал актуален после обновления баланса
        (SELECT currency.rate_to_usd 
         FROM currency
         WHERE currency.id = balance.currency_id AND currency.updated > balance.updated
         ORDER BY rate_to_usd LIMIT 1) AS rate_max
    FROM currency
    JOIN balance ON currency.id = balance.currency_id  
    GROUP BY
        balance.money,
        currency.name,
        currency.id,
        balance.updated,
        balance.currency_id,
        balance.user_id
    ORDER BY rate_min DESC, rate_max ) AS tcur
-- Соединяем результат подзапроса с таблицей пользователей, чтобы получить их имена и фамилии
LEFT JOIN "user" ON tcur.user_id = "user".id
-- Сортируем результаты по имени пользователя в обратном порядке, фамилии и названию валюты
ORDER BY name DESC, lastname, currency_name;



