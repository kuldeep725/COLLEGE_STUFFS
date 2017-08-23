#include<stdio.h>
#include<stdlib.h>

typedef struct node {

    int data;
    struct node *next;

} node;

node * createNode (int n) {

    node *head = (node *) malloc(sizeof(node));
    scanf("%d ", &(head->data));
    node *end = head;

    int i;

    for (i = 1; i < n; i++) {

        node *p = (node *) malloc(sizeof(node));
        scanf("%d ", &(p->data));
        end->next = p;
        end = p;

    }
    end->next = head;
    return head;
    /*for stacks
    node *head = (node *) malloc(sizeof(node));
    scanf("%d ", &(head->data));
    node *start = head;
    head->next = NULL;

    int i;

    for (i = 1; i < n; i++) {

        node *p = (node *) malloc(sizeof(node));
        scanf("%d ", &(p->data));
        printf("Data : %d\n", p->data);
        p->next = start;
        start = p;

    }
    return start;*/

}

node * mergeNodes (node *head1, node *head2, int n) {

    node *head = (node *) malloc(sizeof(node));
    head->data = head1->data;
    head->next = head2;
    node *p = head1->next;
    node *q = head2;
    node *end = head;

    int i = 1;
    while (i < 2*n) {

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
    return head;

}

void displayNode (node * head) {

    node *p = head;

    while (p != NULL) {

        printf("%d", p->data);
        if (p->next != NULL)
            printf("->");
        else printf("\n");

        p = p->next;

    }

}

int main () {

    int N;
    int M;

    scanf("%d %d\n", &N, &M);

    node *head1 = createNode(N);
    node *head2 = createNode(M);

    displayNode(head1);
    displayNode(head2);
    if (N  < M) {
        node *headMerged = mergeNodes(head1, head2, N);
        displayNode (headMerged);
        free(headMerged);
    }

    else {
        puts("N IS NOT SMALLER THAN M");
        return 1;
    }
    free(head1);
    free(head2);

    return 0;

}

//./apm config set https-proxy=http://111601009:password@10.64.1.222:8080
//./apm config set http-proxy=http://111601009:password@10.64.1.222:8080
