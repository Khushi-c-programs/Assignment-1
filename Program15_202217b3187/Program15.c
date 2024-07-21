#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Linked List node
struct node 
{
    char* key;      // key is a string
    char* value;    // value is also a string
    struct node* next;
};

// Like constructor for node
void setNode(struct node* node, char* key, char* value) 
{
    node->key = strdup(key);    // Use strdup to duplicate the string
    node->value = strdup(value);
    node->next = NULL;
}

// Hash Map structure
struct hashMap 
{
    int numOfElements;  // Current number of elements in hashMap
    int capacity;       // Capacity of hashMap
    struct node** arr;  // Array of linked list to hold base address
};

// Like constructor for hashMap
void initializeHashMap(struct hashMap* mp) 
{
    mp->capacity = 100;  // Default capacity
    mp->numOfElements = 0;
    mp->arr = (struct node**)calloc(mp->capacity, sizeof(struct node*));  // Allocate and initialize array
}

// Hash function to calculate bucket index
int hashFunction(struct hashMap* mp, char* key) 
{
    int sum = 0, factor = 31;
    for (int i = 0; i < strlen(key); i++) 
    {
        sum = ((sum % mp->capacity) + (((int)key[i]) * factor) % mp->capacity) % mp->capacity;
        factor = ((factor % __INT16_MAX__) * (31 % __INT16_MAX__)) % __INT16_MAX__;
    }
    return sum;
}

// Function to insert key-value pair
void insert(struct hashMap* mp, char* key, char* value) 
{
    int bucketIndex = hashFunction(mp, key);
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    setNode(newNode, key, value);
    if (mp->arr[bucketIndex] == NULL) 
    {
        mp->arr[bucketIndex] = newNode;
    } 
    else 
    {
        newNode->next = mp->arr[bucketIndex];
        mp->arr[bucketIndex] = newNode;
    }
    mp->numOfElements++;
}

// Function to delete a key-value pair
void deleteKey(struct hashMap* mp, char* key) 
{
    int bucketIndex = hashFunction(mp, key);
    struct node* prevNode = NULL;
    struct node* currNode = mp->arr[bucketIndex];
    while (currNode != NULL) 
    {
        if (strcmp(key, currNode->key) == 0) 
        {
            if (currNode == mp->arr[bucketIndex]) 
            {
                mp->arr[bucketIndex] = currNode->next;
            } 
            else 
            {
                prevNode->next = currNode->next;
            }
            free(currNode->key);
            free(currNode->value);
            free(currNode);
            mp->numOfElements--;
            return;
        }
        prevNode = currNode;
        currNode = currNode->next;
    }
}

// Function to search for a value by key
char* search(struct hashMap* mp, char* key) 
{
    int bucketIndex = hashFunction(mp, key);
    struct node* bucketHead = mp->arr[bucketIndex];
    while (bucketHead != NULL) 
    {
        if (strcmp(bucketHead->key, key) == 0) 
        {
            return bucketHead->value;
        }
        bucketHead = bucketHead->next;
    }
    return "Oops! No data found.\n";
}

// Drivers code
int main() 
{
    struct hashMap* mp = (struct hashMap*)malloc(sizeof(struct hashMap));
    initializeHashMap(mp);

    insert(mp, "Yogaholic", "Anjali");
    insert(mp, "pluto14", "Vartika");
    insert(mp, "elite_Programmer", "Manish");
    insert(mp, "GFG", "BITS");
    insert(mp, "decentBoy", "Mayank");

    printf("%s\n", search(mp, "elite_Programmer"));
    printf("%s\n", search(mp, "Yogaholic"));
    printf("%s\n", search(mp, "pluto14"));
    printf("%s\n", search(mp, "decentBoy"));
    printf("%s\n", search(mp, "GFG"));
    printf("%s\n", search(mp, "randomKey"));

    printf("\nAfter deletion : \n");
    deleteKey(mp, "decentBoy");
    printf("%s\n", search(mp, "decentBoy"));

    // Free allocated memory
    for (int i = 0; i < mp->capacity; i++) 
    {
        struct node* currNode = mp->arr[i];
        while (currNode != NULL) 
        {
            struct node* nextNode = currNode->next;
            free(currNode->key);
            free(currNode->value);
            free(currNode);
            currNode = nextNode;
        }
    }
    free(mp->arr);
    free(mp);

    return 0;
}
