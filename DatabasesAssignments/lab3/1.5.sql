select first_name, count(first_name) from customer
group by first_name
having count(first_name) > 1
order by first_name;