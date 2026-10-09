#include <stdio.h>
#include <stdlib.h>
#define MAX 5

int queue[MAX];
int front = -1;
int rear = -1;

void insert(int value) {
    if (rear == MAX - 1) {
        printf("Overflow\n", value);
        return;
    }
    if (front == -1) front = 0;
    rear++;
    queue[rear] = value;
    printf("Inserted element: %d\n", value);
}
void deleteit() {
    if (front == -1 || front > rear) {
        printf("Underflow\n");
        return;
    }
    printf("Deleted value: %d\n", queue[front]);
    front++;
    if (front > rear) {
        front = rear = -1;
    }
}


void display() {
    if (front == -1 || front > rear) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main() {
    int choice;
    int value;
    int running = 1;
    printf("--- Simple Queue Interface ---\n");

    while (running) {
        printf("\n1. Insert \n2. Delete\n3. Display\n4. Exit\n");
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter an integer to enqueue: ");
                if (scanf("%d", &value) != 1) {
                    printf("Invalid integer entry.\n");
                    while (getchar() != '\n');
                } else {
                    insert(value);
                }
                break;

            case 2:
                deleteit();
                break;

            case 3:
                display();
                break;

            case 4:
                printf("Exiting program. Goodbye!\n");
                running = 0;
                break;

            default:
                printf("Unknown selection! Please pick an option between 1 and 4.\n");
                break;
        }
    }

    return 0;
}
