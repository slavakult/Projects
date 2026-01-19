-- CTE (Common Table Expression) для получения последнего курса валюты к USD
WITH cte_last_rate_to_usd AS (
    SELECT
        currency.id,
        currency.name AS currency_name,
        MAX(currency.rate_to_usd) AS last_rate -- Выбираем максимальный курс для каждой валюты
    FROM currency
    INNER JOIN balance ON currency.id = balance.currency_id -- Соединяем таблицы currency и balance
    WHERE currency.updated = (SELECT MAX(updated) FROM currency) -- Фильтруем только последние обновленные курсы
    GROUP BY currency.id, currency.name 
)
-- Основной запрос для формирования итоговых данных
SELECT
    COALESCE("user".name, 'not defined') AS name, 
    COALESCE("user".lastname, 'not defined') AS lastname, 
    balance.type, 
    SUM(COALESCE(balance.money, 1)) AS volume, -- Сумма денег по каждому типу баланса (если NULL, считаем как 1)
    COALESCE(cte_last_rate_to_usd.currency_name, 'not defined') AS currency_name, 
    COALESCE(cte_last_rate_to_usd.last_rate, 1) AS last_rate_to_usd, 
    SUM(COALESCE(balance.money, 1)) * COALESCE(cte_last_rate_to_usd.last_rate, 1) AS total_volume_in_usd -- Общий объем в USD
FROM balance
FULL JOIN "user" ON "user".id = balance.user_id -- Полное соединение таблиц balance и user
LEFT JOIN cte_last_rate_to_usd ON balance.currency_id = cte_last_rate_to_usd.id -- Левый джойн с CTE для получения курса валюты
GROUP BY type, "user".id, "user".name, lastname, currency_name, last_rate -- Группировка данных для агрегации
ORDER BY name DESC, lastname, type; -- Сортировка результатов