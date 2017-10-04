/*

    * Name      : Kuldeep Singh Bhandari
    * Roll No.  : 111601009
    * Date      : 04-09-2017
    * Aim       : To make a dot language from reading a text file
*/
#include<stdio.h>
#include<string.h>

FILE *fpRead;               //to read the file containing adjacency matrix
FILE *fpWrite;              //to write the file having dot form of the adjacency matrix
int a[32][32];              //to store the elements of adjacency matrix
int n;                      //to store the number of rows/column
char s1[32];                //to store name of the output file (by reading first string from input file)

//to read the file containing adjacency matrix
void readAdjacentMatrix () {

    char s2[32];            //to store input string
    fscanf(fpRead, " %[^\n]s",s1);
    fscanf(fpRead, " %[^\n]s",s2);
    fscanf(fpRead, "%d", &n);       //to read number of rows/columns in the adjacency matrix
    int i, j;               //loop variables
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            fscanf(fpRead, "%1d", &a[i][j]);        //taking input as n*n adjacency matrix from the input file
        }
    }
    /*for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%1d", a[i][j]);
        }
        printf("\n");
    }*/

}

//to make dot file from the given adjacency matrix
void makeDotFile () {

    char one[32];
    strcpy(one, s1);
    strcat(s1, ".dot");
    fpWrite = fopen(s1, "w");                   //creating/ opening a file to write dot form of the adjacency matrix
    //NOW WE START WRITING DATA IN THE FILE

    fprintf(fpWrite, "graph %s {\n", one);

    int i,j;
    int check;

    for (i = 0; i < n; i++) {
        check = 0;              //TO CHECK IF INCOMING NODE IS CONNECTED TO ANYONE OR NOT
        for (j = i; j < n; j++) {
            if (a[i][j] == 1) {
                fprintf(fpWrite, "      ");
                fprintf(fpWrite, "%d -- %d ", i, j);
                if (j == n -1 && i == n-1) {
                    fprintf(fpWrite, "\n");
                }
                else {
                    fprintf(fpWrite, ";\n");
                }
                check = 1;
            }
        }
        if (check == 0) {       //IF NODE IS NOT CONNECTED TO ANYONE
            fprintf(fpWrite, "      ");
            fprintf(fpWrite, "%d ", i);

            if (i != n -1) {
                fprintf(fpWrite, ";\n");
            }
            else {
                fprintf(fpWrite, "\n");
            }
        }
    }
    fprintf(fpWrite, "}");

}
//MAIN BEGINS HERE
int main () {

    char fileName[55];
    printf("ENTER FILE NAME : \n");
    scanf("%s", fileName);
    fpRead = fopen(fileName,"r");       //opening .txt input file 
    if (fpRead == 0) {
        printf("ERROR IN FILE OPENING.\n");
        return 1;
    }
    readAdjacentMatrix();
    makeDotFile();      //CALLING MAKEDOT TO CREATE .dot FILE
    return 0;
}
//MAIN ENDS HERE
