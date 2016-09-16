#include <iostream>
#include<vector>
#include<algorithm>
#include "hashmap.h"
using namespace std;

int main()
{
    node *head=new node();
    head->next=NULL;
    cout << "Hello world!" << endl;
    insertNode(head,createNode(10,15));
    insertNode(head,createNode(11,16));
    insertNode(head,createNode(12,17));
    insertNode(head,createNode(13,18));
    insertNode(head,createNode(14,19));
    node *temp=searchNode(head,14);
    cout<<"output="<<temp->value<<endl;
    cout<<searchAndDelete(head,12)<<endl;
    temp=searchNode(head,10);
    cout<<"output123="<<temp->value<<endl;
    cout<<searchAndDelete(head,16)<<endl;
    temp=searchNode(head,40);
    if(temp==NULL)
    cout<<"last null";

    //cout<<"last output="<<temp!=NULL?temp->value:NULL<<endl;
    return 0;
}
