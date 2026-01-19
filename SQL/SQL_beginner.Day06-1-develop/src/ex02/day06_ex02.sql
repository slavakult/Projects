SELECT 
    p.name AS name, -- Имя человека
    m.pizza_name AS pizza_name, -- Название пиццы
    m.price AS price, -- Фактическая цена
    ROUND(m.price * (1 - pd.discount / 100), 2) AS discount_price, -- Цена со скидкой
    pz.name AS pizzeria_name -- Название пиццерии
FROM 
    person_order po
JOIN 
    person p ON po.person_id = p.id -- Соединяем таблицу заказов с таблицей человек
JOIN 
    menu m ON po.menu_id = m.id -- Соединяем таблицу заказов с таблицей меню
JOIN 
    pizzeria pz ON m.pizzeria_id = pz.id -- Соединяем таблицу меню с таблицей пиццерий
JOIN 
    person_discounts pd ON p.id = pd.person_id AND pz.id = pd.pizzeria_id -- Применяем скидки
ORDER BY 
    p.name, m.pizza_name; -- Сортируем по имени человека и названию пиццы
