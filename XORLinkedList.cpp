#include <bits/stdc++.h>
#include <inttypes.h>
#include <iostream>
using namespace std;
class Node{
        public:
        int data;
        Node* npx;
};

Node* XOR(Node *p,Node *q){
    return (Node* )((uintptr_t)p ^ (uintptr_t)q);
}

void insert(Node** head_ref,int data){
    Node* new_node = new Node();
    new_node->data = data;

    new_node->npx = XOR(NULL,*head_ref);

    if(*head_ref!=NULL){
        Node* next = XOR((*head_ref)->npx,NULL);
        (*head_ref)->npx = XOR(new_node,next);
    }
    *head_ref = new_node;
}

void printList(Node* head){
Node* curr = head;
Node* prev = NULL;
Node* next;
    while(curr!=NULL){
        cout<<curr->data<<" ";
        next = XOR(prev,curr->npx);
        prev = curr;
        curr = next;
    }
}

void printListReverse(Node* tail){
Node* curr = tail;
Node* next = NULL;
Node* prev;
    while(curr!=NULL){
        cout<<curr->data<<" ";
        prev = XOR(next,curr->npx);
        next = curr;
        curr = prev;
    }
}

void insertAtEnd(Node** tail_ref,int data){
Node* new_node = new Node();
new_node->data = data;
new_node->npx = XOR(*tail_ref,NULL);
    if(*tail_ref!=NULL){
        Node* prev = XOR(NULL,(*tail_ref)->npx);
        (*tail_ref)->npx = XOR(prev,new_node);
    }
    *tail_ref = new_node;
}
int main(){
    Node* head = NULL;
    insert(&head,5);
    Node* tail = head;
    insert(&head,4);
    insert(&head,3);
    insert(&head,2);
    insert(&head,1);
    insertAtEnd(&tail,6);
    insertAtEnd(&tail,7);
    printList(head);
    cout<<endl;
    printListReverse(tail);
    return 0;
}
