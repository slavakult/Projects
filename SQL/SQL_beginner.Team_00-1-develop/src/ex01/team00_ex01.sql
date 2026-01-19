WITH RECURSIVE road AS (
    SELECT 
        point1 AS path,
        point1,
        point2,
        cost
    FROM cities_roads
    WHERE point1 = 'a'

    UNION ALL

    SELECT 
        CONCAT(road.path, ',', cities_roads.point1) AS path,
        cities_roads.point1, 
        cities_roads.point2,
        road.cost + cities_roads.cost
    FROM road
    JOIN cities_roads ON road.point2 = cities_roads.point1
    WHERE road.path NOT LIKE CONCAT('%', cities_roads.point1, '%')
)
SELECT 
    cost AS total_cost, 
    CONCAT('{', path, ',', point2, '}') AS tour
FROM road
WHERE LENGTH(path) = 7 AND point2 = 'a'
ORDER BY total_cost, tour
