#include <stdio.h>
#include <string.h>

void findFirstRepeated(char* s) {
    int seen[26] = {0};
    int found = 0;

    for (int i = 0; s[i] != '\0'; i++) {
        int val = s[i] - 'a';

        if (seen[val] > 0) {
            printf("%c\n", s[i]);
            found = 1;
            break;
        }

        seen[val]++;
    }

    if (!found) {
        printf("-1\n");
    }
}

int main() {
    char s[1000];
    
    if (scanf("%s", s) == 1) {
        findFirstRepeated(s);
    }

    return 0;
}
