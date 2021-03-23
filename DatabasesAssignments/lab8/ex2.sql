drop table if exists ledger, account;
drop sequence if exists id_ledger;

create table account(
	id integer not null primary key,
	name varchar(40) not null,
	credit integer not null,
	bankname varchar(30) not null
);

CREATE SEQUENCE id_ledger START 1;
create table ledger (
	id integer not null primary key,
	fromID integer not null,
	toID integer not null,
	fee integer not null,
	amount integer not null,
	TransactionDateTime date
);

insert into account(id, name, credit, bankname) values (1, 'SomeName1', 1000, 'SpearBank');
insert into account(id, name, credit, bankname) values (2, 'SomeName2', 1000, 'Tinkoff');
insert into account(id, name, credit, bankname) values (3, 'SomeName3', 1000, 'SpearBank');
insert into account(id, name, credit, bankname) values (4, 'Admin', 0, 'Fees');

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
insert into ledger(id, fromID, toID, amount, fee, TransactionDateTime) values (nextval('id_ledger'), sender, receiver, fee, 30, now());
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

select * from ledger;