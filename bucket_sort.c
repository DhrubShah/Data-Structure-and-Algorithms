#include <stdio.h>
#include <stdlib.h>

// A linked list node
struct Node {
    float data;
    struct Node* next;
};

// Function to create a new linked list node
struct Node* createNode(float data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node into a sorted linked list
void sortedInsert(struct Node** head, struct Node* newNode) {
    struct Node* current;
    if (*head == NULL || (*head)->data >= newNode->data) {
        newNode->next = *head;
        *head = newNode;
    } else {
        current = *head;
        while (current->next != NULL && current->next->data < newNode->data) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

// Function to perform bucket sort
void bucketSort(float arr[], int n) {
    // Create an array of linked lists (buckets)
    struct Node** buckets = (struct Node**)malloc(n * sizeof(struct Node*));
    for (int i = 0; i < n; i++) {
        buckets[i] = NULL;
    }

    // Insert elements into their respective buckets
    for (int i = 0; i < n; i++) {
        int bucketIndex = (int)(arr[i] * n);
        struct Node* newNode = createNode(arr[i]);
        sortedInsert(&buckets[bucketIndex], newNode);
    }

    // Concatenate all buckets into arr[]
    int index = 0;
    for (int i = 0; i < n; i++) {
        struct Node* node = buckets[i];
        while (node != NULL) {
            arr[index++] = node->data;
            struct Node* temp = node;
            node = node->next;
            free(temp);
        }
    }

    // Free allocated memory for buckets
    free(buckets);
}

// Function to print an array
void printArray(float arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%f ", arr[i]);
    }
    printf("\n");
}

int main() {
    float arr[] = {0.897, 0.565, 0.656, 0.1234, 0.665, 0.3434};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Given array is \n");
    printArray(arr, n);

    bucketSort(arr, n);

    printf("\nSorted array is \n");
    printArray(arr, n);

    return 0;
}
