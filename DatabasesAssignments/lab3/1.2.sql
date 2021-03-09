select * from
((select * from city) as cities
inner join
(select * from address) as addresses
on cities.city_id = addresses.city_id)
where city like 'A%';