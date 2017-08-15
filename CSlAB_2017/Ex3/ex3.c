/*

    * Name     : Kuldeep Singh Bhandari
    * Roll No. : 111601009
    * Aim      :   1) Creation of a node
                   2) Insertion of an element at a given position in the node
                   3) Deletion of an element in the node
                   4) Reversion of the node

    * Date     : 08-08-2017

*/
#include<stdio.h>
#include<stdlib.h>

//creating structure student to store students' informations (single linked list)
typedef struct student {

    int data;
    struct student *next;

} student;

//function to create a node and return head of the node to the calling function
student * createStudent (int N) {

    student *head = (student *) malloc(sizeof(student));

    printf("ENTER DATA : \n");  //entering the value
    int value;
    scanf("%d", &value);

    head->data = value;
    head->next = NULL;

    student *start = head;
    int i;
    for (i = 1; i < N; i++) {

        scanf("%d", &value);          //entering the value

        student *p = (student *) malloc(sizeof(student));
        p->data = value;
        p->next = start;
        start = p;

    }

    return start;        /*return the element present at the beginning of the linked list
                            (in this case, the last element entered)*/
}

//function to display data in the node
void displayData (student *head) {

    student *p;

    for (p = head; p != NULL; p = p->next) {

        printf("DATA : %d\n", p->data);

    }

}
//function to insert data in the node
int insertData (student *head, int val, int newData) {

    student *p;
    student *temp;
    int flag = 0;

    for (p = head; p != NULL; p = p->next) {

        temp = p->next;
        if (p->data == val) {

            flag = 1;
            break;

        }

    }
    if (flag) {

        student *stu = (student *) malloc(sizeof(student));
        stu->data = newData;

        if (temp == NULL) {
            p->next = stu;
            stu->next = NULL;
        }
        else {

            p->next = stu;
            stu->next = temp;
        }
        return 1;
    }
    else {
        return 0;
    }

}

//function to delete data in the node
student * deleteData (student *head, int val) {

    student *p;
    student *temp;
    int flag = 0;

    for (p = head; p != NULL;) {

        if (head == NULL) {
            printf("HEAD IS NULL !!\n");
            break;
        }

        else if (head->data == val) {

            if (head->next == NULL) {
                free(head);
                return NULL;
            }
            student *x = head;
            head = head->next;
            x->next = NULL;
            free(x);
            p = head;
            flag = 1;
            continue;

        }

        else if (p->data == val) {

            student *x = p;
            p = temp;
            temp->next = x->next;
            x->next = NULL;
            free(x);
            flag = 1;

        }
        temp = p;
        p = p->next;
    }
    if (flag) {
        return head;
    }
    else {
        return NULL;
    }
}

//function to reverse data in the node
student * reverseData (student *head, int N) {

    student *newHead;
    student *p = head->next;
    student *t;
    student *temp = head;
    head->next = NULL;

    int i;
    for (i = 0; i < N-1; i++) {

        if (i != N-2) {

            t = p->next;
            p->next = temp;
            temp = p;
            p = t;

        }
        else {
            p->next = temp;
        }

    }

    return p;

}
//function to free all the memory
void freeMemory (student *head) {

    student *p = head;
    student *temp;
    do {

        temp = p;
        p = p->next;
        temp->next = NULL;
        free(temp);

    } while (p != NULL);

}

int main () {

    int N;
    int val;
    int newData;

    scanf("%d", &N);
    struct student *head = createStudent(N);        //creating student structure and returning head pointer
    printf("head->data : %d\n", head->data);
    printf("The Initial State : \n");
    displayData(head);

    printf("Enter val : ");
    scanf("%d", &val);
    printf("Enter the value to be inserted : ");
    scanf("%d", &newData);

    int check = insertData (head, val, newData);
    if (check) {                             //checking if element exists or not

        printf("\nINSERTION DONE SUCCESSFULLY!!\n\n");
        printf("The State after Insertion : \n");
        displayData (head);

        head = deleteData (head, val);
        if (head != NULL) {
            printf("\nDELETION DONE SUCCESSFULLY!!\n\n");
            printf("The State after Deletion : \n");
            displayData (head);
        }
        else {
            printf("THE LIST IS EMPTY !! \n");
        }

    }
    else {
        printf("INSERTION FAILED !! (%d is not in the list) \n",val);
    }

    if (head != NULL) {

        head = reverseData (head, N);
        printf("The State after Reversion : \n");
        displayData (head);
        freeMemory(head);

    }

    return 0;

}
