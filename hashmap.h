#ifndef HASHMAP_H_INCLUDED
#define HASHMAP_H_INCLUDED
using namespace std;
class node
{
public:
    int key;
    int value;
    node *next;
};

node* createNode(int key,int value)
{
    node *newnode=new node();
    newnode->key=key;
    newnode->value=value;
    newnode->next=NULL;
    return newnode;
}

node * searchNode(node *head,int key)
{

    while(head->next!=NULL)
    {
        if(head->next->key==key)
        {
            return head->next;
        }
        head=head->next;
    }
    return NULL;

}

void insertNode(node *head,node *keynode)
{
    while(head->next!=NULL)
        head=head->next;
    head->next=keynode;
}

bool searchAndDelete(node *head,int key)
{
    node *temp;
    if(head->next==NULL)
        return false;

    while(head->next!=NULL&&head->next->key!=key)
    {
        head=head->next;
    }

    if(head->next==NULL)
    {
        return false;
    }
    else if(head->next!=NULL&&head->next->key==key)
    {
        temp=head->next;
        head->next=head->next->next;
        delete temp;
        return true;
    }
    else if(head->next!=NULL&&head->next->key!=key)
    {
        return false;
    }
    else
    {
        return false;
    }

}


#endif // HASHMAP_H_INCLUDED
