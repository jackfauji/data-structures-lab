#include <stdio.h>
#include <limits.h>

#define MAX 10

int enq(int pq[], int *r);
void deq(int pq[], int *r);
void displayQueue(int pq[], int r);

int main() {
    int pq[MAX], ch, r = 0;

    // Initialize the priority queue array with a default value
    for (int i = 0; i < MAX; i++) {
        pq[i] = INT_MAX;
    }

    do {
        printf("\nEnter choice\n");
        printf("1. Enqueue    2. Dequeue   3. Display Queue   4. Exit\n");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                r = enq(pq, &r);
                break;
            case 2:
                deq(pq, &r);
                break;
            case 3:
                displayQueue(pq, r);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    } while (ch != 4);

    return 0;
}

int enq(int pq[], int *r) {
    int p, data;

    if (*r >= MAX - 1) {  // Checking if there is enough space for new element
        printf("Overflow\n");
        return *r;
    }

    printf("Enter priority and data: ");
    scanf("%d%d", &p, &data);

    pq[*r] = p;
    pq[*r + 1] = data;
    *r += 2;  // Update the index for the next insertion

    return *r;
}

void deq(int pq[], int *r) {
    if (*r == 0) {
        printf("Underflow\n");
        return;
    }

    int i, j, min = INT_MAX;

    // Finding the minimum priority
    for (i = 0; i < *r; i += 2) {
        if (pq[i] < min) {
            min = pq[i];
            j = i;
        }
    }

    // If we have found a valid minimum priority
    if (min != INT_MAX) {
        printf("Priority %d data has been dequeued: %d\n", min, pq[j + 1]);

        // Removing the element by shifting
        for (i = j; i < *r - 2; i += 2) {
            pq[i] = pq[i + 2];
            pq[i + 1] = pq[i + 3];
        }
        
        *r -= 2;  // Update the size of the queue
    }
}

void displayQueue(int pq[], int r) {
    int i, j, min, tempPriority, tempData;

    if (r == 0) {
        printf("Queue is empty.\n");
        return;
    }

    // Sort the queue based on priority
    for (i = 0; i < r; i += 2) {
        for (j = i + 2; j < r; j += 2) {
            if (pq[i] > pq[j]) {
                // Swap priorities
                tempPriority = pq[i];
                pq[i] = pq[j];
                pq[j] = tempPriority;

                // Swap corresponding data
                tempData = pq[i + 1];
                pq[i + 1] = pq[j + 1];
                pq[j + 1] = tempData;
            }
        }
    }

    // Print sorted queue
    printf("Priority Queue:\n");
    for (i = 0; i < r; i += 2) {
        printf("Priority: %d, Data: %d\n", pq[i], pq[i + 1]);
    }
}
