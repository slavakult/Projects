SELECT
    m.pizza_name,  
    m.price, 
    pizzeria.name AS pizzeria_name 
FROM
    menu m 
JOIN
    pizzeria ON m.pizzeria_id = pizzeria.id
WHERE
    m.id NOT IN (SELECT menu_id FROM person_order) 
ORDER BY
    m.pizza_name, 
    m.price;
