#include<iostream>
#include<stdlib.h>
#include<stdio.h>

struct Node{int data; Node* next;};
Node* head;

void printList(Node* head){
    std::cout << "The list is : " << std::endl;
    while(head != NULL){
        std::cout << head->data << " ";
        std::cout << "\n";
        head = head->next;
    }
}

void printRecursive(Node* p){
    if(p==NULL){return;}
    std::cout << p->data << std::endl;
    printRecursive(p->next);
}

void Reverse(){
    Node *prev, *current, *next;
    current = head;
    prev = NULL;
    while(current != NULL){ 
        next = current->next;
        current->next = prev;
        prev = current;
        current = next; 
    }
    head = prev;
}

void Delete(int n){
    Node* temp1 = head;
    if(n==1){
        head = temp1->next,
        delete temp1;
        return;
    }
    int i;
    for(i=0; i<n-2; i++){
        temp1 = temp1 -> next;
    }
    Node* temp2 = temp1->next;
    temp1->next = temp2->next;
    delete temp2;
}

void insertElement(int x, int position){
    Node* temp = new Node();
    temp->data = x;

    if(position == 1) {
        temp->next = head;
        head = temp;
    }
    else{
        Node* tempHead = head;
        for(int i=0; i<position-2; i++){
            tempHead = tempHead->next;
        }
        temp->next = tempHead->next;
        tempHead->next = temp;
    }
}


int main(){
    head = NULL;

    insertElement(4, 1);
    insertElement(5, 2);
    insertElement(3, 3);
    insertElement(2, 4);
 
    printList(head);

    Delete(1);

    printList(head);
    
    Reverse();
    
    printList(head);
    
    std::cout << "The list is (recursive): " << std::endl;
    printRecursive(head);
    return 0;
}

