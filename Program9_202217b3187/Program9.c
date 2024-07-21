#include <stdio.h> 

// Function to sort an array using insertion sort 
void insert(int a[], int n) 
{ 
    int i, j, temp; 
    for (i = 1; i < n; i++) 
    { 
        temp = a[i]; 
        j = i - 1; 

        // Moving the elements greater than temp to one position ahead from their current position
        while (j >= 0 && temp <= a[j]) 
        { 
            a[j + 1] = a[j]; 
            j = j - 1; 
        } 
        a[j + 1] = temp; 
    } 
} 
 
// Function to print the array 
void printArr(int a[], int n) 
{ 
    int i; 
    for (i = 0; i < n; i++) 
        printf("%d ", a[i]); 
    printf("\n");
} 
 
int main() 
{ 
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &arr[i]);
    }
   
    printf("Before sorting, array elements are - \n"); 
    printArr(arr, n); 
    insert(arr, n); 
    printf("After sorting, array elements are - \n"); 
    printArr(arr, n); 
    return 0; 
}
