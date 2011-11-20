#include <iostream>
#include "nstring.h"
#include "hashmap.h"
#include <vector>
#include <cstdlib>
#include <cstdio>

using namespace std;

void etape1() {
    cout << "test d'egalite des Nstring :" << endl;
    Nstring s1, s2;
    cout << s1 << "==" << s2 << ": " << (s1==s2) << endl;
    Nstring s3("toto");
    cout << s3 << "==" << s1 << ": " << (s1==s3) << endl;
    Nstring s4(s3);
    cout << s3 << "==" << s4 << ": " << (s4==s3) << endl;
    s2="toto";
    cout << s3 << "==" << s2 << ": " << (s2==s3) << endl;
    s3.setCarAt(2,'F');
    cout << s3 << "==" << s2 << ": " << (s2==s3) << endl;
    Nstring s5;
    s5="toto2";
    s5=s5;
    cout << s5 << "==" << s2 << ": " << (s2==s5) << endl;
}

void hashmap()
{
    HashMap<Nstring> hash;
    vector<Nstring> keys;
    Nstring key,value;
    char c='o';
    while (c!='n') {
        cout<<"cle:"<<endl;
        fflush(stdin);
        cin>>key;
        keys.push_back(key);
        cout<<"value:"<<endl;
        fflush(stdin);
        cin>>value;
        hash.insert(key,value);
        cout<<"continuer ? (o/n)";
        fflush(stdin);
        cin>>c;
    }

    for(int i=0;i<(int)keys.size();i++)
        cout<<"hash["<<keys[i]<<"]="<<hash.get(keys[i])<<endl;
}

int main()
{
    hashmap();

    return 0;
}

