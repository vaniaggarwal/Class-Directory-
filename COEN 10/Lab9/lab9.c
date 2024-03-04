/*
 * Vani Aggarwal
 * T 9:15 to 12 PM
 * #35375
 * November 16, 2021
 */

#include <stdio.h>
#include <string.h>
#define SIZE 5

// function prototypes
void schedule_time(void);
void cancel(void);
void list(void);
void letter_search(void);
void group(void);
int countletter(char);
int priority(void);

// declare globalized variables
int counter = 0;
char schedule[SIZE][20];
char phone[SIZE][11];
char name[20];
int groups[5];

int main()
{
	char userletter;
	int i, j;
	int number;
	int priority_flag = 0;
	for (i = 0; i < 5; i++)
		schedule[i][0] = '\0';
	for (i = 0; i < SIZE; i++)
		groups[i] = 0;

	while (1)
	{ // forever loop
		int option;
		printf("Menu \n 1 - schedule \n 2 - cancel \n 3 - list \n 4 - show names \n 5 - show groups \n 6 - priority \n 7 - count letters \n 9 - quit\n"); // prints options
		scanf("%d", &option);																															  // user input

		switch (option)
		{
		case 1: // schedule
			schedule_time();
			break;
		case 2: // cancel
			cancel();
			break;
		case 3: // list
			list();
			break;
		case 4: // show names
			letter_search();
			break;
		case 5: // show groups
			group();
			break;
		case 6: // priority
			if (priority_flag == 0)
			{
				priority_flag = priority();
				break;
			}
			else
			{
				printf("Priority already used. Can only be used once.\n");
			}
			break;
		case 7: // count letters
			printf("Enter a letter to see how many times it is repeated:\n");
			scanf(" %c", &userletter);
			number = countletter(userletter);
			printf("The number of times %c is repeated is %d times.\n", userletter, number);
			break;
		case 9: // quit
			return 0;
			break;
		default:					// if none of the cases
			printf("Bad Option\n"); // not one of options on menu
			break;
		}
	}
}

void schedule_time(void)
{						  // function definition for case 1
	char phone_number[8]; // variables
	int i, j, group_size;
	int flag = 1;

	if (counter == 5)
	{ // if shcedule is full
		printf("Schedule is full. Come back tomorrow!\n");
	}
	else
	{
		printf("What's your first name?\n");
		scanf("%s", &name);
		for (i = 0; i < SIZE; i++)
		{
			if (strcmp(schedule[i], name) == 0)
			{
				flag = 0;
				printf("That name is already scheduled\n");
				break;
			}
		}

		if (flag == 1)
		{
			printf("How many people? Minimum of 1 and Maximum of 4\n");
			scanf("%d", &group_size);
			if (group_size > 0 && group_size < 5)
			{
				printf("Enter your phone number:\n");
				scanf("%s", phone_number);
				for (j = 0; j < strlen(phone_number); j++)
				{ // for loop to copy input to array for phone number
					phone[counter][j] = phone_number[j];
				}
				groups[counter] = group_size;

				for (j = 0; j < strlen(name); j++)
				{
					schedule[counter][j] = name[j];
				}
				printf("Lesson scheduled for %s at %d PM. \n", schedule[counter], counter + 1);
				counter++;
			}
			else
			{
				printf("Not a valid group size! Must be between 1 and 4\n");
			}
		}
	}
	return;
}

void cancel(void)
{
	int i, j;
	if (counter == 0)
	{ // no lessons scheduled
		printf("No lessons scheduled!\n");
	}
	else
	{
		char name[20];

		printf("What is the name corresponding to the lesson scheduled?\n"); // asks for name
		scanf("%s", name);													 // user input
		for (i = 0; i < SIZE; i++)
		{ // for loop
			if (strcmp(schedule[i], name) == 0)
			{ // compares
				for (j = i + 1; j < counter; j++)
				{
					strcpy(schedule[j - 1], schedule[j]);
					strcpy(phone[j - 1], phone[j]);
					groups[j - 1] = groups[j];
					printf("%s's party of %d has changed to %d PM. Phone number is %s.\n", schedule[j], groups[j], j, phone[j]); // j+1, j
				}
				counter--;
				schedule[counter][0] = '\0';
				printf("Cancelled!\n");
				break;
			}
		}
	}
	if (i == SIZE)
	{
		printf("That name does not correspond to a scheduled time.\n");
	}
}

void list(void)
{ // lists names, phone numbers, and group size
	int i;
	if (counter == 0)
	{ // if no lessons are scheduled
		printf("Schedule is empty\n");
	}
	else
	{
		for (i = 0; i < SIZE; i++)
		{
			if (schedule[i][0] == '\0')
			{
				printf("%d PM - free\n", i + 1); // prints that time is free
			}
			else
			{
				printf("%d PM is booked by %s. Phone number is %s. Group size is %d\n", i + 1, schedule[i], phone[i], groups[i]); // prints that time has lesson
			}
		}
	}
	return;
}

void letter_search(void)
{
	char letter;
	int i;
	if (counter == 0)
	{									// if no lessons are scheduled
		printf("Schedule is empty!\n"); // program will print that schedule is empty
	}
	else
	{
		printf("Enter first letter of name: \n"); // asks for user input
		while (getchar() != '\n')
			;
		scanf("%c", &letter); // user input
		for (i = 0; i < SIZE; i++)
		{ // for loop
			if (schedule[i][0] == letter)
			{														   // compares
				printf("name: %s\ntime: %d PM\n", schedule[i], i + 1); // prints out name and time
			}
			if (i == SIZE)
			{
				printf("Name not found.\n"); /// prints that names are not found
			}
		}
	}
	return;
}

void group(void)
{
	int i, number;
	if (counter == 0)
	{ // if no lessons scheduled
		printf("Schedule is empty!\n");
	}
	else
	{
		printf("Input number to find group size that matches!\n"); // prompts user input
		scanf("%d", &number);									   // user input

		for (i = 0; i < SIZE; i++)
		{
			if (groups[i] == number && schedule[i][0] != '\0')
			{
				printf("%s's party of %d is scheduled for %d PM\n", schedule[i], groups[i], i + 1);
			}

			if (i == SIZE)
			{
				printf("No groups of that number found.\n");
			}
		}
	}
	return;
}

int countletter(char userletter)
{ // count letters function
	int i;
	char *p;
	int countofletters = 0;
	for (i = 0; i < SIZE; i++)
	{
		p = schedule[i];
		while (*p != '\0')
		{
			if (*p == userletter)
				countofletters++;
			p++;
		}
	}
	return countofletters;
}

int priority(void)
{
	char phone_number[8];
	int i, j, group_size;
	int flag = 0;

	printf("What's your first name?\n");
	scanf("%s", &name);

	for (i = 0; i < SIZE; i++)
	{
		if (strcmp(schedule[i], name) == 0)
		{
			printf("That name is already scheduled.\n");
			return 0;
		}
	}

	if (strcmp(schedule[i], name) != 0)
	{
		printf("How many people? Minimum of 1 and Maximum of 4\n");
		scanf("%d", &group_size);
		if (group_size > 0 && group_size < 5)
		{
			printf("Enter your phone number:\n");
			scanf("%s", phone_number);

			if (counter == 5)
			{
				printf("%s's party of %d has been cancelled. Phone number is %s.\n", schedule[4], groups[4], phone[4]);
				for (i = 0; i < 20; i++)
				{
					schedule[4][i] = '\0';
					groups[4] = 0;
					phone[4][i] = '\0';
				}
			}

			for (j = 3; j >= 0; j--)
			{
				strcpy(schedule[j + 1], schedule[j]);
				strcpy(phone[j + 1], phone[j]);
				groups[j + 1] = groups[j];
				if (schedule[j][0] != '\0')
					printf("%s's party of %d has changed to %d PM. Phone number is %s.\n", schedule[j], groups[j], j + 2, phone[j]);
			}

			for (j = 0; j < strlen(phone_number); j++)
			{
				phone[0][j] = phone_number[j];
			}

			groups[0] = group_size;

			for (j = 0; j < strlen(name); j++)
			{
				schedule[0][j] = name[j];
			}

			printf("Lesson scheduled for %s at 1 PM.\n", schedule[0]);

			if (counter < 5)
			{
				counter += 1;
			}

			return 1;
		}
		else
		{
			printf("Not a valid group size! Must be between 1 and 4.\n");
			return 0;
		}
	}
}
