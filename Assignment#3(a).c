#include <stdio.h>

int top(int *stack,int top_index)
{
    if (top_index == -1)
    {
        return -1;                     //return -1 in case of empty stack 
    }
    else
        return stack[top_index];      //return top element of the stack
}

void Push(int *stack, int num, int top_index)
{
    top_index++;                  //initially it was pointing to the top element of the stack, for pushing a new element we must first increase it
    stack[top_index] = num;
}

int pop(int *stack, int top_index)
{
    if (top_index == -1)
    {
        return -1;
    }
    else
    {
        return stack[top_index--]; //returning the top element and lowering the top pointer
    }
}

int size(int *stack,int top_index)
{
    return top_index + 1;               // since it is 0 indexed array 
}

int main()
{
    int n;
    scanf("%d", &n);
    int stack[n];
    int top_index = -1;      //this is the index of top element, initially it is -1 we will increase it before each insertion so that when we need it, it will point  
                            // to the top element of the stack

    for (int i = 0; i < n; i++)
    {
        int request;                
        int a;
        scanf("%d", &request);         //taking the input and push it in the stack
        if (request == 0)
        {

            scanf(" %d\n", &a);
            
            Push(stack, a, top_index);
        }
        else if (request == 1)
        {
            a = pop(stack,top_index);            // it will take the top value lower the pointer which points to the top of the stack i.e., pop
            if (a == -1)
            {
                printf("!\n");        // -1 indicates empty stack
            }
            else
            {
                printf("%d\n", a);
            }
        }
        else if (request== 2)
        {
            a = top(stack, top_index);         // this function returns the top element of the stack passed
            if (a == -1)
            {
                printf("!\n");
            }
            else
            {
                printf("%d\n", a);
            }
        }
        else if (request == 3)        //returning the size of stack
        {
            printf("%d\n", size(stack, top_index));
        }
    }
    return 0;
}