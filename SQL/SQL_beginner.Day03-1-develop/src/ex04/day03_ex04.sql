WITH female_orders AS (
    SELECT
        pizzeria.name AS pizzeria_name
    FROM
        person_order
    JOIN
        menu ON person_order.menu_id = menu.id
    JOIN
        pizzeria ON menu.pizzeria_id = pizzeria.id
    JOIN
        person ON person_order.person_id = person.id
    WHERE
        person.gender = 'female'
),
male_orders AS (
    SELECT
        pizzeria.name AS pizzeria_name
    FROM
        person_order
    JOIN
        menu ON person_order.menu_id = menu.id
    JOIN
        pizzeria ON menu.pizzeria_id = pizzeria.id
    JOIN
        person ON person_order.person_id = person.id
    WHERE
        person.gender = 'male'
),
only_female_orders AS (
    SELECT
        pizzeria_name
    FROM
        female_orders
    EXCEPT
    SELECT
        pizzeria_name
    FROM
        male_orders
),
only_male_orders AS (
    SELECT
        pizzeria_name
    FROM
        male_orders
    EXCEPT
    SELECT
        pizzeria_name
    FROM
        female_orders
)
SELECT
    pizzeria_name
FROM
    only_female_orders
UNION
SELECT
    pizzeria_name
FROM
    only_male_orders
ORDER BY
    pizzeria_name;
