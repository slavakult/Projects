select DISTINCT person_visits.visit_date as missing_date
from person_visits
LEFT JOIN (select visit_date from person_visits where person_id=1 or person_id=2) as data
ON person_visits.visit_date=data.visit_date
WHERE data.visit_date is NULL
ORDER BY missing_date ASC;
