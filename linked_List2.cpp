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

void insertAtEnd(Node* &head,int val)
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
        if(temp->next!=NULL) cout<<" -> ";

        temp=temp->next;
    }

    cout<<"\n";
}

void insertAtPosition(Node* &head,int val,int pos)
{
    Node* newNode=createNode(val);

    if(pos==1)
    {
        newNode->next=head;
        head=newNode;
        return;
    }

    Node* temp=head;
    
    for(int i=1;i<pos-1 && temp!=NULL;i++)
    {
        temp=temp->next;
    }

    if(temp!=NULL)
    {
        newNode->next=temp->next;
        temp->next=newNode;
    }

}

void insertAtFront(Node* &head,int val)
{
    insertAtPosition(head,val,1);
}

void deleteAtPosition(Node* &head,int pos)
{
    if(head==NULL) return;

    if(pos==1)
    {
        Node* temp=head;
        head=head->next;

        delete temp;
        return;
    }

    Node* temp=head;

    for(int i=1;i<pos-1 && temp!=NULL;i++)
    {
        temp=temp->next;
    }

    if(temp!=NULL && temp->next!=NULL)
    {
        Node* d=temp->next;

        temp->next=temp->next->next;

        delete d;

        return;
    }
}

void sorting(Node* head)
{
    if(head==NULL) return;

    Node* i=head;
    while(i!=NULL)
    {
        Node* j=head;
        while(j->next!=NULL)
        {
            if(j->data>j->next->data) swap(j->data,j->next->data);
            j=j->next;
        }
        i=i->next;
    }
}

int main()
{
    Node* head=NULL;

    insertAtEnd(head,5);
    insertAtEnd(head,3);
    insertAtEnd(head,9);
    insertAtEnd(head,42);
    insertAtEnd(head,0);
    insertAtEnd(head,10);

    display(head);

    insertAtPosition(head,99,5);
    display(head);

    insertAtFront(head,1);
    display(head);

    deleteAtPosition(head,2);
    display(head);

    sorting(head);
    display(head);
}