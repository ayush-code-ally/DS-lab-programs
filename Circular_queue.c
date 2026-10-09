#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

int queue[SIZE];
int front = -1;
int rear = -1;
int isFull() {
    return ((rear + 1) % SIZE) == front;
}
int isEmpty() {
    return front == -1;
}
void insert(int value) {
    if (isFull()) {
        printf("Overflow \n");
        return;
    }
    if (front == -1) {
        front = 0;
    }
    rear = (rear + 1) % SIZE;
    queue[rear] = value;
    printf("Inserted : %d\n", value);
}
void deleteit() {
    if (isEmpty()) {
        printf("Underflow.\n");
        return;
    }

    printf("Deleted value: %d\n", queue[front]);
    if (front == rear) {
        front = -1;
        rear = -1;
    } else {
        front = (front + 1) % SIZE;
    }
}

void display() {
    if (isEmpty()) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue elements: ");
    int i = front;
    while (1) {
        printf("%d ", queue[i]);
        if (i == rear) {
            break;
        }
        i = (i + 1) % SIZE;
    }
    printf("\n");
}

int main() {
    int choice;
    int value;
    int running = 1;

    while (running) {
        printf("\n1. Insert \n2. Delete \n3. Display\n4. Exit\n");
        printf("Enter your choice (1-4): ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input! Please enter a number.\n");
            while (getchar() != '\n');
            continue;
        }

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
