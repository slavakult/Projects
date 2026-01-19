INSERT INTO person_visits
VALUES (
    (SELECT MAX(id) + 1 FROM person_visits),
    (SELECT id FROM person WHERE name = 'Dmitriy'),
    (SELECT pizzeria.id
     FROM pizzeria
     JOIN menu ON pizzeria.id = menu.pizzeria_id
     WHERE price < 800
       AND pizzeria.name NOT IN (
            SELECT pizzeria_name FROM mv_dmitriy_visits_and_eats)
     LIMIT 1),
    '2022-01-08'
);
