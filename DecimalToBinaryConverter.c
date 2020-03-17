/*
 ============================================================================
 Name        : DecimalToBinary.c
 Author      : Tyler Blanchard
 Description : Decimal to 2's complement converter
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void magnitudeToBinary(int n, char arr[], int numOfBits);
void flipBits(char arr[], int numOfBits);
void addOne(char arr[], int numOfBits);


int main(void) {
	setvbuf(stdout, NULL, _IONBF, 0);

	//Declare a char array with size 16 to simulate 16-bit binary
	int numOfBits = 16;
	char arr[numOfBits + 1];
	arr[numOfBits] = '\0'; //set the terminating character
	//Declare integer n to hold the decimal integer
	int n = 0;

	puts("Enter integers and convert it to 2's complement binary.");
	puts("Non-numeric input terminates program.");

	//Continually taking input and convert it to binary
	while (scanf("%d", &n) == 1) {//if successfully read in ONE decimal integer
		//Initialize the char array to all 0s (leave the terminating character unchanged)
		for(int i = 0; i < numOfBits; i ++){
			arr[i] = '0';
		}

		//Convert magnitude (absolute value) to binary
		magnitudeToBinary(abs(n), arr, numOfBits);

		//if the number is negative: flip all bits, then add 1.
		if(n < 0){
			//Flip all bits in char arr
			flipBits(arr, numOfBits);
			//Add 1
			addOne(arr, numOfBits);
		}

		//Output binary:
		printf("Integer: %d, 2's complement binary: %s\n", n, arr);

	}

	return EXIT_SUCCESS;
}
/* addOne: arithmatically add 1 to the binary simulated by character array
 * INPUT: 	char arr[]: the character array holding the binary
 * 			int numOfBits: the number of bits in the binary
 * */
void addOne(char arr[], int numOfBits){
	/* True table
	 * ******************************
	 * carry arr[i]	|  arr[i] carry
	 * 	1		0	|	1		0
	 * 	1		1	|	0		1
	 * 	0		0	|	0		0
	 * 	0		1	|	1		0
	 * *********************************/
	char carry = '1';
	for(int i = numOfBits - 1; i >= 0; i --){
		if(carry != arr[i]){
			arr[i] = '1';
			carry = '0';
		}
		else if(carry == '1'){
			arr[i] = '0';
		}
		else{
			arr[i] = '0';
		}
	}
	return;
}
/* flipBits: perform 1's complement on the binary, i.e., change 1 to 0, 0 to 1
 * INPUT:	char arr[]: the character array holding the binary
 * 			int numOfBits: the number of bits in the binary *
 * */
void flipBits(char arr[], int numOfBits){
	for (int i = 0; i < numOfBits; i++) {
	    if (arr[i] == '1') {
	        arr[i] = '0';
	    }
	    else {
	       arr[i] = '1'; 
	    }
	}


	return;
}
/* magnitudeToBinary: 	Convert a non-negative decimal integer to binary (stored in a char array)
 * 						using division-remaider algorithm
 * INPUT:	int n: The decimal integer number to be converted
 * 			char arr[]: the character array holding the binary
 * 			int numOfBits: the number of bits in the binary *
 * */
void magnitudeToBinary(int n, char arr[], int numOfBits){
      
    int remainder;
    
    for(int i = numOfBits - 1; i >= 0; i--) {
	
	remainder = n % 2;
	
	arr[i] = remainder + 48;
	
	n = n / 2; 

}
	return;
}