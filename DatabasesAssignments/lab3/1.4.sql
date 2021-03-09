select first_name, last_name, amount from
(select customer_id, amount from payment where amount > 11) as payments
inner join
(select customer_id, first_name, last_name from customer) as customer
on payments.customer_id = customer.customer_id;