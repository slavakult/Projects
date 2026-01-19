SELECT 
    pz.name AS name, 
    agg.count_of_orders, 
    agg.average_price, 
    agg.max_price, 
    agg.min_price
FROM (
    SELECT 
        m.pizzeria_id, 
        COUNT(*) AS count_of_orders, 
        ROUND(AVG(m.price), 2) AS average_price, 
        MAX(m.price) AS max_price, 
        MIN(m.price) AS min_price
    FROM 
        person_order po
    JOIN 
        menu m ON po.menu_id = m.id
    GROUP BY 
        m.pizzeria_id
) AS agg
JOIN 
    pizzeria pz ON pz.id = agg.pizzeria_id
ORDER BY 
    pz.name;
