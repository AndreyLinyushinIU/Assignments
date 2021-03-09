CREATE OR REPLACE FUNCTION trigger_function()
RETURNS trigger AS
$$
BEGIN
raise exception 'do not modify it!';
RETURN New;
END; $$
LANGUAGE plpgsql;

create trigger _trigger
after INSERT
on payment
execute procedure trigger_function();
