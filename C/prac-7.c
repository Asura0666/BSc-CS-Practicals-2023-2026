//7.a.Write a program to declare structure employee and read all print data of the employees.

#include <stdio.h>
#include <string.h>

struct employee {
    int id;
    char name[50];
    float salary;
}e1, e2;

int main() {
    
    e1.id = 666;
    strcpy(e1.name, "Asura");
    e1.salary = 50000;
    
    e2.id = 777;
    strcpy(e2.name, "Lucky man");
    e2.salary = 126000;
    
    printf("\nEmpolyee 1 id: %d",e1.id);
    printf("\nEmpolyee 1 name: %s",e1.name);
    printf("\nEmpolyee 1 salary: %f",e1.salary);
    
    printf("\nEmpolyee 2 id: %d",e2.id);
    printf("\nEmpolyee 2 name: %s",e2.name);
    printf("\nEmpolyee 2 salary: %f",e2.salary);
    
    return 0;
}