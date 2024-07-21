#include <stdio.h>

// Function to find the smallest element in the array from the given index
int smallest(int arr[], int start, int n) 
{
    int pos = start;
    for (int i = start + 1; i < n; i++) 
    {
        if (arr[i] < arr[pos]) {
            pos = i;
        }
    }
    return pos;
}

// Function to implement Selection Sort
void selection_sort(int arr[], int n) 
{
    int pos, temp;
    for (int i = 0; i < n - 1; i++) 
    {
        // Find the smallest element in the unsorted part
        pos = smallest(arr, i, n);
        // Swap the found smallest element with the current element
        temp = arr[i];
        arr[i] = arr[pos];
        arr[pos] = temp;
    }
}

// Main function to test Selection Sort
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

    selection_sort(arr, n);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) 
    {
        printf("%d ", arr[i]);
    }

    return 0;
}
