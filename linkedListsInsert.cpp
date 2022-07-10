#include<iostream>
#include<stdlib.h>
#include<stdio.h>

struct Node{int data; Node* next;};
Node* head;

void printList(Node* head){
    std::cout << "The list is : " << std::endl;
    while(head != NULL){
        std::cout << head->data << " ";
        head = head->next;
    }
}


void insertElement(int x, int position)
{
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

    return 0;
}

