--DROP SCHEMA public CASCADE;
--CREATE SCHEMA public;

--Table of production companies
CREATE TABLE prodComp (
	_name text NOT NULL PRIMARY KEY,
	_address text NOT NULL UNIQUE
);

--Table of movies
CREATE TABLE movie (
	_year smallint NOT NULL,
	_title text NOT NULL,
	_length smallint NOT NULL,
	_prodComp text NOT NULL,
	_outline text,
	_prodCompName text NOT NULL,
	PRIMARY KEY (_title, _year),
	FOREIGN KEY (_prodCompName) REFERENCES prodComp(_name)
);

--Table of actors
CREATE TABLE actor (
	_name text NOT NULL,
	_birthdate date NOT NULL,
	PRIMARY KEY (_name, _birthdate)
);

--Table of directors
CREATE TABLE director (
	_name text NOT NULL,
	_birthdate date NOT NULL,
	PRIMARY KEY (_name, _birthdate)
);

--Relation movie->genre
CREATE TABLE genre (
	_year smallint NOT NULL,
	_title text NOT NULL,
	_genre text NOT NULL,
	PRIMARY KEY (_title, _year, _genre),
	FOREIGN KEY (_year, _title) REFERENCES movie(_year, _title)
);

--Relation actor->quote
CREATE TABLE quotes (
	_name text NOT NULL,
	_birthdate date NOT NULL,
	_quote text NOT NULL,
	PRIMARY KEY (_name, _birthdate, _quote),
	FOREIGN KEY (_name, _birthdate) REFERENCES actor(_name, _birthdate)
);

--Relation actor<->movie, role
CREATE TABLE roles (
	_name text NOT NULL,
	_birthdate date NOT NULL,
	_year smallint NOT NULL,
	_title text NOT NULL,
	_role text NOT NULL,
	PRIMARY KEY (_name, _birthdate, _year, _title),
	FOREIGN KEY (_name, _birthdate) REFERENCES actor(_name, _birthdate),
	FOREIGN KEY (_year, _title) REFERENCES movie(_year, _title)
);

--Relation director-> movie
CREATE TABLE directors (
	_year smallint NOT NULL,
	_title text NOT NULL,
	_name text NOT NULL,
	_birthdate date NOT NULL,
	PRIMARY KEY (_name, _birthdate, _year, _title),
	FOREIGN KEY (_name, _birthdate) REFERENCES director(_name, _birthdate),
	FOREIGN KEY (_year, _title) REFERENCES movie(_year, _title)
);