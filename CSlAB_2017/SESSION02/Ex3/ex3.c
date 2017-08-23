/*

    * Name     : Kuldeep Singh Bhandari
    * Roll No. : 111601009
    * Aim      : Using​ ​ recursion​ ​ to​ ​ print​ ​ numbers​ ​ from​ ​ n ​ ​ to​ ​ 0
    * Date     : 22-08-2017

*/

#include<stdio.h>

//​function​ ​ using​ ​ recursion​ ​ to​ ​ print​ ​ numbers​ ​ from​ ​ n ​ ​ to​ ​ 0
void printNumbers (int n) {

	printf("%d ",n);		//printing the number

	if (n == 0) {
		return;		//start returning
	}
	printNumbers (n - 1);

}


//BEGINNING OF MAIN FUNCTION
int main () {

	int n;					
	printf("Enter n : ");
	scanf("%d", &n);			//asking user to enter the number
	printNumbers(n);			//calling function to print the sequence of numbers from n to 0
	printf("\n");
	return 0;

}
//END OF MAIN FUNCTION