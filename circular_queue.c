#include <stdio.h>

#define SIZE 5

int queue[SIZE];
int front = -1, rear = -1;

void insert(int value) {
    if ((rear + 1) % SIZE == front) {
        printf("Queue Overflow\n");
        return;
    }

    if (front == -1)
        front = 0;

    rear = (rear + 1) % SIZE;
    queue[rear] = value;
}

void delete() {
    if (front == -1) {
        printf("Queue Underflow\n");
        return;
    }

    printf("Deleted: %d\n", queue[front]);

    if (front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % SIZE;
    }
}

void display() {
    if (front == -1) {
        printf("Queue is empty\n");
        return;
    }

    printf("Circular Queue: ");

    int i = front;
    while (1) {
        printf("%d ", queue[i]);

        if (i == rear)
            break;

        i = (i + 1) % SIZE;
    }

    printf("\n");
}

int main() {
    insert(10);
    insert(20);
    insert(30);
    insert(40);

    delete();
    delete();

    insert(50);
    insert(60);

    display();

    return 0;
}
