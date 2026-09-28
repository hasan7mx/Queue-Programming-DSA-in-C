#include <stdio.h>

#define SIZE 100

struct Element {
    int value;
    int priority;
};

struct Element queue[SIZE];
int count = 0;

void insert(int value, int priority) {
    if (count == SIZE) {
        printf("Priority Queue Overflow\n");
        return;
    }

    queue[count].value = value;
    queue[count].priority = priority;
    count++;
}

void deleteHighestPriority() {
    if (count == 0) {
        printf("Priority Queue is empty\n");
        return;
    }

    int index = 0;

    for (int i = 1; i < count; i++) {
        if (queue[i].priority < queue[index].priority) {
            index = i;
        }
    }

    printf("Deleted: %d (Priority %d)\n",
           queue[index].value,
           queue[index].priority);

    for (int i = index; i < count - 1; i++) {
        queue[i] = queue[i + 1];
    }

    count--;
}

void display() {
    if (count == 0) {
        printf("Priority Queue is empty\n");
        return;
    }

    printf("Priority Queue:\n");

    for (int i = 0; i < count; i++) {
        printf("Value: %d, Priority: %d\n",
               queue[i].value,
               queue[i].priority);
    }
}

int main() {
    insert(10, 2);
    insert(20, 1);
    insert(30, 3);

    deleteHighestPriority();

    display();

    return 0;
}
