template <typename T>
Cell<T>::Cell() : tuple(NULL)
                ,next(NULL)
{
}

template <typename T>
Cell<T>::Cell(const Nstring key, const T value) : tuple(new Tuple<Nstring,T>(key,value))
									,next(NULL)
{
}

template <typename T>
Cell<T>::~Cell()
{
    if(tuple!=NULL)
        delete tuple;
    if(next!=NULL)
        delete next;
}

template <typename T>
void Cell<T>::set(const Nstring &key, const T &value)
{
	if(tuple==NULL)
        tuple = new Tuple<Nstring,T>(key,value);
    else {
        //sinon on cherche si y'a deja la cle
        Cell *n = this, *previousN = this;
        do {
            if(n->tuple->key == key) {
                n->tuple->value = value;
                return;
            } else {
                previousN=n;
                n = this->next;
            }
        } while(n!=NULL);
        //on a pas la cle
        previousN->next = new Cell<T>(key,value);
    }
}

template <typename T>
T Cell<T>::getValue(const Nstring &key) const throw (Nstring)
{
	if(tuple==NULL)
		throw Nstring("Undefined !");

	const Cell *n = this;
	// Itère sur toutes les données
	do {
		if(key == n->tuple->key)
			return n->tuple->value;
		n = n->next;
	} while(n!=NULL);
	throw Nstring("Undefined !");
}


