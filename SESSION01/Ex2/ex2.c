/*

    * Name     : Kuldeep Singh Bhandari
    * Roll No. : 111601009
    * Aim      : Program to understand the use of structure variables
                 and structure pointer variables
    * Date     : 01-08-2017

*/
#include<stdio.h>
#include<stdlib.h>          //to use malloc function

//function to change the information of the student
typedef struct student {

    char name[33];          //to store student Name
    int id;                 //to store student Id

} student;                  //now student is an alias for struct student

int main () {

    student *list;          //pointer variable to the structure
    int N;
    scanf("%d\n", &N);      //total number of students

    list = (student *) malloc(sizeof(student));         //dynamically allocating memory to the structure pointer from heap

    int i;
    for (i = 0; i < N; i++) {

        scanf(" %32[a-zA-Z ]", list[i].name);           /*storing name with small letters and capital letters
                                                          and can even have spaces inbetween*/
        scanf(" %d", &(list[i].id));
        printf("Name : %s\nId   : %d\n",list[i].name, list[i].id );     //printing information of the students

    }
    int max = list[0].id;     //to find maximum id
    int index = 0;            //to find index of the student with maximum id

    for (i = 0; i < N; i++) {

        if (max < list[i].id) {

            max = list[i].id;
            index = i;

        }

    }

    printf("The name of the person with largest id (%d) is \"%s\".\n", max, list[index].name);
    free(list);
    return 0;       //end of code

}
/* Sample Output :

Name : Mouni
Id   : 14
Name : Dilip
Id   : 27
Name : Shawn
Id   : 99
Name : Harry
Id   : 21
Name : John
Id   : 22
Name : Jennifer Lawrence
Id   : 108
The name of the person with largest id (108) is "Jennifer Lawrence ".

*/
