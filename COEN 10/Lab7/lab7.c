/*
 * Vani Aggarwal
 * T 9:15 to 12 PM
 * #35375
 * October 26, 2021
 */

#include <stdio.h>
#include <string.h>
#define SIZE 5

int option, i, j, k; // declare variables
int counter = 0;
int time;
char schedule[SIZE][20];
char name[20];
char letter; 

int main() {
    for (i=0; i<5; i++)
	 schedule[i][0]='\0';

while (1) { // forever loop
    printf("Menu \n 1 - schedule \n 2 - cancel \n 3 - list \n 4 - show names \n 9 - quit\n"); // prints options
    scanf("%d", &option); // user input

switch (option) { 
    case 1 :  // schedule lesson 
	if (counter == 5) {
	    printf("Schedule is full. Come back tomorrow!\n"); 
	} else {
	    for (i=0; i<SIZE; i++) {
		if (schedule[i][0] == '\0') {
		    printf("What is your first name?\n"); // asks user for name
		    scanf("%s", name); // takes input
		    strcpy(schedule[i], name);
		    printf("Lesson scheduled for %s\n", schedule[i]); 
		    counter++;
		    break;
		}
	    }
	}
	break;	
    

    case 2 : // cancel lesson
	if (counter == 0) { // if no lessons scheduled
	    printf("No lessons scheduled!\n"); 
	} else {
		printf("What is the name corresponding to the lesson scheduled?\n"); // asks user their name
		scanf("%s", name); // user input
		for (i = 0; i < SIZE; i++) { // for loop
		    if (strcmp(schedule[i], name) == 0) { // compares 
			 for (j=i+1; j < SIZE; j++) {  // second for loop 
				strcpy(schedule[j-1], schedule[j]); // copies 
			 }
		    	 counter--;	// increments counter down
			 schedule[j][0]='\0'; // places null into canceled 
			 printf("Cancelled!\n");		
			 
	    }   
	}
	}
	break; 
    
    

    case 3 :  // list 
	if (counter == 0) { // no lessons are recorded
	    printf("Schedule is empty.\n");	    
	} else {
	    for (j=0; j<SIZE; j++) {  // loop to transverse array
		if (schedule[j][0] == '\0') {
		    printf("%d pm - free\n", j+1); // prints that time is free
		} else {
		    printf("%d pm - %s\n", j+1, schedule[j]); // prints that time has lesson
		}
	    }

	}
	break; 
    
    case 4 : // show names
	if (counter == 0) { // if there are no lessons scheduled
	    printf("Schedule is empty!\n"); // program will print that schedule is empty
	     
	} else {
		printf("Enter first letter of name: \n"); // asks user for input
		while (getchar() != '\n');
		scanf("%c", &letter);	// user input 
		for (i=0; i<SIZE; i++) { // for loop
		    if (schedule[i][0] == letter) { // compares	
			printf("name: %s\ntime: %d pm\n", schedule[i], i+1); // prints out name and time
			break;
		    }
		if (i==SIZE) { 
		    printf("Name not found.\n"); // prints that names are not found
		 }	    
	    }
	}
	break; 
	 
    case 9 :  // quit
	return 0; // closes program
	break;
    
    default : 
	printf("Bad Option\n"); // not one of options on menu
	break; 
    
}
}
}
