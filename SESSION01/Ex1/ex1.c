/*

    * Name     : Kuldeep Singh Bhandari
    * Roll No. : 111601009
    * Aim      : Program to understand the use of structure variables
                 and structure pointer variables
    * Date     : 01-08-2017

*/
#include<stdio.h>
#include<string.h>

//creating structure containing name and id of the students
typedef struct student {

    char name[100];         //to store student Name
    int id;                 //to store student id

} student;                  //now student is an alias for struct student

//function to print the information of the student
void PrintStruc (student stu) {

    printf("Name : %s\n", stu.name);
    printf("Id   : %d\n", stu.id);

}

//function to change the information of the student
void changeInfo (student *sPtr) {

    strcpy(sPtr->name, "abc");
    sPtr->id = 123;

}

int main () {

    student stu1 = { "name", 1 };       //initializing the variables of structure student

    PrintStruc(stu1);       //printing the inialized information of the student

    student *stuPtr = &stu1;        //storing the address of stu1 in pointer stuPtr
    changeInfo (stuPtr);            //changing the information of the student

    //Modified student information
    printf("New Name : %s\n", stuPtr->name);
    printf("New Id   : %d\n", stuPtr->id);

    return 0;       //end of code

}

/* Sample Output :

Name : name
Id   : 1
New Name : abc
New Id   : 123

*/
