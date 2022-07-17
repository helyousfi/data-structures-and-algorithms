#include <stdio.h>
#include <stdlib.h>
#define MIN_INT -32768
#define MAX_INT 32768

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

// Max element
int max(struct Node *p)
{
    int M = MIN_INT;
    while(p!=NULL)
    {
        if(p->data>M)
        {
            M = p->data;
        }
        p = p->next;
    }
    return M;
}

// Max recursive
int max_recursive(struct Node* p)
{
    int x;
    if(p==NULL){
        return MIN_INT;}
    x = max_recursive(p->next);
    if (p->data < x){
        return x;
    } 
    else{
        return p->data;
    }
}


// Min element
int min(struct Node *p)
{
    int M = MAX_INT;
    while(p!=NULL)
    {
        if(p->data<M)
        {
            M = p->data;
        }
        p = p->next;
    }
    return M;
}


// Search in a linked list
struct Node* search(struct Node* p, int key)
{
    while(p!=NULL){
        if(key==p->data){
            return p;
        }
        p = p->next;
    }
    return NULL;
}

// Recursive function
struct Node* search_recursive(struct Node* p, int key)
{
    if(p==NULL)
    {
        return NULL;
    }
    if(key == p->data)
    {
        return p;
    }
    return search_recursive(p->next, key);
}

 




int main()
{
    int A[] = {4, 5, 8, 1, 6, 20};
    int n = 6;
    create(A, n);
    Display_recursive(first);
    printf("\nmax_recursive is %d", search(first, 6));
    printf("\nmax_recursive is %d", search_recursive(first, 6));
    return 0;
}