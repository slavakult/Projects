SELECT
(SELECT NAME
FROM person
WHERE person.id = person_order.person_id
) AS NAME,
CASE
WHEN (SELECT NAME
FROM person
WHERE person.id = person_order.person_id)='Denis' 
THEN 'true' 
else 'false'
END AS CHECK_NAME
FROM person_order
WHERE (person_order.menu_id = 13
OR person_order.menu_id = 14
OR person_order.menu_id = 18)
AND person_order.order_date = '2022-01-07';
