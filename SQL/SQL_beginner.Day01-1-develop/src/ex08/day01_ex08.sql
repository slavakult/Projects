SELECT order_date, person_information
FROM (
        SELECT 
            po.order_date, 
            p.name || ' (age:' || p.age || ')' AS person_information,
            p.id
        FROM person p
            NATURAL JOIN (
                SELECT person_id , order_date
                FROM person_order 
            ) AS po
    ) AS subquery
ORDER BY order_date, person_information;
