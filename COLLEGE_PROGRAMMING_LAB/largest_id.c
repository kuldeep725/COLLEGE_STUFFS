#include<stdio.h>
#include<stdlib.h>

struct student {

	char name[100];
	int id;

};

int main () {

	struct student *sPtr;
	int N;

	//printf("Enter number of students : ");
	scanf("%d",&N);

	sPtr = (struct student *) malloc(N * sizeof(sPtr));

	int i;
	for (i = 0; i < N; i++) {

		//printf("%d\n", i + 1);
		//printf("Enter Name : ");
		scanf("%s", sPtr[i].name);
		//printf("Enter Id : ");
		scanf("%d", &(sPtr[i].id));

	}

	int max = sPtr[0].id;
	int index = 0;
	for (i = 0; i < N; i++) {

		if (max < sPtr[i].id) {
			max = sPtr[i].id;
			index = i;
		}

	}
	printf("Name with maximum id %d is : %s\n", max, sPtr[index].name);

	

	return 0;

}