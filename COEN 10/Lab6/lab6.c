/*
 * Vani Aggarwal
 * T 9:15 to 12 PM
 * #35375
 * October 26, 2021
 */

#include <stdio.h>
int option, i, j, k; // declare variables
int counter = 0;
int schedule[5] = {0, 0, 0, 0, 0};
int time;

int main()
{
    while (1)
    {                                                                           // forever loop
        printf("Menu \n 1 - schedule \n 2 - cancel \n 3 - list \n 9 - quit\n"); // prints options
        scanf("%d", &option);                                                   // user input

        if (option == 1)
        { // schedule lesson
            if (counter == 5)
            {
                printf("Schedule is full. Come back tomorrow!\n");
            }
            else
            {
                for (i = 0; i < 5; i++)
                {
                    if (schedule[i] == 0)
                    {
                        schedule[i] = 1 + i;
                        printf("Your lesson is at: %d pm\n", schedule[i]); // enter time of lesson in array and output to user
                        counter++;
                        break;
                    }
                }
            }
        }

        else if (option == 2)
        { // cancel lesson
            if (counter == 0)
            { // if no lessons scheduled
                printf("No lessons scheduled!\n");
            }
            else
            {
                printf("What time is your lesson? Enter here, and then enter 3 to check if appointment is cancelled: ");
                scanf("%d", &time);
                if (time > 0 && time < 6 && schedule[time - 1] != 0)
                {
                    schedule[time - 1] = 0;
                    counter--;
                }
                else if (schedule[time - 1] == 0)
                {
                    printf("Time is already free!\n");
                }
                else
                {
                    printf("Not an available time.\n");
                }
            }
        }

        else if (option == 3)
        { // list
            if (counter == 0)
            { // no lessons are recorded
                printf("Schedule is empty.\n");
            }
            else
            {
                for (j = 0; j < 5; j++)
                { // loop to transverse array
                    if (schedule[j] == 0)
                    {
                        printf("%d pm - free\n", j + 1); // prints that time is free
                    }
                    else
                    {
                        printf("%d pm - lesson\n", j + 1); // prints that time has lesson
                    }
                }
            }
        }

        else if (option == 9)
        {             // quit
            return 0; // closes program
        }

        else
        {
            printf("Bad Option\n"); // not one of options on menu
        }
    }
}
