SELECT DISTINCT name
FROM (
    SELECT name FROM v_persons_female
    UNION ALL
    SELECT name FROM v_persons_male
) AS combined_names
ORDER BY name;
