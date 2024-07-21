#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node structure for linked list
struct node {
    char* key;
    char* value;
    struct node* next;
};

// Function to initialize a new node
void setNode(struct node* node, char* key, char* value) {
    node->key = strdup(key); // Duplicate the key to avoid issues with pointer re-use
    node->value = strdup(value); // Duplicate the value for similar reasons
    node->next = NULL;
}

// HashMap structure
struct hashMap {
    int numOfElements;
    int capacity;
    struct node** arr;
};

// Function to initialize the hash map
void initializeHashMap(struct hashMap* mp) {
    mp->capacity = 100; // Default capacity
    mp->numOfElements = 0;
    mp->arr = (struct node**)malloc(sizeof(struct node*) * mp->capacity);
    for (int i = 0; i < mp->capacity; i++) {
        mp->arr[i] = NULL;
    }
}

// Hash function to calculate the index for a given key
int hashFunction(struct hashMap* mp, char* key) {
    int sum = 0, factor = 31;
    for (int i = 0; i < strlen(key); i++) {
        sum = (sum + ((int)key[i] * factor)) % mp->capacity;
        factor = (factor * 31) % __INT16_MAX__;
    }
    return sum;
}

// Function to insert key-value pair into the hash map
void insert(struct hashMap* mp, char* key, char* value) {
    int bucketIndex = hashFunction(mp, key);
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    setNode(newNode, key, value);

    if (mp->arr[bucketIndex] == NULL) {
        mp->arr[bucketIndex] = newNode;
    } else {
        newNode->next = mp->arr[bucketIndex];
        mp->arr[bucketIndex] = newNode;
    }
    mp->numOfElements++;
}

// Function to delete a key-value pair from the hash map
void delete(struct hashMap* mp, char* key) {
    int bucketIndex = hashFunction(mp, key);
    struct node* prevNode = NULL;
    struct node* currNode = mp->arr[bucketIndex];

    while (currNode != NULL) {
        if (strcmp(key, currNode->key) == 0) {
            if (currNode == mp->arr[bucketIndex]) {
                mp->arr[bucketIndex] = currNode->next;
            } else {
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
char* search(struct hashMap* mp, char* key) {
    int bucketIndex = hashFunction(mp, key);
    struct node* bucketHead = mp->arr[bucketIndex];

    while (bucketHead != NULL) {
        if (strcmp(bucketHead->key, key) == 0) {
            return bucketHead->value;
        }
        bucketHead = bucketHead->next;
    }
    return "Oops! No data found.";
}

// Driver code
int main() {
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
    printf("%s\n", search(mp, "randomKey")); // Key is not inserted

    printf("\nAfter deletion:\n");
    delete(mp, "decentBoy");
    printf("%s\n", search(mp, "decentBoy")); // Should indicate key not found

    // Clean up
    for (int i = 0; i < mp->capacity; i++) {
        struct node* curr = mp->arr[i];
        while (curr != NULL) {
            struct node* toDelete = curr;
            curr = curr->next;
            free(toDelete->key);
            free(toDelete->value);
            free(toDelete);
        }
    }
    free(mp->arr);
    free(mp);

    return 0;
}

