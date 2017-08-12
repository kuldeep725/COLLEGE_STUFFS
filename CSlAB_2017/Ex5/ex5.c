/*

    * Name     : Kuldeep Singh Bhandari
    * Roll No. : 111601009
    * Aim      :   1) Creation of a node using doubly linked list
                   2) Insertion of an element at a given position  in the node using doubly linked list
                   3) Deletion of an element in the node using doubly linked list
                   4) Reversion of the node using doubly linked list

    * Date     : 12-08-2017

*/
#include<stdio.h>
#include<stdlib.h>

//creating structure student to store students' informations using doubly linked list
typedef struct student {

	int data;
	struct student *next;
	struct student *prev;

} student;

student * createStudent (int );
void displayData (student *); 
student * insertData (student *, int , int );
student * deleteData (student *, int );
student * reverseData (student *);


/*MAIN FUNCTION BEGINS*/
int main(int argc, char const *argv[]) {

	int N;
	int val;
	int newData;
	scanf("%d", &N);

	student *start = createStudent (N);			   //creating student structure and returning head pointer
	printf("start->data : %d\n", start->data);
	printf("The Initial State : \n");
    displayData(start);

    printf("Enter val : ");
    scanf("%d", &val);
    printf("Enter the value to be inserted : ");
    scanf("%d", &newData);

    start = insertData (start, val, newData);			
    if (start != NULL) {                             //checking if element exists or not

        printf("\nINSERTION DONE SUCCESSFULLY!!\n\n");
        printf("The State after Insertion : \n");
        displayData (start);

        start = deleteData (start, val);
        if (start != NULL) {
            printf("\nDELETION DONE SUCCESSFULLY!!\n\n");
            printf("The State after Deletion : \n");
            displayData (start);
        }
        else {
        	printf("\nDELETION DONE SUCCESSFULLY!!\n\n");
            printf("THE LIST IS EMPTY NOW!! \n");

        }

    }
    else {
        printf("INSERTION FAILED !! (%d is not in the list) \n",val);
    }

    if (start != NULL) {

        start = reverseData (start);
        printf("The State after Reversion : \n");
        displayData (start);
        free(start);

    }

    return 0;
}
/*MAIN FUNCTION ENDS*/

//function to create a node and return head of the node to the calling function
student * createStudent (int n) {

	student *end;
	student *start;
	student *p;

	int i;
	for (i = 0; i < n; i++) {

		p = (student *) malloc (sizeof(student));
		scanf("%d", &(p->data));		//entering the value

		if (i == 0) {

			end = p;
			start = p;

		}
		else {

			start->prev = p;
			p->next = start;
			start = p;

		}

	}
	start->prev = NULL;
	end->next = NULL;
	return start;	 /*return the element present at the beginning of the linked list
                            (in this case, the last element entered)*/

}

//function to display data in the node
void displayData (student *start) {

	student *p = start;

	do {

		printf("Data : %d\n", p->data);
		p = p->next;

	} while(p != NULL);
	


}

//function to insert data in the node
student * insertData (student *start, int val, int newData) {

	student *p = start;
	student *addNode;
	int flag = 0;

	do {

		if (p->data == val) {

			flag = 1;
			break;

		}
		p = p->next;

	} while(p != NULL);
	
	if (flag) {

		addNode = (student *) malloc(sizeof(student));
		addNode->data = newData;

		if (p->next == NULL) {

			addNode->prev = p;
			addNode->next = NULL;
			p->next = addNode;
			
		}
		else {
			
			addNode->prev = p;
			addNode->next = p->next;
			p->next->prev = addNode;
			p->next = addNode;

		}

		return start;

	}

	else return NULL;
}

//function to delete data in the node
student * deleteData (student *start, int val) {

	student *p = start;
	student *temp;

	if (start == NULL) {
		return start;
	}

	do {

		if (p->data == val) {
			
			if (p == start) {

				if (p->next == NULL) {		//checking if it is only element
					free(p);
					return NULL;
				}
				temp = p;
				p = p->next;
				start = temp->next;
				temp->next = NULL;
				temp->prev = NULL;
				free (temp);
				continue;
				
			}

			else {

				temp = p;
				p = p->next;
				temp->prev->next = temp->next;
				temp->next->prev = temp->prev;
				temp->prev = NULL;
				temp->next = NULL;
				free(temp);
				continue;
			
			}
		}
		p = p->next;


	} while (p != NULL);

	return start;

}

//function to reverse data in the node
student * reverseData (student *start) {

	student *p = start;
	student *end = start;
	student *temp = NULL;
	student *t;

	if (start == NULL) {
		return NULL;
	}
	do {

		if (p->next == NULL) {		//checking if it is the last element 

			start = p;
			start->next = temp;
			start->prev = NULL;
			break;

		}

		else {

			t = p->next;			//saving p->next initially is important for proper updation
			p->prev = t;
			p->next = temp;
			temp = p;
			p = t;
			
		}
		
	} while (p != NULL);

	return start;		//returning start of the node

}
/*SAMPLE OUTPUT : 
5
1 2 2 4 5
start->data : 5
The Initial State : 
Data : 5
Data : 4
Data : 2
Data : 2
Data : 1
Enter val : 2
Enter the value to be inserted : 5
INSERTION DONE SUCCESSFULLY!!

The State after Insertion : 
Data : 5
Data : 4
Data : 2
Data : 5
Data : 2
Data : 1

DELETION DONE SUCCESSFULLY!!

The State after Deletion : 
Data : 5
Data : 4
Data : 5
Data : 1
The State after Reversion : 
Data : 1
Data : 5
Data : 4
Data : 5
*/