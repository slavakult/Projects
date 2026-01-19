COMMENT ON TABLE person_discounts IS 'Таблица хранит информацию о скидках, предоставляемых каждому покупателю в конкретной пиццерии. 
Это позволяет сделать индивидуальные предложения.';
 
-- Добавление комментариев к столбцам
COMMENT ON COLUMN person_discounts.id IS 'Порядковый номер строки с данными в таблице, который необходим для порядкового счета данных и удобства при обращении к строке.';
COMMENT ON COLUMN person_discounts.person_id IS 'Идентификатор покупателя из таблицы person, у которого своя скидка.';
COMMENT ON COLUMN person_discounts.pizzeria_id IS 'Идентификатор пиццерии со скидкой из таблицы pizzeria.';
COMMENT ON COLUMN person_discounts.discount IS 'Индивидуальная скидка для клиента в зависимости от его заказа.';
