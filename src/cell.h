#ifndef CELL_INCLUDED
#define CELL_INCLUDED

#include "nstring.h"

/** Définition d'une valeur */
template <typename X, typename Y>
struct Tuple {
	X key;
	Y value;

    Tuple();
    Tuple(X,Y);
};

template <typename X, typename Y>
Tuple<X,Y>::Tuple() : key(),value()
{}

template <typename X, typename Y>
Tuple<X,Y>::Tuple(X x,Y y) : key(x), value(y)
{}

/** Gestion des cellules pointés par un résultat de hashage */
template <typename T>
class Cell
{
private:
    Tuple<Nstring,T> *tuple;
    Cell *next;
public:
	/** Initialisation objet vide */
	Cell();
	Cell(const Nstring key, const T value);
	~Cell();

	/** Ajouter ou modifier une valeur si elle existe */
	void set(const Nstring &key, const T &value);

	/** Retourne valeur */
	T getValue(const Nstring &key) const throw (Nstring);
};

//pour resourdre le probleme des templates//cf export
#include "cell.tpp"
#endif // define CELL_INCLUDED


