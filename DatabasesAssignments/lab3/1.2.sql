select * from
((select * from city) as cities
inner join
(select * from address) as addresses
on cities.city_id = addresses.city_id)
where city like 'A%';

Notation: \sigma_{city starts with 'A'}{\sigma_{true}{city} \cross \sigma_{true}{address}}