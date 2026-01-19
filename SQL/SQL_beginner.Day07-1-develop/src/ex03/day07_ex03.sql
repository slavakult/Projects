SELECT 
    pz.name AS name,
    COALESCE(SUM(visits.count_of_visits), 0) + COALESCE(SUM(orders.count_of_orders), 0) AS total_count
FROM 
    pizzeria pz
LEFT JOIN 
    (
        SELECT 
            pizzeria_id, 
            COUNT(*) AS count_of_visits
        FROM 
            person_visits
        GROUP BY 
            pizzeria_id
    ) visits ON pz.id = visits.pizzeria_id
LEFT JOIN 
    (
        SELECT 
            m.pizzeria_id, 
            COUNT(*) AS count_of_orders
        FROM 
            person_order po
        JOIN 
            menu m ON po.menu_id = m.id
        GROUP BY 
            m.pizzeria_id
    ) orders ON pz.id = orders.pizzeria_id
GROUP BY 
    pz.name
ORDER BY 
    total_count DESC, 
    name ASC;
