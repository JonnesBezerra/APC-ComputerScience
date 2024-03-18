#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 50

// Structure to represent a queue element
typedef struct {
    int data;
} Node;

// Structure to represent the queue
typedef struct {
    Node* items[MAX_SIZE];
    int front, rear;
} Queue;

// Function to create a new queue
Queue* createQueue() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->front = -1;
    queue->rear = -1;
    return queue;
}

// Function to check if the queue is empty
int isEmpty(Queue* queue) { return queue->front == -1; }

// Function to check if the queue is full
int isFull(Queue* queue) { return queue->rear == MAX_SIZE - 1; }

// Function to enqueue an element
void enqueue(Queue* queue, int data) {
    if (isFull(queue)) {
        printf("Queue overflow\n");
        return;
    }
    if (queue->front == -1) {
        queue->front = 0;
    }
    queue->rear++;

    // Create a new Node object
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;

    // Assign the Node object to the queue's items array
    queue->items[queue->rear] = newNode;
}

// Function to dequeue an element
int dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue underflow\n");
        return -1;
    }
    int data = queue->items[queue->front]->data;
    if (queue->front == queue->rear) {
        queue->front = queue->rear = -1;
    } else {
        queue->front++;
    }
    return data;
}

void discardAndMove(Queue* queue) {
    int discarded = dequeue(queue);
    printf("%d, ", discarded);
    enqueue(queue, dequeue(queue));
}

int main() {
    int n;

    while (scanf("%d", &n) != EOF && n != 0) {
        printf("Discarded cards: ");

        // Create a queue for the cards
        Queue* queue = createQueue();

        // Enqueue cards from 1 to n
        for (int i = 1; i <= n; i++) {
            enqueue(queue, i);
        }

        // Perform operations until one card remains
        while (queue->rear > 0) {
            discardAndMove(queue);
        }

        printf("\nRemaining card: %d\n\n", dequeue(queue));

        // Free the queue memory
        free(queue);
    }

    return 0;
}
