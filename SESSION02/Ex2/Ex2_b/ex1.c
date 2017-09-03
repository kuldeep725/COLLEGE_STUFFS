/*

    * Name     : Kuldeep Singh Bhandari
    * Roll No. : 111601009
    * Aim      : Implementation of Stacks
    * Date     : 29-08-2017

*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//creating a structure with a string variable "name" and next pointer
typedef struct stack {

    char name[100];
    struct stack *next;

} stack;        //creating new alias for "struct stack" data type

//DEFINING PROTYPES
stack newStack();
void stackPush (stack **, char *);
char* stackPop (stack **);
//int stackSize(stack);
int stackIsEmpty (stack *);
void stackTop (stack *);
int count = 0;      //counter variable to calculate size of stacks

//MAIN FUNCTION BEGINS HERE
int main () {

    stack *top = NULL;          //pointer to struct stack pointing to the top of the stack
    char moviename[100];        //to store movie name

    printf("ENTER MOVIE NAME : \n");
    scanf ("%s", moviename);                //asking user to enter movie name
    stackPush (&top, moviename);            //pushing into stack
    printf("PUSHING AN ELEMENT TO THE STACK....\n");

    strcpy (moviename, stackPop (&top));        //popping from stack
    printf("POPPING AN ELEMENT FROM THE STACK....\n");
    printf("POPPED Movie name = %s\n", moviename);

    strcpy (moviename, stackPop (&top));        //popping from stack
    printf("\nPOPPING AN ELEMENT FROM THE STACK....\n");


    //int checkStack = stackIsEmpty (top);

    printf("ENTER MOVIE NAME : \n");
    scanf ("%s", moviename);                //asking user to enter movie name
    stackPush (&top, moviename);            //pushing into stack
    printf("PUSHING AN ELEMENT TO THE STACK....\n");

    printf("ENTER MOVIE NAME : \n");
    scanf ("%s", moviename);                //asking user to enter movie name
    stackPush (&top, moviename);            //pushing into stack
    printf("PUSHING AN ELEMENT TO THE STACK....\n");

    printf("ENTER MOVIE NAME : \n");
    scanf ("%s", moviename);                //asking user to enter movie name
    stackPush (&top, moviename);            //pushing into stack
    printf("PUSHING AN ELEMENT TO THE STACK....\n");

    strcpy (moviename, stackPop (&top));
    printf("\nPOPPING AN ELEMENT FROM THE STACK....\n");
    printf("POPPED Movie name = %s\n", moviename);

    printf("ENTER MOVIE NAME : \n");
    scanf ("%s", moviename);                //asking user to enter movie name
    stackPush (&top, moviename);            //pushing into stack
    printf("PUSHING AN ELEMENT TO THE STACK....\n");

    printf("ENTER MOVIE NAME : \n");
    scanf ("%s", moviename);                //asking user to enter movie name
    stackPush (&top, moviename);            //pushing into stack
    printf("PUSHING AN ELEMENT TO THE STACK....\n");

    printf("SIZE OF THE STACK :  %d\n", count);      //printing size of the stack

    printf("\n----------LIST OF MOVIES---------- \n\n");

    stackTop (top);             //printing top of the stack
    strcpy (moviename, stackPop (&top));        //popping from stack

    stackTop (top);             //printing top of the stack
    strcpy (moviename, stackPop (&top));        //popping from stack

    stackTop (top);             //printing top of the stack
    strcpy (moviename, stackPop (&top));        //popping from stack
    stackTop (top);             //printing top of the stack
    strcpy (moviename, stackPop (&top));        //popping from stack

    return 0;

}
//MAIN FUNCTION ENDS HERE

/*stack newStack () {

    stack *top;
    return top;

}*/

void stackPush (stack **top, char *thename) {

    stack *p = (stack *) malloc (sizeof(stack));
    strcpy(p->name, thename);
    count++;

    if (top != NULL) {
        p->next = *top;
        *top = p;
    }
    else {
        *top = p;
        (*top)->next = NULL;
        printf("TOP = NULL\n");
    }


}

char* stackPop (stack **top) {

    if (*top == NULL) {
        printf("CAN'T BE POPPPED. EMPTY STACK !!\n");
        return " ";
    }
    stack *p = *top;
    *top = (*top)->next;
    static char thename[100];
    strcpy(thename, p->name);
    p->next = NULL;
    free(p);
    count--;
    return thename;

}
    //printf("Pushing movie : %s\n", p->name);

int stackIsEmpty (stack *top) {

    int count = 1;
    if (top == NULL) {
        count = 0;
    }
    return count;

}

void stackTop (stack *top){

    printf("MOVIE NAME (%d): %s\n",count, top->name);

}
