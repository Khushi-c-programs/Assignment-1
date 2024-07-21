#include <stdio.h>

#define MAX 100 // Define maximum size of stack

int stack[MAX], top = -1, n, x, i;

void push(void);
void pop(void);
void display(void);

int main() 
{
    int choice;

    printf("\n Enter the size of STACK ((MAX=100)%d): ", MAX);
    scanf("%d", &n);

    printf("\n\t STACK OPERATIONS USING ARRAY");
    printf("\n\t-----------------------------");
    printf("\n\t 1. PUSH\n\t 2. POP\n\t 3. DISPLAY\n\t 4. EXIT");

    do 
    {
        printf("\n Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) 
        {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("\n\t Exiting...");
                break;
            default:
                printf("\n\t Invalid choice. Please enter 1, 2, 3, or 4.");
        }
    } 
    while (choice != 4);

    return 0;
}

// Function to push an element onto the stack
void push() 
{
    if (top >= n - 1) 
    {
        printf("\n\t Stack overflow. Unable to push %d\n", x);
    } 
    else 
    {
        printf(" Enter a value to be pushed: ");
        scanf("%d", &x);
        top++;
        stack[top] = x;
        printf("\n\t %d pushed to stack\n", x);
    }
}

// Function to pop an element from the stack
void pop() 
{
    if (top <= -1) 
    {
        printf("\n\t Stack underflow. No elements to pop\n");
    } 
    else 
    {
        printf("\n\t The popped element is %d\n", stack[top]);
        top--;
    }
}

// Function to display the elements of the stack
void display() 
{
    if (top >= 0) 
    {
        printf("\n\t Elements in stack:\n");
        for (i = top; i >= 0; i--) 
        {
            printf("\t%d\n", stack[i]);
        }
    } 
    else 
    {
        printf("\n\t The stack is empty\n");
    }
}
