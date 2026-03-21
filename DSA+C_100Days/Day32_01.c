#include <stdio.h>

int main() {
    int n, m;
    int stack[100];
    int top = -1;

    if (scanf("%d", &n) != 1) return 0;
    for (int i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);
        stack[++top] = val;
    }

    if (scanf("%d", &m) != 1) return 0;

    for (int i = 0; i < m; i++) {
        if (top >= 0) {
            top--;
        }
    }
    for (int i = top; i >= 0; i--) {
        printf("%d%s", stack[i], (i == 0 ? "" : " "));
    }
    printf("\n");

    return 0;
}
