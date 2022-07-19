#include <iostream>
#include <cstring>

struct stack{
    int n;      // Max size of the stack
    char* S;    // The array
    int top;    // The top
};

// Push a character to the stack
void push(stack* St, char x)
{
    if(St->top != St->n){
        St->top++;
        St->S[St->top] = x;
    }
    else{
        std::cout << "Stack overflow!" << std::endl;
    }
}

// Pop a character from the stack
int pop(stack* St){
    if(St->top == 0){
        std::cout << "Stack is empty!" << std::endl;
        return -1;
    }
    int x = St->S[St->top];
    St->top--;
    return x;
}

// Check if the stack is empty
int isEmpty(stack St)
{
    if(St.top == -1){
        return 1; 
    }
    return 0;
}

// Display the stack
void Display(stack st){
    for(int i=0; i<st.top; i++){
        std::cout << st.S[i] << std::endl;
    }
}

// Check if a string is balanced
int isBalanced(char* Str)
{
    stack st;
    st.n = strlen(Str);
    st.S = new char[st.n];
    st.top = -1;

    for(int i=0; Str[i]!='\0'; i++){
        if(Str[i] == '(')
        {
            push(&st, '(');
        }
        else if(Str[i] == ')')
        {
            if(isEmpty(st))
            {
                return 0;
            }
            pop(&st);
        }
    }
    Display(st);
    if(isEmpty(st))
    {
        return 1;
    }
    return 0;
}

int main()
{
    char S[20] = "(((a+b)(c-d))";
    std::cout << isBalanced(S) << std::endl;
    return 0;
}
