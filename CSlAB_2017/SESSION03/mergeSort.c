/*
    *Name       : Kuldeep Singh Bhandari
    *Roll No.   : 111601009
    *Aim        : Program to sort an array using merge sort (Recursion)
*/
#include<stdio.h>
#include<string.h>

char a[20][32];             //array pointer to store the input list of integers

int compare (char p[32], char q[32]) {

    int check = -1;
    int i = 0;
    while (p[i] != '\0' && q[i] != '\0') {
        if (p[i] <= 'z' && p[i] >= 'a' && q[i] <= 'z' && q[i] >= 'a' ) {
            if (p[i] < q[i]) {
                return -1;
            }
            else {
                return 1;
            }
        }
        else if (p[i] <= 'Z' && p[i] >= 'A' && q[i] <= 'Z' && q[i] >= 'A' ) {
            if (p[i] < q[i]) {
                return -1;
            }
            else {
                return 1;
            }
        }
        else {
            if (p[i] <= 'z' && p[i] >= 'a' && q[i] <= 'Z' && q[i] >= 'A') {
                if (p[i] - 'a' == q[i]-'A' && i == 0) {
                    return -1;
                }
                else if (p[i]-'a' < q[i]-'A') {
                    return -1;
                }
                else {
                    return 1;
                }
            }
            else if (p[i] <= 'Z' && p[i] >= 'A' && q[i] <= 'z' && q[i] >= 'a'){
                if (p[i] - 'A' == q[i]-'a' && i == 0) {
                    return 1;
                }
                else if (p[i]-'A' < q[i]-'a') {
                    return -1;
                }
                else {
                    return 1;
                }
            }
        }
        i++;
    }
    return check;

}
//program to merge two arrays
void mergeArray (int low, int mid, int high) {

    char c[16][32];
    int i;
    int length_1;
    int length_2;
    printf("a = %s\n", a[mid]);

    //copying elements from array 'a' in a sorting manner in array 'c'
    for (i = low, length_1 = low, length_2 = mid + 1; length_1 <= mid && length_2 <= high; i++) {


        if (compare(a[length_1], a[length_2]) < 0) {
            strcpy(c[i],a[length_1++]);
        }

        else {
            strcpy(c[i],a[length_2++]);
        }
    }

    //only one of two below loops will run
    while (length_1 <= mid) {
        strcpy(c[i],a[length_1++]);         //copying remaining elements in c
    }
    while (length_2 <= high) {
        strcpy(c[i],a[length_2++]);       //copying remaining elements in c
    }

    for (i = low;  i<= high; i++) {
        strcpy(a[i],c[i]);           //copying new array 'c' into array 'a'
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
    int i;               //loop counter
    printf("Enter the number of elements in the list : (Max. 100)\n");     //asking user to enter the number of elements in the array
    scanf("%d", &n);            //entering number of elements in the array
printf("n = %d\n", n);
    if (n <= 0 || n >= 100) {
        printf("ERROR IN INPUT : Number of elements in the array should be greater than 0 and less than 100. \n");
        return 1;               //program didn't work properly
    }

    printf("Enter the elements in the list (to be sorted) : \n");

    for (i = 0; i < n; i++) {
        scanf("%s\n", a[i]);         //entering the elements in the array
    }

    mergeSort(0, n - 1);            //function to sort the given array

    printf("LIST AFTER SORTING IS : \n");

    //printing list after sorting
    for (i = 0; i < n; i++) {
        printf("%s ", a[i]);
    }
    printf("\n");
    return 0;       //returning 0 for successful program

}
//MAIN FUNCTION ENDS HERE
