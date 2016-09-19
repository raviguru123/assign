#include <iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#include<string>
#include "hashmap.h"
using namespace std;


int hashKeyGeneration(string word)
{
    int result = 0;
    for(size_t i = 0; i < word.length(); ++i)
    {
        result += word[i] * pow(31, i);
    }
    return result;
}

int searchNode(vector<node*> &v,int low,int high,int key)
{
    int mid=(low+high)/2;
    if(low>=high)
    {
        return -1;
    }
    else
    {
        if(v[mid]->key<key)
        {
            return searchNode(v,mid+1,high,key);
        }
        else if(v[mid]->key>key)
        {
            return searchNode(v,low,mid-1,key);
        }
        else
            return mid;
    }

}

void insertNode(vector<node*> &v,int key,int value)
{
    int pos=0,i;
    if(v.size()==0){
    node *newNode=new node();
    newNode->key=key;
    newNode->value=value;
    v.push_back(newNode);
    }

    i=searchNode(v,0,v.size(),key);


    if(i==-1)
    {
    node *newNode=new node();
    newNode->key=key;
    newNode->value=value;
        i = v.size()-1;
        while(key<v[i]->key && i>=0)
        {

            i--;
        }
        v.insert(v.begin()+i+1,newNode);
    }
    else
    {
        v[i]->value=value;
    }

}

bool deleteNode(vector<node*> &v,int key)
{

        for(int i=0;i<v.size();i++){
        cout<<"key="<<v[i]->key<<" and value="<<v[i]->value<<endl;
        }

    return true;
}

int main()
{

    vector<node *> map;
    insertNode(map,1,10);
    insertNode(map,4,12);
    insertNode(map,3,13);
    deleteNode(map,4);
    return 0;
}
