--Table of movies
CREATE TABLE IF NOT EXISTS movie (
	title text NOT NULL,
	_year smallint NOT NULL,
	_length smallint NOT NULL,
	prodComp text NOT NULL,
	plot text NOT NULL,
	PRIMARY KEY(title, _year),
	FOREIGN KEY (prodComp) REFERENCES prodCompMovie(_name)
);

--Table of actors
CREATE TABLE IF NOT EXISTS actor (
	_name text NOT NULL,
	birthdate date NOT NULL,
	PRIMARY KEY(_name, birthdate)
);

--Table of directors
CREATE TABLE IF NOT EXISTS director (
	_name text NOT NULL,
	birthdate date NOT NULL,
	PRIMARY KEY(_name, birthdate)
);

--Table of production companies
CREATE TABLE IF NOT EXISTS prodComp (
	_name text NOT NULL UNIQUE PRIMARY KEY,
	address text NOT NULL UNIQUE
);

--Relation production company -> movie
CREATE TABLE IF NOT EXISTS prodCompMovie (
	_name text NOT NULL PRIMARY KEY,
	movie text NOT NULL
);

--Relation director -> movies
CREATE TABLE IF NOT EXISTS directorMovie (
	_name text NOT NULL PRIMARY KEY,
	movie text NOT NULL,
	FOREIGN KEY (movie) REFERENCES movieDirector(title)
);

--Relation movie -> directors
CREATE TABLE IF NOT EXISTS movieDirector (
	title text NOT NULL PRIMARY KEY,
	director text NOT NULL,
	FOREIGN KEY (title) REFERENCES movie(title)
);

--Relation movie -> genre
CREATE TABLE IF NOT EXISTS movieGenre (
	title text NOT NULL PRIMARY KEY,
	genre text NOT NULL,
	FOREIGN KEY (title) REFERENCES movie(title)
);

--Relation movie -> actors
CREATE TABLE IF NOT EXISTS movieActors (
	title text NOT NULL PRIMARY KEY,
	actor text NOT NULL,
	FOREIGN KEY (title) REFERENCES movie(title)
);

--Relation movie -> quotes
CREATE TABLE IF NOT EXISTS movieQuotes (
	title text NOT NULL PRIMARY KEY,
	_quote text NOT NULL,
	actor text NOT NULL,
	FOREIGN KEY (title) REFERENCES movie(title),
	FOREIGN KEY (actor) REFERENCES actor(_name)
);

--Relation actor -> movies
CREATE TABLE IF NOT EXISTS actorMovies (
	_name text NOT NULL PRIMARY KEY,
	movie text NOT NULL,
	_role text NOT NULL,
	FOREIGN KEY (movie) REFERENCES movieActors(title)
);
