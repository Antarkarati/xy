#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};

Node* createNode(int val)
{
    Node* newNode=new Node();

    newNode->data=val;
    newNode->left=NULL;
    newNode->right=NULL;

    return newNode;
}

Node* inset(Node* &root,int val)
{
    if(root==NULL)
    {
        cout<<val<<" inserted as Root(level 0)\n";

        return createNode(val);
    }

    Node* temp=root;
    int level=0;

    while(true)
    {
        if(val==temp->data)
        {
            cout<<val<<" is alrady present at level "<<level<<'\n';

            return root;
        }

        else if(val<temp->data)
        {
            if(temp->left==NULL)
            {
                temp->left=createNode(val);

                cout<<val<<" inserted at level "<<level+1<<" Left of "<<temp->data<<"\n";
                return root;
            }
            temp=temp->left;
        }

        else
        {
            if(temp->right==NULL)
            {
                temp->right=createNode(val);

                cout<<val<<" inserted at level "<<level+1<<" right of "<<temp->data<<"\n";
                return root;
            }

            temp=temp->right;
        }
        level++;
    }
}


int main()
{
    Node* root=NULL;

    root =inset(root,50);

    inset(root,30);
    inset(root,70);
    inset(root,20);
    inset(root,40);

    inset(root,30);
    inset(root,70);

    inset(root,60);

    return 0;
}
