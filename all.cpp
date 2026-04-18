//linked list

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







/////bst
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




//////ll intersecting 
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



/////graph

#include<bits/stdc++.h>
using namespace std;

#define INF 99999

int main()
{
    ifstream inFile("input.txt");
    ofstream outFile("output.txt");

    if(!inFile)
    {
        cout<<"Error .input.txt not found.creste it.";
        return 1;
    } 


    int n;
    inFile>>n;

    int path[10][10];

    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            inFile>>path[i][j];

            if(path[i][j]==0) path[i][j]=INF;
        }
    }

    for(int k=0;k<n;k++)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(path[i][j]>path[i][k]+path[k][j])
                    path[i][j]=path[i][k]+path[k][j];
            }
        }

    }


    outFile<<"The Shortest Path Matrix:\n";
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(path[i][j]==INF) outFile<<"0 ";
            else
            outFile<<path[i][j]<<" ";
        }
        outFile<<"\n";
    }

    cout<<"Success\n";

    inFile.close();
    outFile.close();

    return 0;
}


/////Stack postfix evaluation 

#include <iostream>
#include <string>  
#include <cmath> 
#include <cctype>  

using namespace std;


#define MAX 100

class Stack {
    int arr[MAX];
    int top_index;

public:
    
    Stack() {
        top_index = -1;
    }
    
   
    void push(int value) {
        if (top_index >= MAX - 1) {
            cout << "Stack Overflow!" << endl;
            return;
        }
        top_index++;
        arr[top_index] = value;
    }
    
    
    int top() {
        if (top_index < 0) {
            return -1; 
        }
        return arr[top_index];
    }
    
    
    void pop() {
        if (top_index < 0) {
            cout << "Stack Underflow!" << endl;
            return;
        }
        top_index--;
    }
};


int main() {
    string postfix;
    cout << "Input postfix expression: ";
    cin >> postfix;

    Stack s; 
    int var_values[26]; 
    
    for (int i = 0; i < 26; i++) {
        var_values[i] = -1; 
    }

   
    for (int i = 0; i < postfix.length(); i++) {
        char ch = postfix[i];

        
        if (isalpha(ch)) {
            int index = ch - 'a'; 
            
           
            if (var_values[index] == -1) {
                cout << "Enter the value of " << ch << ": ";
                cin >> var_values[index];
            }
            s.push(var_values[index]); 
        } 
       
        else if (isdigit(ch)) {
            s.push(ch - '0'); 
        } 
       
        else {
            
            int val1 = s.top(); s.pop(); 
            int val2 = s.top(); s.pop(); 

           
            switch (ch) {
                case '+': s.push(val2 + val1); break;
                case '-': s.push(val2 - val1); break;
                case '*': s.push(val2 * val1); break;
                case '/': s.push(val2 / val1); break;
                case '^': s.push(pow(val2, val1)); break;
            }
        }
    }

    
    cout << "Output: " << s.top() << endl;

    return 0;
}


///////tree traversal

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

void preorder(Node* root)
{
    if(root==NULL) return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node* root)
{
    if(root==NULL) return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void postorder(Node* root)
{
    if(root==NULL) return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";

}

int main()
{
    Node* root=NULL;
    root=createNode(2);
    root->left=createNode(7);
    root->right=createNode(5);
    root->left->left=createNode(8);
    root->right->right=createNode(4);

    preorder(root);
    cout<<endl;
    inorder(root);
    cout<<endl;

    postorder(root);
    cout<<endl;

    return 0;
}

/////bs

#include<bits/stdc++.h>
using namespace std;

int binarySearch(int arr[],int n,int t)
{
    int left=0;
    int right=n-1;

    while(left<=right)
    {
        int mid=left+(right-left)/2;

        if(arr[mid]==t) return mid;
        if(arr[mid]<t) left=mid+1;
        else right=mid-1;
    }

    return -1;
}

int main()
{
    int arr[]={10,20,40,50,70,890};

    int t=90;
    int n=sizeof(arr)/sizeof(arr[0]);

    int r=binarySearch(arr,n,t);

    if(r==-1) cout<<" Not found";
    else cout<<" found at"<<r+1;

    return 0;
}

//////in to post

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

#define MAX 100

class Stack {
    char arr[MAX];
    int top_index;
public:
    Stack() { 
        top_index = -1; 
    }
    
    void push(char val) {
        arr[++top_index] = val;
    }
    
    char pop() {
        if (top_index == -1) return '\0';
        return arr[top_index--];
    }
    
    char top() {
        if (top_index == -1) return '\0';
        return arr[top_index];
    }
    
    bool isEmpty() {
        return top_index == -1;
    }
    
    string getStackContent() {
        string s = "";
        for (int i = 0; i <= top_index; i++) {
            s += arr[i];
        }
        return s;
    }
};

int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return -1;
}

void infixToPostfix(string infix) {
    Stack s;
    string postfix = "";

    cout << "\n";
    cout << left << setw(18) << "Symbol Scanned" 
         << setw(15) << "Stack" 
         << "Postfix Expression" << "\n";
    cout << "---------------------------------------------------\n";

    for (int i = 0; i < infix.length(); i++) {
        char ch = infix[i];

        if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9')) {
            postfix += ch;
        }
        else if (ch == '(') {
            s.push(ch);
        }
        else if (ch == ')') {
            while (!s.isEmpty() && s.top() != '(') {
                postfix += s.pop();
            }
            s.pop(); 
        }
        else {
            while (!s.isEmpty() && precedence(ch) <= precedence(s.top())) {
                postfix += s.pop();
            }
            s.push(ch);
        }

        cout << left << setw(18) << ch 
             << setw(15) << s.getStackContent() 
             << postfix << "\n";
    }

    while (!s.isEmpty()) {
        postfix += s.pop();
        cout << left << setw(18) << "End (Pop All)" 
             << setw(15) << s.getStackContent() 
             << postfix << "\n";
    }

    cout << "---------------------------------------------------\n";
    cout << "Final Postfix Expression: " << postfix << "\n\n";
}

int main() {
    string infix;
    
    cout << "Enter Infix Expression: ";
    cin >> infix; 
    
    infixToPostfix(infix);

    return 0;
}




