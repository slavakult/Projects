SELECT DISTINCT person_order.order_date as action_date, name as person_name 
FROM person
JOIN person_order ON person.id = person_order.person_id
LEFT JOIN person_visits ON person.id = person_visits.person_id
ORDER BY action_date ASC, person_name DESC;
