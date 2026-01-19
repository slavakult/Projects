 m1.pizza_name AS pizza_name, --здесь я решил использовать алиасы для того
    pz1.name AS pizzeria_name_1, -- чтобы сделать копии меню и сделать отдельно названия пицц 
    pz2.name AS pizzeria_name_2,
    m1.price AS price
FROM
    menu m1
JOIN
    pizzeria pz1 ON m1.pizzeria_id = pz1.id
JOIN
    menu m2 ON m1.pizza_name = m2.pizza_name AND m1.price = m2.price AND m1.pizzeria_id != m2.pizzeria_id
JOIN
    pizzeria pz2 ON m2.pizzeria_id = pz2.id
WHERE
    m1.id > m2.id  
ORDER BY
    pizza_name;
