SELECT DISTINCT pizzeria.name AS pizzeria_name
FROM pizzeria
WHERE pizzeria.id IN (
    SELECT person_visits.pizzeria_id
    FROM person_visits
    WHERE person_visits.person_id = (
        SELECT person.id
        FROM person
        WHERE person.name = 'Dmitriy'
    ) AND person_visits.visit_date = '2022-01-08'
) AND pizzeria.id IN (
    SELECT menu.pizzeria_id
    FROM menu
    WHERE menu.price < 800
);
