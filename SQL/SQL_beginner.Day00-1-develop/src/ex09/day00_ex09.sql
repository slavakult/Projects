SELECT
(SELECT NAME FROM person WHERE person.id=person_visits.person_id)
AS person_name,
(SELECT name FROM pizzeria WHERE pizzeria.id = person_visits.pizzeria_id)
AS pizzeria_name
FROM person_visits
WHERE visit_date BETWEEN '2022-01-07' and '2022-01-09'
ORDER BY person_name ASC, pizzeria_name DESC;
