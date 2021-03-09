SELECT title FROM film
WHERE (rating='R' OR rating='PG-13') AND film_id IN
(SELECT film_id FROM film_category
WHERE category_id IN
(SELECT category_id FROM category
WHERE name='Horror' OR name='Sci-Fi'))
AND film_id NOT IN
(SELECT film_id 
FROM rental
INNER JOIN inventory 
ON inventory.inventory_id = rental.inventory_id);