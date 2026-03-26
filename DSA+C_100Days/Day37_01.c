#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100

int queue[MAX];
int size = 0;

void insert(int x) {
    if (size >= MAX) return;
    
    int i = size - 1;
    while (i >= 0 && queue[i] < x) {
        queue[i + 1] = queue[i];
        i--;
    }
    queue[i + 1] = x;
    size++;
}
void delete() {
    if (size == 0) {
        printf("-1\n");
    } else {
        printf("%d\n", queue[size - 1]);
        size--;
    }
}
void peek() {
    if (size == 0) {
        printf("-1\n");
    } else {
        printf("%d\n", queue[size - 1]);
    }
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    char op[10];
    int val;

    for (int i = 0; i < n; i++) {
        scanf("%s", op);
        if (strcmp(op, "insert") == 0) {
            scanf("%d", &val);
            insert(val);
        } else if (strcmp(op, "delete") == 0) {
            delete();
        } else if (strcmp(op, "peek") == 0) {
            peek();
        }
    }

    return 0;
}
