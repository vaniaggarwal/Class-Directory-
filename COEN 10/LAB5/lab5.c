/*
 * Vani Aggarwal
 * T 9:15 to 12 AM
 * #35375
 * 10/19/21
 */
#include <stdio.h>
#include <stdlib.h> // for rand() and srand()
#include <time.h> // time()
int main() {
    int number1, number2, product; // declare variables
    int i; // declare variable
    int counter = 0; // declare and initialize counter
    srand((int) time (NULL)); // seeds 
    for (i=0; i < 10; i++) { // start of for loop repeated 10 times
	      int number1 = rand() % 13; // generates first random number between 0 and 12
	      int number2 = rand() % 13; // generates second random number between 0 and 12
	      printf("Enter the product of the following two numbers: %d x %d\n", number1, number2); // prompts user input 
	      scanf("%d", &product); // user inputs product

    	if (number1 * number2 == product) {  // start of if statement
    	    printf("Correct! Good Job!\n"); // outputs if correct 
    	    counter += 1; // counter = counter + 1
    	} else {
    	    printf("Oops! That's Wrong. The Correct Answer is: "); 
    	    product = number1 * number2;
    	    printf("%d\n", product); // outputs correct answer 
    	  }
  	}	
  
      counter = counter * 10;
      printf("Score (in percent): %d%%", counter); // outputs score in percentage
}
