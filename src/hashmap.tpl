#include "hashmap.h"
#include <iostream>

template <typename Value>
HashMap<Value>::HashMap() : nb_val(0)
                            ,nb_val_max(MAX)
                            ,tab(new Cell<Value>[nb_val_max])
{}

template <typename Value>
HashMap<Value>::HashMap(const Nstring &key,const Value &value) : nb_val(0)
															,nb_val_max(MAX)
															,tab(new Cell<Value>[nb_val_max])
{
	insert(key,value);
}

template <typename Value>
HashMap<Value>::~HashMap()
{
    delete []tab;
}

template <typename Value>
void HashMap<Value>::insert(const Nstring &key, const Value &value)
{
    int i = hash(key);
    tab[i%nb_val_max].set(key,value);
}

template <typename Value>
int HashMap<Value>::hash(const Nstring &key) const
{
    int hash=0;
    int size = key.size();
    for(int i=0;i<size;i++)
        hash+=(int)key[i];
    return hash;
}

template <typename Value>
Value HashMap<Value>::get(const Nstring &key) const throw (NstringException)
{
    int i = hash(key);
    return tab[i%nb_val_max].getValue(key);
}


