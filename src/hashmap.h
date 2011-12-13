#ifndef HASH_H_INCLUDED
#define HASH_H_INCLUDED

#include "nstring.h"
#include "cell.h"

const int MAX = 42;

template <typename Value>
class HashMap
{
private:
    int nb_val, nb_val_max;
    Cell<Value> *tab;
    int hash(const Nstring&) const;
public:
    HashMap();
    HashMap(const Nstring&,const Value&);
    ~HashMap();
    void insert(const Nstring &key, const Value &value);
    Value get(const Nstring &key) const throw (NstringException);
};

//pour resourdre le probleme des templates//cf export
#include "hashmap.tpl"
#endif // HASH_H_INCLUDED
