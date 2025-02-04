#include <stdio.h>
#include <stdlib.h>

struct dequeue {
    int *arr;
    int front;
    int rear;
    int size;
};

typedef struct dequeue DQ;

void ins_rear(DQ *dq) {
    if ((dq->rear + 1) % dq->size == dq->front) {  // Check if the queue is full
        // Double the size of the array
        int n = dq->size;
        dq->size = dq->size * 2;
        dq->arr = (int *)realloc(dq->arr, dq->size * sizeof(int));

        if (dq->arr == NULL) {
            printf("\nMemory allocation failed");
            exit(0);
        }
        printf("\nReallocated successfully");

        if (dq->front > dq->rear) {
            for (int i = 0; i < dq->front; i++) {
                dq->arr[i + n] = dq->arr[i];  // Move wrapped elements to the new position
            }
            dq->rear = dq->front + n - 1;
        }
    }
    if (dq->front == -1) {
        dq->front = dq->rear = 0;
        printf("\nEnter item to be inserted: ");
        int item;
        scanf("%d", &item);
        dq->arr[dq->rear] = item;
        return;
    }
    printf("\nEnter item to be inserted: ");
    int item;
    scanf("%d", &item);
    dq->rear = (dq->rear + 1) % dq->size;
    dq->arr[dq->rear] = item;
}

void del_front(DQ *dq) {
    if (dq->front == -1) {
        printf("\nQueue empty\n");
        return;
    }
    if (dq->front == dq->rear) {
        dq->front = dq->rear = -1;
    } else {
        dq->front = (dq->front + 1) % dq->size;
    }
}

void del_rear(DQ *dq) {
    if (dq->rear == -1) {
        printf("\nQueue empty\n");
        return;
    }
    if (dq->front == dq->rear) {
        dq->front = dq->rear = -1;
    } else {
        dq->rear = (dq->rear - 1 + dq->size) % dq->size;
    }
}

void ins_front(DQ *dq) {
    if ((dq->front - 1 + dq->size) % dq->size == dq->rear) {  // Check if the queue is full
        // Double the size of the array
        int n = dq->size;
        dq->size = dq->size * 2;
        dq->arr = (int *)realloc(dq->arr, dq->size * sizeof(int));

        if (dq->arr == NULL) {
            printf("\nMemory allocation failed");
            exit(0);
        }
        printf("\nReallocated successfully");

        if (dq->front > dq->rear) {
            for (int i = 0; i < dq->front; i++) {
                dq->arr[i + n] = dq->arr[i];  // Move wrapped elements to the new position
            }
            dq->rear = dq->front + n - 1;
        }
    }
    if (dq->front == -1) {
        dq->front = dq->rear = 0;
        printf("\nEnter item to be inserted: ");
        int item;
        scanf("%d", &item);
        dq->arr[dq->front] = item;
        return;
    }
    printf("\nEnter the item to be inserted: ");
    int item;
    scanf("%d", &item);
    dq->front = (dq->front - 1 + dq->size) % dq->size;
    dq->arr[dq->front] = item;
}

void display(DQ *dq) {
    if (dq->front == -1) {
        printf("\nQueue empty\n");
        return;
    }
    int i = dq->front;
    while (i != dq->rear) {
        printf("%d\t", dq->arr[i]);
        i = (i + 1) % dq->size;
    }
    printf("%d\t", dq->arr[i]);
}

void que_front(DQ *dq) {
    if (dq->front == -1) {
        printf("\nQueue empty\n");
        return;
    }
    printf("Queue front: %d\n", dq->arr[dq->front]);
}

void que_rear(DQ *dq) {
    if (dq->rear == -1) {
        printf("\nQueue empty\n");
        return;
    }
    printf("Queue rear: %d\n", dq->arr[dq->rear]);
}

int main() {
    DQ dq;
    dq.front = dq.rear = -1;
    int choice;
    int n;
    printf("\nEnter the size of the array: ");
    scanf("%d", &n);
    dq.size = n;
    dq.arr = (int *)malloc(dq.size * sizeof(int));

    if (dq.arr == NULL) {
        printf("\nMemory allocation failed");
        exit(0);
    }

    for (;;) {
        printf("\nEnter your choice:\n");
        printf("1. Insert rear\n");
        printf("2. Insert front\n");
        printf("3. Delete front\n");
        printf("4. Delete rear\n");
        printf("5. Display\n");
        printf("6. Queue front\n");
        printf("7. Queue rear\n");
        printf("8. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                ins_rear(&dq);
                break;
            case 2:
                ins_front(&dq);
                break;
            case 3:
                del_front(&dq);
                break;
            case 4:
                del_rear(&dq);
                break;
            case 5:
                display(&dq);
                break;
            case 6:
                que_front(&dq);
                break;
            case 7:
                que_rear(&dq);
                break;
            case 8:
                free(dq.arr);
                exit(0);
            default:
                printf("\nInvalid choice\n");
        }
    }

    return 0;
}
