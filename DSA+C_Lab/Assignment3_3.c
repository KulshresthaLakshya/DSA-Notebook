#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

bool isValidPath(int path[], int n, int target) {
    int min = INT_MIN;
    int max = INT_MAX;

    for (int i = 0; i < n - 1; i++) {
        if (path[i] < min || path[i] > max) return false;
        if (target > path[i]) min = path[i];
        else max = path[i];
    }
    return true;
}

int main() {
    int seqD[] = {17, 77, 27, 66, 18, 43};
    int n = 6;
    if (isValidPath(seqD, n, 43)) printf("Sequence (d) is Possible\n");
    else printf("Sequence (d) is Not Possible (Violates BST boundaries)\n");
    return 0;
}