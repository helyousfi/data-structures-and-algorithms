// Linked Lists in C language 

#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

// Declare the head as global variable
struct Node* head;

void insertBegin(int x){
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    (*temp).data = x;
    (*temp).next = head;
    head = temp;
}


void printList(){
    struct Node* temp = head;
    int index = 0;
    while(temp != NULL){
        printf("Node %d : \n", index);
        printf("Current : %x \n", temp);
        printf("%d -> %x  \n",(*temp).data,(*temp).next);
        printf("\n");        
        temp = (*temp).next;
        index++;
    }
}

int main(){
    int n, x, i;
    // Create the head
    head = NULL;
    printf("Enter the number of Nodes : ");
    scanf("%d", &n);
    for(i=0; i<n; i++){
        printf("Enter the number : ");
        scanf("%d", &x);
        insertBegin(x);
    }
    printList();
    return 0;
}