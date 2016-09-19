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
//label 1 function start from here
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


#endif // HASHMAP_H_INCLUDED
