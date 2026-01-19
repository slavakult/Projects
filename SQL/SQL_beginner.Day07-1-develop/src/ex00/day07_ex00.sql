SELECT 
    pv.person_id, 
    COUNT(pv2.person_id) AS count_of_visits
FROM 
    (SELECT DISTINCT person_id FROM person_visits) AS pv
LEFT JOIN 
    person_visits pv2 ON pv.person_id = pv2.person_id
GROUP BY 
    pv.person_id
ORDER BY 
    count_of_visits DESC, 
    pv.person_id ASC;
