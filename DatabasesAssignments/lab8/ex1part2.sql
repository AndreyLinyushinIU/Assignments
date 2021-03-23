ALTER TABLE account ADD COLUMN BankName varchar(30);
UPDATE account SET BankName = 'SpearBank' where id = 1 or id = 3;
UPDATE account SET BankName = 'Tinkoff' where id = 2;
insert into account(id, name, credit, bankname) values (4, 'FeeAccount', 0, 'FeeBank');

CREATE OR REPLACE FUNCTION  send(sender integer, receiver integer, fee integer) returns void AS
$$
declare
	bank1 varchar(30);
	bank2 varchar(30);
BEGIN
UPDATE account SET credit = account.credit - fee WHERE id = sender;
UPDATE account SET credit = account.credit + fee WHERE id = receiver;
select bankname into bank1 from account where id = sender;
select bankname into bank2 from account where id = receiver;
if bank1 <> bank2 then
	UPDATE account SET credit = account.credit - 30 WHERE id = sender;
	UPDATE account SET credit = account.credit + 30 WHERE id = 4;
end if;

END; $$
LANGUAGE plpgsql;

BEGIN;
	savepoint T1;
	select send(1,3,500);
	savepoint T2;
	select send(2,1,700);
	savepoint T3;
	select send(2,3,100);
COMMIT;

select * from account;