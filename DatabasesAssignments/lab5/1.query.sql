1.1
Explain SELECT * FROM public.payment where amount=2
1.2
CREATE UNIQUE INDEX emai ON customer(email);
CREATE INDEX addr ON customer USING hash (address_id);
1.3
EXPLAIN analyze SELECT * FROM customer 
WHERE customer.address_id > 100 AND customer.address_id < 500; 
1.4
The total time for a query significantly decreased