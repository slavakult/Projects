INSERT INTO menu 
VALUES(
  (SELECT MAX(id) +1 FROM menu),
  (SELECT id from pizzeria where name='Dominos'),
  'sizilian pizza',
  900);
