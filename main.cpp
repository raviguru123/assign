#include <iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#include<string>
#include "hashmap.h"
#define min_value -1000000;
using namespace std;


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



int searchkeyAndValue(vector<node*> &v,int key)
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
    insertkeyAndValue(map,1,10);//first parameter pointer to node class and second paramter key and third parameter
    insertkeyAndValue(map,4,12);
    insertkeyAndValue(map,3,13);
    insertkeyAndValue(map,3,16);
    deletekeyAndValue(map,3);
    deletekeyAndValue(map,16);
    cout<<searchkeyAndValue(map,4)<<endl;
    deletekeyAndValue(map,4);
    deletekeyAndValue(map,1);
    cout<<searchkeyAndValue(map,67)<<endl;
    print(map);
    return 0;
}
