/*
    *Name       : Kuldeep Singh Bhandari
    *Roll No.   : 111601009
    *Aim        : Program to sort an array using bubble sort
*/
#include<stdio.h>

//function to sort the given array
void bubbleSort (int *a, int n) {

    int temp;       //temporary variable for swapping
    int i, j;       //loop counters

    for (i = 0; i < n; i++) {
        for (j = 0; j < n - i - 1; j++) {

            //swapping the elements if upcoming element is smaller than the present element
            if (a[j+1] > a[j]) {
                temp = a[j+1];
                a[j+1] = a[j];
                a[j] = temp;
            }
        }

        for (j = 0; j < n; j++) {
            printf("%d->", a[j] );
        }
        printf("\n");
    }

}

//Main begins here
int main () {

    int n;              //to store number of elements in the array
    int i;              //loop counter
    int a[100];         //to store list of integer elements
    printf("Enter the number of elements in the list : (Max. 100)\n");     //asking user to enter the number of elements in the array
    scanf("%d", &n);            //entering number of elements in the array

    if (n <= 0 || n >= 100) {
        printf("ERROR IN INPUT : Number of elements in the array should be greater than 0 and less than 100. \n");
        return 1;               //program didn't work properly
    }

    printf("Enter the elements in the list (to be sorted) : (INTEGERS ONLY)\n");

    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);         //entering the elements in the array
    }

    bubbleSort (a, n);            //function to sort the given array

    printf("LIST AFTER SORTING IS : \n");

    //printing list after sorting
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
    return 0;       //returning 0 for successful program

}
//Main ends here
