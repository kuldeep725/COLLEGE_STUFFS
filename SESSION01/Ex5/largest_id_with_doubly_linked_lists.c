#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct student {

	char name[32];
	int id;
	struct student *next;
	struct student *prev;

} student;

int main(int argc, char const *argv[]) {

	int N;
	scanf("%d\n", &N);

	student *head = (student *) malloc(sizeof(student));

	int i;

	scanf(" %32[a-zA-Z ] ", head->name);
	scanf("%d\n", &(head->id));
	printf("Name : %s\nId : %d\n", head->name, head->id);
	head->prev = NULL;

	int max = head->id;
	int index = 0;
	student *temp = head;
	char answer[32];

	for (i = 1; i < N; i++) {

		student *s = (student *) malloc(sizeof(student));

		scanf("%32[a-zA-Z ] %d\n", s->name, &(s->id));
		printf("Name : %s\nId : %d\n", s->name, s->id);

		temp->next = s;
		s->prev = temp;
		temp = s;

		if(max < s->id) {
			max = s->id;
			strcpy(answer,s->name);
		}

	}

	printf("Name with largest id is %s\n" , answer);

	return 0;
}