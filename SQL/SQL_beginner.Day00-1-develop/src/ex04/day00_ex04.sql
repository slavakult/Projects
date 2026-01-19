SELECT

name || ' (age:' || age::text ||','|| 'gender:' || quote_literal(gender) || ',' || 'address:' || quote_literal(address) || ')'

AS datas

FROM person

ORDER BY person_information ASC;
