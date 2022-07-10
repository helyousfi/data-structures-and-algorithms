#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node* head;

void Insert(x){
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    (*temp).data = x;
    (*temp).next = head;
    head = temp;
}

void printList(){
    struct Node* temp = head;
    while(temp != NULL){
        printf("%d \n",(*temp).data);
        temp = (*temp).next;
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
        Insert(x);
        printList();
    }
    return 0;
}