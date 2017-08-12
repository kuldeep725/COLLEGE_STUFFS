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

} node;

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
node * mergeNodes (node *head1, node *head2, int n) {

    node *head = (node *) malloc(sizeof(node));
    head->data = head1->data;
    head->next = head2;
    node *p = head1->next;
    node *q = head2;
    node *end = head;

    int i = 1;
    while (i < 2 * n) {

        node *r = (node *) malloc(sizeof(node));
        if (i % 2 == 0) {

            r->data = p->data;
            end->next = r;
            end = r;
            p = p->next;



        }
        else {

            r->data = q->data;
            end->next = r;
            end = r;
            q = q->next;

        }
        if (i == n - 1) r->next = NULL;
        i++;

    }
    end->next = head;
    return head;            //returning the head of the merged Node

}

//to display data in the node
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

//MAIN FUNCTION BEGINS HERE
int main () {

    int N;
    int M;

    scanf("%d %d\n", &N, &M);   //entering value of N & M

    node *head1 = createNode(N);
    node *head2 = createNode(M);

    printf("FIRST NODE IS : \n");
    displayNode(head1);
    printf("SECOND NODE IS : \n");
    displayNode(head2);
    if (N  < M) {
        node *headMerged = mergeNodes(head1, head2, N);
        printf("MERGED NODE IS : \n");
        displayNode (headMerged);
        free(headMerged);
    }

    else {
        puts("INVALID INPUT. FIRST NODE IS BIGGER THAN OR EQUAL TO SECOND NODE.");
        return 1;
    }
    free(head1);    //freeing memory for head of first node
    free(head2);    //freeing memory for head of second node

    return 0;

}
//MAIN FUNCTION ENDS HERE

/*SAMPLE INPUT FORMAT :
5 7
1 2 3 4 5
6 7 8 9 163 15 44
*/

/*SAMPLE OUTPUT :
FIRST NODE IS : 
1->2->3->4->5
SECOND NODE IS : 
6->7->8->9->163->15->44
MERGED NODE IS : 
1->6->2->7->3->8->4->9->5->163
*/