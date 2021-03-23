--exercise 1 part 1

drop table if exists account;

create table account(
	id integer primary key,
	name varchar(40),
	credit integer
);

insert into account(id, name, credit) values (1, 'SomeName1', 1000);
insert into account(id, name, credit) values (2, 'SomeName2', 1000);
insert into account(id, name, credit) values (3, 'SomeName3', 1000);

BEGIN;
savepoint T1;
UPDATE account SET credit = account.credit - 500 WHERE id = 1;
UPDATE account SET credit = account.credit + 500 WHERE id = 3;
SAVEPOINT T2;
UPDATE account SET credit = account.credit - 700 WHERE id = 2;
UPDATE account SET credit = account.credit + 700 WHERE id = 1;
savepoint T3;
UPDATE account SET credit = account.credit - 100 WHERE id = 2;
UPDATE account SET credit = account.credit - 100 WHERE id = 3;
rollback to T1;
COMMIT;

select id, credit from account;