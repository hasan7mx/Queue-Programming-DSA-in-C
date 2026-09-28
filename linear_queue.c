#include <stdio.h>

#define MAX 100

int queue[MAX];
int front = -1, rear = -1;

void insert(int value) {
    if (rear == MAX - 1) {
        printf("Queue Overflow\n");
        return;
    }

    if (front == -1)
        front = 0;

    queue[++rear] = value;
}

void delete() {
    if (front == -1 || front > rear) {
        printf("Queue Underflow\n");
        return;
    }

    printf("Deleted: %d\n", queue[front++]);

    if (front > rear)
        front = rear = -1;
}

void display() {
    if (front == -1) {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue: ");
    for (int i = front; i <= rear; i++)
        printf("%d ", queue[i]);

    printf("\n");
}

int main() {
    insert(10);
    insert(20);
    insert(30);

    delete();
    delete();

    insert(40);

    display();

    return 0;
}
