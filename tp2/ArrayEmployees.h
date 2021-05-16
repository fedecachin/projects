#ifndef ARRAYEMPLOYEES_H_INCLUDED
#define ARRAYEMPLOYEES_H_INCLUDED

typedef struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;
} Employee;

#endif // ARRAYEMPLOYEES_H_INCLUDED

int initEmployees(Employee* list, int len);

int addEmployee(Employee list[], int len, int* id, char name[],char
                lastName[],float salary,int sector);

int buscarLibre(Employee list[], int len);

int findEmployeeById(Employee* list, int len,int id);

int removeEmployee(Employee* list, int len, int id);

int printEmployees(Employee* list, int length);

void printEmployee(Employee empleado);

int sortEmployees(Employee* list, int len, int order);

int arrayLetras(char array[]);

int modificarEmpleado(Employee lista[], int tam);
