#include <stdio.h>
#include <stdlib.h>
#define MAX 10

// Function prototypes
void create();
void insert();
void deletion();
void search();
void display();

// Global variables
int b[MAX], n = 0;

int main() {
    int ch;
    char g = 'y';

    do {
        printf("\nMain Menu");
        printf("\n1. Create \n2. Delete \n3. Search \n4. Insert \n5. Display \n6. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        // Switch statement to call the appropriate function based on user input
        switch(ch) {
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
                exit(0);
            default:
                printf("\nEnter the correct choice:");
        }

        printf("\nDo you want to continue (y/n)? ");
        scanf(" %c", &g);
    } while(g == 'y' || g == 'Y');

    return 0;
}

void create() {
    printf("\nEnter the number of elements: ");
    scanf("%d", &n);

    if (n > MAX) {
        printf("\nNumber of elements exceeds the maximum limit of %d\n", MAX);
        n = 0; // Reset n to 0 if it exceeds the limit
        return;
    }

    for(int i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &b[i]);
    }
}

void deletion() {
    if (n == 0) {
        printf("\nThe list is empty.\n");
        return;
    }

    int pos;
    printf("\nEnter the position to delete: ");
    scanf("%d", &pos);

    if (pos >= n || pos < 0) {
        printf("\nInvalid position.\n");
        return;
    }

    for(int i = pos; i < n - 1; i++) {
        b[i] = b[i + 1];
    }
    n--;

    printf("\nThe elements after deletion:\n");
    display();
}

void search() {
    if (n == 0) {
        printf("\nThe list is empty.\n");
        return;
    }

    int e;
    printf("\nEnter the element to be searched: ");
    scanf("%d", &e);

    for(int i = 0; i < n; i++) {
        if(b[i] == e) {
            printf("Value %d is at position %d\n", e, i);
            return;
        }
    }
    printf("Value %d is not in the list.\n", e);
}

void insert() {
    if (n == MAX) {
        printf("\nThe list is full.\n");
        return;
    }

    int pos, p;
    printf("\nEnter the position to insert: ");
    scanf("%d", &pos);

    if(pos > n || pos < 0) {
        printf("\nInvalid position.\n");
        return;
    }

    for(int i = n; i > pos; i--) {
        b[i] = b[i - 1];
    }

    printf("Enter the element to insert: ");
    scanf("%d", &p);

    b[pos] = p;
    n++;

    printf("\nThe list after insertion:\n");
    display();
}

void display() {
    if (n == 0) {
        printf("\nThe list is empty.\n");
        return;
    }

    printf("\nThe elements of the list ADT are:\n");
    for(int i = 0; i < n; i++) {
        printf("%d ", b[i]);
    }
    printf("\n");
}

