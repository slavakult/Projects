SELECT 
    person.NAME, 
    COUNT(person_visits.person_id) AS count_of_visits
FROM 
    person_visits
join person on person_visits.person_id=person.id 
GROUP BY 
    person.name
ORDER BY 
    count_of_visits DESC, 
    person.name ASC
     limit 4;
