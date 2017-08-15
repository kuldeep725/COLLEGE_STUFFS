/*

    * Name     : Kuldeep Singh Bhandari
    * Roll No. : 111601009
    * Aim      : Build two circular linked list of different size such that number of node in
                 the first list is more than number of node in second.Then merge a linked list into
                 another circular linked list by i​ nserting nodes of second list into first list at alternate
                 positions of first list.

    * Date     : 12-08-2017

*/
#include<stdio.h>
#include<stdlib.h>

//defining node to store next pointer and an integer variable
typedef struct node {

    int data;
    struct node *next;

} node;     //creating alias for struct node

//creating n Nodes to store next pointer and an integer variable
node * createNode (int n) {

    node *head = (node *) malloc(sizeof(node));
    scanf("%d ", &(head->data));        //entering the data
    node *end = head;

    int i;

    for (i = 1; i < n; i++) {

        node *p = (node *) malloc(sizeof(node));
        scanf("%d ", &(p->data));        //entering the data
        end->next = p;
        end = p;

    }
    end->next = head;
    return head;                    //returning the head of the node

}

//merging second node into alternate position of first one
node *mergeNodes (node *head1, node *head2, int n, int m) {

    node *p = head1; 
    node *q = head2;
    node *temp = head1; 

    if (p == NULL) {
        return NULL;
    }

    int i = 0;
    while (i < n + m) {     //running loop for (n + m) times

        if ((i < 2 * m) && (i % 2 == 1)) {      //checking if the 2nd node is not completed and i is odd

            temp->next = q;
            temp = q;
            q = q->next;

        }
        else {

            if (i != 0) {
                temp->next = p;
                temp = p;
            }
            p = p->next;

        }

        i++;

    }

    return head1;       //returning the head of the merged Node


}
void displayNode (node * head) {

    node *p = head;

    do {

        printf("%d", p->data);
        if (p->next != head)
            printf("->");
        else printf("\n");

        p = p->next;

    } while (p != head);

}

//function to free all the memory
void freeMemory (node *head) {

    node *ptr;
    node *p = head->next;

    do {

        ptr = p;
        p = p->next;
        ptr->next = NULL;
        free(ptr);          //free the node

    } while (p != head);

    free(head);     //freeing head at the last since head is needed in the loop condition

}
//MAIN FUNCTION BEGINS HERE
int main () {

    int N;      //number of elements in node 1
    int M;      //number of elements in node 2
    node *headMerged = NULL;

    scanf("%d %d\n", &N, &M);   //entering value of N & M

    node *head1 = createNode(N);        //creating first Node
    node *head2 = createNode(M);        //creating second Node

    printf("FIRST NODE IS : \n");
    displayNode(head1);
    printf("SECOND NODE IS : \n");
    displayNode(head2);
    if (N  > M) {
        headMerged = mergeNodes(head1, head2, N, M);        //merging node1 and node2
        if (headMerged == NULL) {
            printf("HEAD OF FIRST NODE IS NULL.\n");
        }
        else {
            printf("MERGED NODE IS : \n");
            displayNode (headMerged);
            free(headMerged);       //freeing the whole node
        }
        
    }

    else {
        puts("INVALID INPUT. FIRST NODE IS SMALLER THAN OR EQUAL TO SECOND NODE.");
        return 1;
    }
    if (headMerged == NULL && head1 != NULL) 
        freeMemory(head1);    //freeing memory for head of first node
    if (headMerged == NULL && head2 != NULL)
        freeMemory(head2);    //freeing memory for head of second node

    return 0;

}
//MAIN FUNCTION ENDS HERE

/*SAMPLE INPUT FORMAT 1 :

7 5
6 7 8 9 163 15 44
1 2 3 4 5

*/

/*SAMPLE OUTPUT 1:

FIRST NODE IS : 
6->7->8->9->163->15->44
SECOND NODE IS : 
1->2->3->4->5
MERGED NODE IS : 
6->1->7->2->8->3->9->4->163->5->15->44

*/

/*SAMPLE INPUT FORMAT 2 :

5 7 
1 2 3 4 5
6 7 8 9 163 15 44

*/

/*SAMPLE OUTPUT 2:

FIRST NODE IS : 
1->2->3->4->5
SECOND NODE IS : 
6->7->8->9->163->15->44
INVALID INPUT. FIRST NODE IS SMALLER THAN OR EQUAL TO SECOND NODE.

*/
