#include<stdio.h>
#include<stdlib.h>
#define SIZE 5

void insert();
void delete();
void display();

int queue[SIZE], front = 0, rear = 0, ch = 1;

int main() {
    printf("Queue using Array");
    printf("\n1. Insertion \n2. Deletion \n3. Display \n4. Exit");

    while(ch) {
        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        switch(ch) {
            case 1:
                insert();
                break;
            case 2:
                delete();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Wrong Choice: please see the options");
        }
    }
    return 0;
}

void insert() {
    if(rear == SIZE) {
        printf("\nQueue is Full");
    } else {
        int value;
        printf("\nEnter value to insert: ");
        scanf("%d", &value);
        queue[rear++] = value;
        printf("\nValue inserted successfully.");
    }
}

void delete() {
    if(front == rear) {
        printf("\nQueue is Empty");
    } else {
        printf("\nDeleted Element is: %d", queue[front]);
        for(int i = 0; i < rear - 1; i++) {
            queue[i] = queue[i + 1];
        }
        rear--;
    }
}

void display() {
    if(front == rear) {
        printf("\nQueue is Empty");
    } else {
        printf("\nQueue Elements are:\n");
        for(int i = front; i < rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

