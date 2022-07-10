#include<stdio.h>
#include<stdlib.h>
#include<iostream>
struct Node {int data;Node* next; };

void insertHead(Node** pointerToHead, int x){
    Node* temp = new Node;
    (*temp).data = x;
    (*temp).next = *pointerToHead;
    *pointerToHead = temp;
}   

void printSignal(Node* head){
    while(head != NULL){
        std::cout<<(*head).data<<std::endl;
        head = (*head).next;
    }
}

int main(int argc, char *argv[]) {
    int n, x, i;
    Node* head = NULL;
    std::cout << "Enter the length of signal :" << std::endl;
    std::cin >> n;
    for(int i; i<n; i++){
        std::cout << "Enter the sample : " << std::endl;
        std::cin >> x;
        insertHead(&head, x);
    }
    printSignal(head);

    return 0;
}





