#ifndef TP1_H_INCLUDED
#define TP1_H_INCLUDED

#include <string>

class NstringException {
private:
    std::string error;
public:
    NstringException(const std::string&);
    ~NstringException() {}
    const std::string& to_string() const {return error;}
};

class Nstring {
private:
    char *text;
    long length;
public:
    Nstring();
    Nstring(const Nstring&);
    Nstring(const char *);
    ~Nstring() {}

    long size() const;
    const char* c_str() const;
    bool operator==(const Nstring&) const;
    bool operator!=(const Nstring&) const;
    Nstring& operator=(const Nstring&);
    Nstring& operator+=(const Nstring&);
    void setCarAt(int pos,char c) throw (NstringException);
    char operator[](int i) const throw (NstringException);

    friend std::istream& operator>>(std::istream&, Nstring&);
};
std::ostream& operator<<(std::ostream&, const Nstring&);

#endif // TP1_H_INCLUDED
