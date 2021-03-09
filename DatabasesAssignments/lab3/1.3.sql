select first_name, last_name, city from

(select city, address_id from
(select city, city_id from city) as cities
inner join
(select address_id, city_id from address) as addresses
on cities.city_id = addresses.city_id) as cityAddress

inner join
(select first_name, last_name, address_id from customer) as customerName
on cityAddress.address_id = customerName.address_id;

Notation: П_{first_name, last_name, city}{П_{city, address_id}{П_{city, city_id}{city}
\cross П_{address_id, city_id}{address}}} \cross П_{first_name, last_name, address_id}{customer}