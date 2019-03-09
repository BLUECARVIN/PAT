#include <cstdio>
#include <iostream>

using namespace std;

struct Node
{
    char name[20];
    char course[20];
    int grade;
}temp, male, female;

int main()
{
    male.grade = INT_MAX;
    female.grade = INT_MIN;
    int num;
    scanf("%d", &num);
    while(num--)
    {
        char s;
        scanf("%s %c %s %d", temp.name, &s, temp.course, &temp.grade);
        if(s == 'M')
        {
            if(temp.grade < male.grade)
                male = temp;
        }
        else if(s == 'F')
        {
            if(temp.grade > female.grade)
                female = temp;
        }
    }
    int flag = 0;
    if(female.grade == INT_MIN)
    {
        printf("Absent\n");
        flag = 1;
    }
    else
    {
        printf("%s %s\n", female.name, female.course);
    }
    if(male.grade == INT_MAX)
    {
        printf("Absent\n");
        flag = 1;
    }
    else
    {
        printf("%s %s\n", male.name, male.course);
    }
    if(flag == 1)
    {
        printf("NA");
    }
    else
    {
        printf("%d", female.grade - male.grade);
    }
    system("pause");
    return 0;
    
    
}