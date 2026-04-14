/* Write a program to check whether a given string is a palindrome or not using an Array and a Queue data structure. */
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX 100

char queue[MAX];
int front = -1;
int rear = -1;

void enqueue(char c) {
    if (rear == MAX - 1) return;
    if (front == -1) front = 0;
    queue[++rear] = c;
}

char dequeue() {
    if (front == -1 || front > rear) return '\0';
    return queue[front++];
}

int main() {
    char str[MAX];
    int i, len;
    int isPalindrome = 1;

    printf("Enter a string: ");
    fgets(str, MAX, stdin);
    
    str[strcspn(str, "\n")] = 0;
    len = strlen(str);
    for (i = 0; i < len; i++) {
        enqueue(tolower(str[i]));
    }

    for (i = len - 1; i >= 0; i--) {
        if (tolower(str[i]) != dequeue()) {
            isPalindrome = 0;
            break;
        }
    }

    if (isPalindrome) {
        printf("\"%s\" is a palindrome.\n", str);
    } else {
        printf("\"%s\" is not a palindrome.\n", str);
    }

    return 0;
}