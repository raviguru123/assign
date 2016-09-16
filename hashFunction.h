#ifndef HASHFUNCTION_H_INCLUDED
#define HASHFUNCTION_H_INCLUDED
#include <vector>
using namespace std;
template<class T1,class T2>
class valuenode{
        T1 key;
        T2 value;
        valuenode<T1,T2> *next;
};

template<class T1,class T2>
class keynode{
    int key;
    valuenode<T1,T2> *next;
};

template<class T1,class T2>
class map{
    vector<keynode<T1,T2> *> container;
    public:
    void insert(keynode<T1,T2> &node){

    }
};
#endif // HASHFUNCTION_H_INCLUDED
