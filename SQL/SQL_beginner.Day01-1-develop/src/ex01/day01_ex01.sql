(SELECT NAME as object_name from person ORDER BY NAME)
union ALL
(SELECT pizza_name from menu ORDER BY pizza_name)
