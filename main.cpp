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

string convertInt(int number)
{
    if (number == 0)
        return "0";
    string temp="";
    string returnvalue="";
    while (number>0)
    {
        temp+=number%10+48;
        number/=10;
    }
    for (int i=0; i<temp.length(); i++)
        returnvalue+=temp[temp.length()-i-1];
    return returnvalue;
}

int searchKey(vector<node*> &v,int low,int high,int key)
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
            return searchKey(v,mid+1,high,key);
        }
        else if(v[mid]->key>key)
        {
            return searchKey(v,low,mid-1,key);
        }
        else
            return mid;
    }

}

void insertkeyAndValue(vector<node*> &v,int key,int value)
{
    int pos=0,i;
    key=hashKeyGeneration(convertInt(key));
    if(v.size()==0)
    {
        node *newNode=new node();
        newNode->key=key;
        newNode->value=value;
        v.push_back(newNode);
    }

    i=searchKey(v,0,v.size(),key);


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

bool deletekeyAndValue(vector<node*> &v,int key)
{
    int index=searchKey(v,0,v.size(), key=hashKeyGeneration(convertInt(key)));
    if(index!=-1)
    {
        v.erase(v.begin()+index);
    }

    for(int i=0; i<v.size(); i++)
    {
        cout<<"key="<<v[i]->key<<" and value="<<v[i]->value<<endl;
    }

    return true;
}

int main()
{

    vector<node *> map;
    insertkeyAndValue(map,1,10);
    insertkeyAndValue(map,4,12);
    insertkeyAndValue(map,3,13);
    deletekeyAndValue(map,4);
    return 0;
}
