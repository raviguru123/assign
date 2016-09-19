#include <iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#include<string>
#include "hashmap.h"
#define min_value -1000000;
using namespace std;
void print(vector<node*>&v)
{
    for(int i=0; i<v.size(); i++)
    {
        while(v[i]->next!=NULL)
        {
            cout<<"key="<<v[i]->next->key<<" value="<<v[i]->next->value<<" ";
            v[i]=v[i]->next;
        }
        cout<<endl;
    }

}

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

node * createMapNode(int indexKey,int key,int value)
{
    node *head=new node();
    head->key=indexKey;
    node *newNode=new node();
    newNode->key=key;
    newNode->value=value;
    newNode->next=NULL;
    head->next=newNode;
    return head;
}


void insertkeyAndValue(vector<node*> &v,int key,int value)
{
    int pos=0,i;
    int indexkey=hashKeyGeneration(convertInt(key));
    if(v.size()==0)
    {
        node *newNode=createMapNode(indexkey,key,value);
        v.push_back(newNode);
        return;
    }

    i=searchKey(v,0,v.size(),indexkey);
    if(i==-1)
    {
        i = v.size();
        while(indexkey<v[i-1]->key&& i>0)
        {
            i--;
        }
        node *newNode=createMapNode(indexkey,key,value);
        v.insert(v.begin()+i,newNode);

    }
    else
    {
        node *temp=v[i];
        bool isExist=false;

        while(temp->next!=NULL)
        {
            if(temp->next->key==key)
            {
                isExist=true;
                temp->next->value=value;
                temp=temp->next;
            }

        }
        if(isExist==false)
        {
            node *keyNode=new node();
            keyNode->key=key;
            keyNode->value=value;
            keyNode->next=NULL;
            insertNode(v[i],keyNode);
        }

    }

}

bool deletekeyAndValue(vector<node*> &v,int key)
{
    int index=searchKey(v,0,v.size(),hashKeyGeneration(convertInt(key)));
    if(index!=-1)
    {
        if(searchAndDelete(v[index],key)==true)
        {
            if(v[index]->next==NULL)
            {
                v.erase(v.begin()+index);
            }
        }
        return true;

    }
    return false;
}



int searchValue(vector<node*> &v,int key)
{
    int index=searchKey(v,0,v.size(),hashKeyGeneration(convertInt(key)));
    if(index!=-1)
    {
        node *keyNode=searchNode(v[index],key);
        if(keyNode!=NULL)
            return keyNode->value;
    }

    return min_value;
}


int main()
{

    vector<node *> map;
    insertkeyAndValue(map,1,10);
    insertkeyAndValue(map,4,12);
    insertkeyAndValue(map,3,13);
    insertkeyAndValue(map,3,16);
    deletekeyAndValue(map,3);
    deletekeyAndValue(map,16);
    deletekeyAndValue(map,4);
    deletekeyAndValue(map,1);
    cout<<searchValue(map,1)<<endl;
    print(map);
    return 0;
}
