SELECT DISTINCT
    p.name
FROM
    person p
JOIN
    person_order po ON p.id = po.person_id
JOIN
    menu m ON po.menu_id = m.id
WHERE
    p.gender = 'female'
    AND m.pizza_name = 'pepperoni pizza'
INTERSECT
SELECT DISTINCT
    p.name
FROM
    person p
JOIN
    person_order po ON p.id = po.person_id
JOIN
    menu m ON po.menu_id = m.id
WHERE
    p.gender = 'female'
    AND m.pizza_name = 'cheese pizza'
ORDER BY 1;
