SELECT COALESCE(p.name, '-') AS person_name,
       pv.visit_date,
       COALESCE(pz.name, '-') AS pizzeria_name
FROM (
        SELECT person_id, pizzeria_id, visit_date
        FROM person_visits
        WHERE visit_date BETWEEN '2022-01-01' AND '2022-01-03'
    ) AS pv
FULL OUTER JOIN person p ON pv.person_id = p.id
FULL OUTER JOIN pizzeria pz ON pv.pizzeria_id = pz.id
ORDER BY person_name, visit_date, pizzeria_name;
