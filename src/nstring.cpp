#include <cstring>
#include <ostream>
#include "nstring.h"

#define MAX 100

using namespace std;

ostream& operator<<(ostream& o,const Nstring& s) {
    o << s.c_str();
    return o;
}
std::istream& operator>>(std::istream& i, Nstring& n) {
    i >> n.text;
    n.length = strlen(n.text);
    return i;
}

NstringException::NstringException(const string &s) {
    error = s;
}

Nstring::Nstring(){
    length = 0;
    text = new char[MAX];
}

Nstring::Nstring(const Nstring& n){
    length = n.length;
    text = new char[MAX];

    strcpy(this->text, n.text);
}

Nstring::Nstring(const char *c){
    length = strlen(c);
    text = new char[MAX];
    strcpy(this->text, c);
}

const char* Nstring::c_str()const{
    if(length==0)
        return "[vide]";
    return text;
}

Nstring& Nstring::operator=(const Nstring& n){
    if(this != &n){
        strcpy(this->text,n.text);
        length = n.length;
    }

    return *this;
}

bool Nstring::operator==(const Nstring& n) const{
    if(this->length != n.length)
        return false;
    else{
        return strcmp(this->text,n.text)==0;
    }
}

bool Nstring::operator!=(const Nstring&n) const {
    return !(*this==n);
}

Nstring& Nstring::operator+=(const Nstring& s) {
    strcat(this->text,s.text);
    return *this;
}

void Nstring::setCarAt(int pos,char c) throw (NstringException) {
    if(this->length+1 < pos)
        throw NstringException("Out of range");
    text[pos]=c;
}

long Nstring::size() const
{
    return length;
}

char Nstring::operator[](int i) const throw (NstringException)
{
    if(length-1 < i)
        throw NstringException("Out of range");
    return text[i];
}


