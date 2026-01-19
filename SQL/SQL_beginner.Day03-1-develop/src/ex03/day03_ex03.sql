WITH female_visits AS (
    SELECT
        pizzeria.name AS pizzeria_name,
        COUNT(*) AS visit_count
    FROM
        person_visits
    JOIN
        pizzeria ON person_visits.pizzeria_id = pizzeria.id
    JOIN
        person ON person_visits.person_id = person.id
    WHERE
        person.gender = 'female'
    GROUP BY
        pizzeria.name
),
male_visits AS (
    SELECT
        pizzeria.name AS pizzeria_name,
        COUNT(*) AS visit_count
    FROM
        person_visits
    JOIN
        pizzeria ON person_visits.pizzeria_id = pizzeria.id
    JOIN
        person ON person_visits.person_id = person.id
    WHERE
        person.gender = 'male'
    GROUP BY
        pizzeria.name
),
more_female_visits AS (
    SELECT
        female_visits.pizzeria_name
    FROM
        female_visits
    LEFT JOIN
        male_visits ON female_visits.pizzeria_name = male_visits.pizzeria_name
    WHERE
        female_visits.visit_count > COALESCE(male_visits.visit_count, 0)
),
more_male_visits AS (
    SELECT
        male_visits.pizzeria_name
    FROM
        male_visits
    LEFT JOIN
        female_visits ON male_visits.pizzeria_name = female_visits.pizzeria_name
    WHERE
        male_visits.visit_count > COALESCE(female_visits.visit_count, 0)
)
SELECT
    pizzeria_name
FROM
    more_female_visits
UNION ALL
SELECT
    pizzeria_name
FROM
    more_male_visits
ORDER BY
    pizzeria_name;
