#include <stdio.h> 

/* Function to perform linear search */
int linearSearch(int arr[], int n, int target) 
{ 
    int i; 
    for (i = 0; i < n; i++) 
    { 
        if (arr[i] == target) 
        { 
            return i; // Element found at index i 
        } 
    } 
    return -1; // Element not found 
} 

int main() 
{ 
    int n, target;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &arr[i]);
    }

    printf("Enter the target element to search: ");
    scanf("%d", &target);

    // Perform linear search
    int result = linearSearch(arr, n, target); 
    if (result == -1) 
    { 
        printf("Element not found in the array.\n"); 
    } 
    else 
    { 
        printf("Element found at index: %d\n", result); 
    } 
    return 0; 
}
