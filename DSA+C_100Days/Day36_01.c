#include <stdio.h>
#include <stdlib.h>

void display(int* queue, int front, int rear, int n, int count) {
    if (count == 0) return;
    
    for (int i = 0; i < count; i++) {
        printf("%d ", queue[(front + i) % n]);
    }
    printf("\n");
}

int main() {
    int n, m;

    if (scanf("%d", &n) != 1) return 0;

    int* queue = (int*)malloc(n * sizeof(int));
    int front = 0;
    int rear = -1;
    int count = 0;

    for (int i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);
        rear = (rear + 1) % n;
        queue[rear] = val;
        count++;
    }

    scanf("%d", &m);

    for (int i = 0; i < m; i++) {
        if (count > 0) {
            front = (front + 1) % n;
            count--;
        }
    }

    display(queue, front, rear, n, count);

    free(queue);
    return 0;
}
