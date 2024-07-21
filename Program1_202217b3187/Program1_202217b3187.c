#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

#define MAX 10

void create();
void insert();
void deletion();
void search();
void display();

int b[20], n = 0, pos, e, i; /*a, p, f*/

void main() {
    int ch;
    char g = 'y';
    
    do 
    {
        printf("\nMain Menu");
        printf("\n1. Create\n2. Delete\n3. Search\n4. Insert\n5. Display\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        
        switch(ch) 
        {
            case 1:
                create();
                break;
            case 2:
                deletion();
                break;
            case 3:
                search();
                break;
            case 4:
                insert();
                break;
            case 5:
                display();
                break;
            case 6:
                exit(0); /* 0 */
            default:
                printf("Enter the correct choice.\n"); /*\n*/
        }
        
        printf("Do you want to continue (y/n)? ");
        scanf(" \n %c", &g);
        
    } while(g == 'y' || g == 'Y');
    getch(); /*thisssssss*/
}

void create() 
{
    printf("Enter the number of elements: "); /*\n*/
    scanf("%d", &n);
    
    if(n > MAX) {
        printf("Maximum limit exceeded.\n");
        n = 0;
        return;
    }
    
    for(i = 0; i < n; i++) 
    {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &b[i]);
    }
}

void deletion() 
{
    if(n == 0) 
    {
        printf("List is empty.\n");
        return;
    }
    
    printf("Enter the position to delete: ");
    scanf("%d", &pos);
    
    if(pos < 1 || pos > n) 
    {
        printf("Invalid position.\n");
    } else 
    {
        for(i = pos - 1; i < n - 1; i++) 
        {
            b[i] = b[i + 1];
        }
        n--;
        printf("Element deleted.\n");
    }
    
    display();
}

void search() 
{
    if(n == 0) 
    {
        printf("List is empty.\n");
        return;
    }
    
    printf("Enter the element to search: ");
    scanf("%d", &e);
    
    for(i = 0; i < n; i++) 
    {
        if(b[i] == e) 
        {
            printf("Element %d found at position %d.\n", e, i + 1);
            return;
        }
    }
    
    printf("Element %d not found in the list.\n", e);
}

void insert() 
{
    if(n == MAX) 
    {
        printf("List is full.\n");
        return;
    }
    
    printf("Enter the position to insert: ");
    scanf("%d", &pos);
    
    if(pos < 1 || pos > n + 1) 
    {
        printf("Invalid position.\n");
    } else 
    {
        for(i = n; i >= pos; i--) 
        {
            b[i] = b[i - 1];
        }
        
        printf("Enter the element to insert: ");
        scanf("%d", &e);
        b[pos - 1] = e;
        n++;
        printf("Element inserted.\n");
    }
    
    display();
}

void display() 
{
    if(n == 0) 
    {
        printf("List is empty.\n");
        return;
    }
    
    printf("The elements of the list are: ");
    for(i = 0; i < n; i++) 
    {
        printf("%d ", b[i]);
    }
    printf("\n");
}
