CREATE TABLE cities_roads(
    point1 VARCHAR,
    point2 VARCHAR,
    cost INTEGER
);

INSERT INTO cities_roads(point1, point2, cost)
VALUES (
	('a', 'b', 10),
    ('b', 'a', 10),
    ('b', 'c', 35),
    ('c', 'b', 35),
    ('c', 'a', 15),
    ('a', 'c', 15),
    ('a', 'd', 20),
    ('d', 'a', 20),
    ('d', 'c', 30),
    ('c', 'd', 30),
    ('d', 'b', 25),
    ('b', 'd', 25),
);


WITH RECURSIVE road AS (
	SELECT 
        point1 AS path,
        point1, 
        point2, 
		cost
 	FROM cities_roads
 	WHERE point1 = 'a'
  
 	UNION
  
 	SELECT 
 		CONCAT(road.path, ',', cities_roads.point1) AS path,
    	cities_roads.point1, 
		cities_roads.point2,
    	road.cost + cities_roads.cost
 	FROM road
    JOIN cities_roads
    ON road.point2 = cities_roads.point1
  	WHERE path NOT LIKE CONCAT('%', cities_roads.point1, '%')
), routes AS (
	SELECT cost AS total_cost,
    CONCAT('{', path, ',', point2, '}') AS tour
  	FROM road
  	WHERE LENGTH(path) = 7 AND point2 = 'a'
)

SELECT *
FROM routes
WHERE total_cost = ( 
	SELECT MIN(total_cost)
  	FROM routes
)
ORDER BY total_cost, tour