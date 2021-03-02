SELECT store_id, address_id, sum FROM
(SELECT store_id, address_id FROM store) AS res1
NATURAL JOIN
(SELECT sum, store_id FROM staff
NATURAL JOIN 
(SELECT staff_id, SUM(amount) FROM payment GROUP BY staff_id) AS sales) AS res2
ORDER BY address_id ASC, sum DESC;