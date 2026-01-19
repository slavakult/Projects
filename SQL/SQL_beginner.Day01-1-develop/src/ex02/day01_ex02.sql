SELECT pizza_name FROM (
    SELECT pizza_name FROM menu
    UNION
    SELECT pizza_name FROM menu
) AS unique_pizzas
ORDER BY pizza_name DESC;
