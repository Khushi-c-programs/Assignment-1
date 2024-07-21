#include <stdio.h> 

// Function to merge the subarrays of a[] 
void merge(int a[], int beg, int mid, int end) 
{ 
    int i, j, k; 
    int n1 = mid - beg + 1; 
    int n2 = end - mid; 

    int LeftArray[n1], RightArray[n2]; // Temporary arrays 

    // Copy data to temp arrays 
    for (i = 0; i < n1; i++) 
        LeftArray[i] = a[beg + i]; 
    for (j = 0; j < n2; j++) 
        RightArray[j] = a[mid + 1 + j]; 

    i = 0; // Initial index of first sub-array 
    j = 0; // Initial index of second sub-array 
    k = beg; // Initial index of merged sub-array 

    // Merge the temp arrays back into a[beg..end]
    while (i < n1 && j < n2) { 
        if (LeftArray[i] <= RightArray[j]) 
        { 
            a[k] = LeftArray[i]; 
            i++; 
        } 
        else 
        { 
            a[k] = RightArray[j]; 
            j++; 
        } 
        k++; 
    } 

    // Copy the remaining elements of LeftArray[], if there are any
    while (i < n1) 
    { 
        a[k] = LeftArray[i]; 
        i++; 
        k++; 
    } 

    // Copy the remaining elements of RightArray[], if there are any
    while (j < n2) 
    { 
        a[k] = RightArray[j]; 
        j++; 
        k++; 
    } 
} 

// Function to implement merge sort
void mergeSort(int a[], int beg, int end) 
{ 
    if (beg < end) 
    { 
        int mid = (beg + end) / 2; 
        mergeSort(a, beg, mid); 
        mergeSort(a, mid + 1, end); 
        merge(a, beg, mid, end); 
    } 
} 

// Function to print the array
void printArray(int a[], int n) 
{ 
    int i; 
    for (i = 0; i < n; i++) 
    {
        printf("%d ", a[i]); 
    }
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
    printArray(arr, n); 
    mergeSort(arr, 0, n - 1); 
    printf("After sorting, array elements are - \n"); 
    printArray(arr, n); 
    return 0; 
}