male(alexandr).
male(andrey).
male(nikolay).
male(alexey).
male(michail).
male(sergei).

female(lusia).
female(marina).
female(nina).
female(ira).


parent(marina, andrey).
parent(alexandr, andrey).
parent(nikolay, marina).
parent(nina, marina).
parent(alexey, alexandr).
parent(lusia, alexandr).
parent(nikolay, ira).
parent(nina, ira).
parent(ira, michail).
parent(alexey, sergei).
parent(lusia, sergei).

child(X, Y) :- parent(Y, X).
grandParent(X, Z) :- parent(X, Y), parent(Y, Z).
grandChild(X, Z) :- child(X, Y), child(Y, Z).

getParent(X) :- parent(Y, X), write(Y).
getGrandParent(X) :- parent(Y, X), parent(Z, Y), write(Z).
getChild(X) :- child(X, Y), write(Y).
getGrandChild(X) :- child(X, Y), child(Y, Z), write(Z).

sibling(andrey, michail).
sibling(alexandr, sergei).
sibling(X, Y) :- sibling(Y, X).
getSibling(X) :- sibling(X, Y), write(Y).
