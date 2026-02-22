#include <stdio.h>

struct Student {
    int sapID;
    char name[50];
    float cgpa;
};

int main() {
    int n;
    printf("Enter the number of students: ");
    scanf("%d", &n);

    struct Student s[n]; 
    for(int i = 0; i < n; i++) {
        printf("\nEnter details for Student %d\n", i + 1);
        printf("SAP ID: ");
        scanf("%d", &s[i].sapID);
        printf("Name: ");
        scanf(" %[^\n]s", s[i].name); 
        printf("CGPA: ");
        scanf("%f", &s[i].cgpa);
    }

    printf("\n--- SAP IDs of Students with CGPA >= 7 ---\n");
    int found = 0;
    for(int i = 0; i < n; i++) {
        if(s[i].cgpa >= 7.0) {
            printf("SAP ID: %d (Name: %s)\n", s[i].sapID, s[i].name);
            found = 1;
        }
    }

    if(!found) {
        printf("No students found with CGPA >= 7.\n");
    }

    return 0;
}