/*

    * Name     : Kuldeep Singh Bhandari
    * Roll No. : 111601009
    * Aim      : Using recursion to print Fibonacci series upto a given number
    * Date     : 22-08-2017

*/

#include<stdio.h>

int n = 0;                  //assigning total number of inputs
int i = 2;                  //global variable counter for counting number of inputs

//function to print Fibonacci series using recursion
void Fibonacci (int x, int y) {

    int temp;               //temporary variable to store value of x
    if (i < n) {

        temp = x;
        x = y;              //storing present value of y in x
        y = y + temp;       //storing earlier value of x in y
        printf("%d ", y);
        i++;
        Fibonacci (x, y);   //calling Fibonacci function recursively
        return;
    }
    else {
        return;
    }

}

//Beginning of Main Function
int main () {

    int x = 0;
    int y = 1;

    printf("Enter the number of elements to be printed :\n");
    scanf("%d", &n);

    //switch for cases when n = 0, n = 1 and n >= 2
    switch (n) {

        case 0 :
                 printf("NO RESULTS.\n");
                 break;

        case 1 :
                 printf("FIBONACCI SERIES IS :\n");
                 printf("%d \n", x);
                 break;

        default :
                 printf("FIBONACCI SERIES OF FIRST %d ELEMENTS IS :\n", n);
                 printf("%d %d ", x, y);
                 Fibonacci(x, y);
                 printf("\n");
                 break;

    }

    return 0;

}
//End of main function
