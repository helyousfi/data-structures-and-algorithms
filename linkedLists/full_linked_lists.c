#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
}*first=NULL;

// Create from an array
void create(int A[], int n)
{
    struct Node *temp, *last;
    first = (struct Node*)malloc(sizeof(struct Node));
    first->data = A[0];
    first->next = NULL;
    last = first;
    for(int i=1; i<n; i++){
        temp = (struct Node*)malloc(sizeof(struct Node));
        temp->data = A[i];
        temp->next = NULL;
        last->next = temp;
        last = temp;
    }
}

// Display
void Display(struct Node* p)
{
    while(p!=NULL)
    {
        printf("%d", p->data);
        p=p->next;
    }
}
 
// Recursive Display
void Display_recursive(struct Node* p)
{
    if(p!=NULL)
    {
        printf("%d", p->data);
        Display(p->next);
    }
}

// Count the Nodes in a linked list
int count(struct Node *p)
{
    int c = 0;
    while(p!=NULL){
        p = p->next;
        c++;
    }
    return c;
}

// Count the Nodes in a linked list recursively
// Time O(n) space O(n)
int count_recursive(struct Node *p)
{
    if(p!=NULL){
        return count_recursive(p->next)+1;
    }
    return 0;
}

// Sum of elements
int sum(struct Node* p)
{
    int sum = 0;
    while(p!=NULL)
    {
        sum = sum + p->data;
        p = p->next;
    }
    return sum;
}

// Sum of elements recursion
int sum_recursive(struct Node *p)
{
    if(p==NULL){
        return 0;
    }
    return sum_recursive(p->next) + p->data;
}



int main()
{
    int A[] = {4, 5, 8, 1, 6, 20};
    int n = 6;
    create(A, n);
    Display_recursive(first);
    printf("sum is %d", sum_recursive(first));
    return 0;
}