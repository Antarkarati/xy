#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

Node* createNode(int val)
{
    Node* newNode=new Node();

    newNode->data=val;
    newNode->next=NULL;

    return newNode;
}

void insert(Node* &head ,int val)
{
    Node* newNode=createNode(val);

    if(head==NULL)
    {
        head=newNode;
        return;
    }

    Node* temp=head;

    while(temp->next!=NULL)
    {
        temp=temp->next;
    }

    temp->next=newNode;
}

void display(Node* head)
{
    Node* temp=head;

    while(temp!=NULL)
    {
        cout<<temp->data;
        if(temp->next!=NULL)
            cout<<" -> ";
        
        temp=temp->next;
        
    }
    cout<<endl;
}

Node* getintersect(Node* head1,Node* head2)
{
    Node* t1=head1;
    Node* result=NULL;

    while(t1!=NULL)
    {
        Node* t2=head2;
        while(t2!=NULL)
        {
            if(t1->data==t2->data)
            
            {
                insert(result,t1->data);
                break;
            } 
            t2=t2->next;
        }
        t1=t1->next;
    }
    return result;
}

int main()
{
    Node* h1=NULL;
    Node* h2=NULL;

    insert(h1,1);
    insert(h1,2);
    insert(h1,3);
    insert(h1,4);

    insert(h2,3);
    insert(h2,4);
    insert(h2,5);
    insert(h2,6);

    display(h1);
    display(h2);

    Node* inter=getintersect(h1,h2);
    display(inter);
      display(inter);

    return 0;
}