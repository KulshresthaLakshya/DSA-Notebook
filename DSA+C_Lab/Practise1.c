//Creating a structure of students
#include<stdio.h>
#define N 2
struct Students{
    int SAPID;
    char name[50];
    int sem;
    float Attendence;
    float CGPA;
};

//Inputting function Declaration
void input(struct Students[N]);

//Inputting function creation
void input1(struct Students stu[N]){
        for (int i=0; i<N; i++)
    {
        printf("\nSAPID: ");
        scanf("%d", &stu[i].SAPID);
        printf("\nNAME: ");
        scanf("%s", stu[i].name);
        printf("\nSemester: ");
        scanf("%d", &stu[i].sem);
        printf("\nAttendence: ");
        scanf("%f", &stu[i].Attendence);
        printf("\nCGPA: ");
        scanf("%f", &stu[i].CGPA);
        }
}

//Condition checking
void eligible_exam(struct Students stu[N]){ 
    for (int i=0; i<N; i++)
    {
        if (stu[i].Attendence >= 75.0 && stu[i].CGPA >= 7.5)
        {
            printf("%s is eligible for the exam.\n", stu[i].name);
        }
        else
        {
            printf("%s is not eligible for the exam.\n", stu[i].name);
        }
    }
}

//Structure returning function
struct Students input2() {
    struct Students stu;
            printf("\nSAPID: ");
            scanf("%d", &stu.SAPID);
            printf("\nNAME: ");
            scanf("%s", stu.name);
            printf("\nSemester: ");
            scanf("%d", &stu.sem);
            printf("\nAttendence: ");
            scanf("%f", &stu.Attendence);
            printf("\nCGPA: ");
            scanf("%f", &stu.CGPA);
            return stu;
}


//Inputting using pointer
void input3(struct Students* stu[N]){
        for (int i=0; i<N; i++)
    {
        printf("\nSAPID: ");
        scanf("%d", &stu[i]->SAPID);
        printf("\nNAME: ");
        scanf("%s", stu[i]->name);
        printf("\nSemester: ");
        scanf("%d", &stu[i]->sem);
        printf("\nAttendence: ");
        scanf("%f", &stu[i]->Attendence);
        printf("\nCGPA: ");
        scanf("%f", &stu[i]->CGPA);
        }
}

//Main body
int main()
{
    struct Students* stu[N];
    for (int i=0; i<N; i++)
    {
        stu[i] = (struct Students*)malloc(sizeof(struct Students));
        input3(stu);
    }
    /* struct Students stu[N];
    input1(stu);
        for(int i = 0; i<N; i++){
        stu[i] = input2();
    } 
    input3(stu);
    */
    eligible_exam(stu);
    return 0;
}
