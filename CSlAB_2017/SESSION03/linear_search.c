/*

    * Name     : Kuldeep Singh Bhandari
    * Roll No. : 111601009
    * Aim      : SEARCHING AN ELEMENT USING SEQUENTIAL SEARCH ALGORITHM
    * Date     : 08-09-2017
    * NOTE     : PRECISION UPTO 6 DIGITS ONLY

*/
#include<stdio.h>

const float THRESHOLD = 0.000001;       //threshold for the float values

//function to calculate element in the list
void searchElementInTheList (float *a, float ele, int n) {

    int i;

    for (i = 0; i < n; i++) {

        //checking if the difference between value is less than threshold or not
        //PRECISION UPTO 6 DIGITS ONLY
        if (((ele - a[i]) <= THRESHOLD && (ele - a[i]) >= -THRESHOLD) || ((a[i] - ele) <= THRESHOLD && (a[i] - ele) >= -THRESHOLD))
        {
            printf("YES, SEARCH ELEMENT exists.\n");       //SEARCH ELEMENT IS FOUND
            return;
        }
    }
    printf("NO, SEARCH ELEMENT doesn't exist.\n");          //SEARCH ELEMENT IS NOT FOUND.

}

//MAIN FUNCTION BEGINS HERE
int main () {

    int n;                  //TO STORE TOTAL NUMBER OF ELEMENTS
    printf("Enter number of elements in the array : (max. 100) \n");
    scanf("%d", &n);        //STORING NUMBER OF ELEMENTS
    if (n > 100) {          //CHECKING IF THE NUMBER IS GREATER THAN 100 OR NOT
        printf("ERROR : Number of array should be less than 100\n");        //SHOWING THE ERROR MESSAGE
        return 1;
    }

    float list[100];        //to store elements of the array
    printf("ENTER THE ELEMENTS OF THE LIST (PRECISION UPTO .000001) :\n");
    int i;
    int temp;

    for (i = 0; i < n; i++) {

        scanf("%f", &list[i]);
        if (i == 0) {
            temp = list[i];
        }
        else {
            if (list[i] - temp < THRESHOLD && list[i] - temp > -THRESHOLD) {       //checking if the numbers are sorted or not by comparing with the threshold value
                printf("ERROR : UNSORTED DATA \n");
                return 1;
            }
            temp = list[i];         //storing the element to be used for checking in the next loop
        }
    }

    float searchElement;        //TO STORE THE SEARCH ELEMENT
    printf("ENTER THE SEARCH ELEMENT : \n");
    scanf("%f", &searchElement);

    searchElementInTheList (list, searchElement, n);        //calling function to check if the element exists or not
    return 0;

}
//END OF THE MAIN FUNCTION
