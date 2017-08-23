/*

    * Name     : Kuldeep Singh Bhandari
    * Roll No. : 111601009
    * Aim      : check if the given string is palindrome or not
    * Date     : 22-08-2017

*/

#include<stdio.h>

int flag = 0;			//global variable flag

//function to check if given string is palindrome or not
int checkPalindrome (char *array, int i, int n) {

	if (i <= n) {

		if (array[i] == array[n]) {
			flag = 1;
		}
		else {
			flag = 0;
			return 0;
		}
		flag = checkPalindrome (array, i + 1, n - 1);		//using recursion of function
		return flag;				//returning flag

	}
	else {
		return flag;				//returning flag when i > n
	}

}

//MAIN FUNCTION BEGINS HERE
int main () {

	int n;
	char array[100];

	printf("Enter the number of terms in the string : (MAX. 100)\n");
	scanf("%d", &n);			//asking user to input the number of elements in the string
	printf("Enter %d elements of the string : \n", n);
	scanf("%s", array);			//asking user to input the string of n elements

	if (checkPalindrome(array, 0, n - 1)) {			//checking when given string is palindrome or not
		printf("STRING '%s' is a Palindrome.\n", array);
	}
	else {
		printf("STRING '%s' is not a Palindrome.\n", array);
	}
	return 0;			//returning 0 

}
//MAIN FUNCTION ENDS HERE