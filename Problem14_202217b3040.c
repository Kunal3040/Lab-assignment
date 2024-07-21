#include <stdio.h>

#define MAX_NODES 15

// Representation of the binary tree using an array
char tree[] = {'\0', 'D', 'A', 'F', 'E', 'B', 'R', 'T', 'G', 'Q', '\0', '\0', 'V', '\0', 'J', 'L'};

// Function to get the right child index
int get_right_child(int index) {
    if (index > 0 && (2 * index) + 1 < MAX_NODES && tree[(2 * index) + 1] != '\0')
        return (2 * index) + 1;
    return -1;
}

// Function to get the left child index
int get_left_child(int index) {
    if (index > 0 && 2 * index < MAX_NODES && tree[2 * index] != '\0')
        return 2 * index;
    return -1;
}

// Pre-order traversal
void preorder(int index) {
    if (index > 0 && tree[index] != '\0') {
        printf(" %c ", tree[index]);
        preorder(get_left_child(index));
        preorder(get_right_child(index));
    }
}

// Post-order traversal
void postorder(int index) {
    if (index > 0 && tree[index] != '\0') {
        postorder(get_left_child(index));
        postorder(get_right_child(index));
        printf(" %c ", tree[index]);
    }
}

// In-order traversal
void inorder(int index) {
    if (index > 0 && tree[index] != '\0') {
        inorder(get_left_child(index));
        printf(" %c ", tree[index]);
        inorder(get_right_child(index));
    }
}

int main() {
    printf("Preorder:\n");
    preorder(1); // Start with the root index
    printf("\nPostorder:\n");
    postorder(1); // Start with the root index
    printf("\nInorder:\n");
    inorder(1); // Start with the root index
    printf("\n");
    return 0;
}

