/*

    * Name     : Kuldeep Singh Bhandari
    * Roll No. : 111601009
    * Aim      : Finding the minimum element in the array
    * Date     : 22-08-2017
    * NOTE     : Precision upto 10 digits after decimal

*/

#include<stdio.h>

//finding the minimum in the array
void findMinimum (double *array, int n, int index, double min) {

    if (index < n) {                 //checking if the array is over or not
        if (array[index] - min <= 0) {          //checking if the element is greater than minimum element
            min = array[index];             //setting minimum to be that element
        }

        findMinimum (array, n, index + 1, min);     //using recursion to access next element in the array
    }
    else {
        printf("MINIMUM = %.10lf\n", min);          //printing the minimum
    }

}
//end of findMinimum function

//BEGINNING OF MAIN FUNCTION
int main () {

    int n;                      //number of elements in the array
    double array[100];           //defining doubleing point array

    printf("Enter total number of elements : (Max. 100)\n");
    scanf("%d", &n);            //entering total number of elements in the array

    if (n == 0) {
        printf("WRONG INPUT. Number of elements (n) shouldn't be zero.\n");
        return 1;
    }

    int i;
    printf("Enter %d elements : \n", n);
    for (i = 0; i < n; i++)
        scanf("%lf", &array[i]);

    findMinimum (array, n, 0, array[0]);        //function to find and print minimum number in the array
    return 0;

}
//END OF MAIN FUNCTION
