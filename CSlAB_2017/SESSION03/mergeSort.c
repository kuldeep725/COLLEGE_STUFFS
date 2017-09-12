/*
    *Name       : Kuldeep Singh Bhandari
    *Roll No.   : 111601009
    *Aim        : Program to sort an array using merge sort (Recursion)
*/
#include<stdio.h>

int a[100];             //array pointer to store the input list of integers

//program to merge two arrays
void mergeArray (int low, int mid, int high) {

    int c[100];
    int i;
    int length_1;
    int length_2;

    //copying elements from array 'a' in a sorting manner in array 'c'
    for (i = low, length_1 = low, length_2 = mid + 1; length_1 <= mid && length_2 <= high; i++) {

        if (a[length_1] < a[length_2]) {
            c[i] = a[length_1++];
        }

        else {
            c[i] = a[length_2++];
        }
    }

    //only one of two below loops will run
    while (length_1 <= mid) {
        c[i++] = a[length_1++];         //copying remaining elements in c
    }
    while (length_2 <= high) {
        c[i++] = a[length_2++];         //copying remaining elements in c
    }

    for (i = low;  i<= high; i++) {
        a[i] = c[i];            //copying new array 'c' into array 'a'
    }

}

//to mergeSort the given array
void mergeSort (int low, int high) {

    if (low < high) {

        int mid = (low + high) / 2;
        mergeSort (low, mid);               //splitting into left half
        mergeSort (mid + 1, high);          //splitting into right half
        mergeArray (low, mid, high);        //merging the two halves

    }
}

//MAIN FUNCTION BEGINS HERE
int main () {

    int n;              //to store number of elements in the array
    int i;              //loop counter
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

    mergeSort(0, n - 1);            //function to sort the given array

    printf("LIST AFTER SORTING IS : \n");

    //printing list after sorting
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
    return 0;       //returning 0 for successful program

}
//MAIN FUNCTION ENDS HERE
