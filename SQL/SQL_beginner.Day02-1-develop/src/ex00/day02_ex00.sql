SELECT NAME, RATING
FROM pizzeria
LEFT JOIN person_visits ON pizzeria.ID = person_visits.PIZZERIA_ID
where pizzeria_id IS NULL;
