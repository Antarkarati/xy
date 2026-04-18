#include <bits/stdc++.h>
using namespace std;
const int MX = 100;
//string arr[MX];

struct Node {
    int data ;
    Node* next;

    Node(int v) {
        data = v;
        next = NULL;
    }
};

void display(Node* &head) {
    Node* tmp = head;

    while(tmp != NULL) {
        cout<<tmp -> data <<" ";
        tmp = tmp -> next;
    }
}

void insertAtFront(Node* &head,int v) {
    Node* new_node = new Node(v);
    new_node -> next = head -> next;
    head = new_node;
}
void insertAtLast(Node* &head, int v) {
    if(head == NULL) insertAtFront(head, v);
    else {
        Node* new_node = new Node(v);
        Node* tmp = head;
        while(tmp -> next != NULL) tmp = tmp -> next;
        tmp -> next = new_node;
    }
}

void insertByPosition(Node* &head, int p, int v) {
    if(head == NULL) {
        cout<<"Invalid position\n";
        return;
    }

    Node* new_node = new Node(v);
    Node* tmp = head;
    int i = 1;

    while(tmp -> next != NULL && i < p-1) {
        tmp = tmp -> next;
        i++;
    }

    if(tmp -> next == NULL) {
        cout<<"NOT FOUND\n";
        return ;
    }

    new_node -> next = tmp -> next;
    tmp -> next = new_node;
}

void deleteAtFront(Node* &head) {
    if(head == NULL) return ;
    else {
        Node* tmp = head;
        head = head -> next;
        delete(tmp);
    }
}

void deleteAtLast(Node* & head) {
    if(head == NULL) return;
    if(head -> next == NULL) deleteAtFront(head);
    else {
        Node* tmp = head;
        while(tmp -> next -> next != NULL) {
            tmp = tmp -> next;
        }
        Node* x = tmp -> next;
        tmp -> next = NULL;
        delete(x);
    }
}

void deleteByValue(Node* &head, int v) {
    if(head == NULL) return;
    if(head -> data == v) deleteAtFront(head);
    else {
        Node* tmp = head;
        while(tmp -> next != NULL && tmp -> next -> data != v) {
            tmp = tmp -> next;
        }
        if(tmp -> next == NULL) {
            cout<<"NOT FOUND\n";
            return;
        }
        Node* x = tmp -> next;
        tmp -> next = tmp -> next -> next;
        delete(x);
    }
}

void bubble_sort(Node* &head) {

    while(true) {
        bool  b = true;
        Node* tmp = head;

        while(tmp -> next != NULL) {

            if(tmp -> data > tmp -> next -> data) {
                int x = tmp -> data;
                tmp -> data = tmp -> next -> data;
                tmp -> next -> data = x;
                b = false;
            }
            tmp = tmp -> next;
        }

        if(b) break;

    }
}

void Solve() {
      int arr[]  = {5, 3, 9, 42, 0, 10};

      int  n = sizeof(arr) / sizeof(arr[0]);

      Node* head = NULL;
      Node* prev = NULL;

      for(int i=0; i<n; i++) {
          Node* new_node = new Node(arr[i]);

          if(head == NULL) head = new_node;
          else prev -> next = new_node;

          prev = new_node;
      }


    insertAtFront(head, 10);
    insertAtLast(head, 20);
    insertByPosition(head,3,50);

    deleteAtFront(head);
    deleteAtLast(head);
    deleteByValue(head, 9);

    bubble_sort(head);





    display(head);




}

int main() {
  //  freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    Solve();
}