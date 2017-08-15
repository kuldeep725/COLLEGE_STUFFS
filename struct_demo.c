/* 	
	* Name 	   : Kuldeep Singh Bhandari	
	* Roll No. : 111601009
*/


#include<stdio.h>
#include<string.h>

struct student {

	char name[100];
	int id;
	
};

//printStruc prints the elements of the structure  student
void printStruc (struct student s) {

	printf("Name : %s\n", s.name);
	printf("Id   : %d\n", s.id);

}

void changeStruc (struct student *sPtr) {

	strcpy(sPtr->name, "abc");
	sPtr->id = 123;

}

int main () {

	struct student stu1 = { "name", 1 };
	struct student *srtptr;

	printStruc (stu1);
	changeStruc (&stu1);
	printStruc (stu1);

	return 0;

}