#include <iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#include<string>
#include "hashmap.h"
using namespace std;

template < class T >
string to_string( T t )
{
    stringstream ss;
    ss << t;
    return ss.str();
}


int hashKeyGeneration(string word) {
    int result = 0;
    for(size_t i = 0; i < word.length(); ++i) {
        result += word[i] * pow(31, i);
    }
    return result;
}

int searchNode(vector<node*> &v,int low,int high,int key){
  int mid=(low+high)/2;
    if(low>=high){
        return -1;
    }
    else{
            if(v[mid]->key<key){
            return searchNode(v,mid+1,high,key);
            }
            else if(v[mid]->key>key){
            return searchNode(v,low,mid-1,key);
            }
            else
                return mid;
    }

    }

void insertNode(vector<node*> &v,int key,int value){
       int newkey=hashKeyGeneration(to_string(key));
}

int findIndex(vector<node*> &v,int key){

}

bool deleteNode(vector<node*> &v,int key){



    return true;
}

int main()
{

 vector<node *> map;
     insertNode(map,1,2);
    return 0;
}
