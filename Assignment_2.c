#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{

int SIZE=100;
// Create a child process
int state = fork();

// Error occurred
if (state < 0)
{
    printf("Fork failed\n");
    return -1;
}

// Generate an array of random integers
int array[SIZE];
for (int i = 0; i < SIZE; i++)
  array[i] = rand();


// Calculate the average of even numbers for the parent process
if (state > 0)
{
    int sum_of_evens=0 , ecount=0;
    for (int i = 0; i < SIZE; i++)
    {
        if (array[i] % 2 == 0)
        {
            sum_of_evens+= array[i];
            ecount++;
        }
    }
    
    double avg_of_evens = (double)sum_of_evens / ecount;
    printf("The average of even numbers is: %lf\n", avg_of_evens);
}
// Calculate the average of odd numbers for the child process
else
{
    int sum_of_odds=0, ocount = 0;
    for (int i = 0; i < SIZE; i++)
    {
        if (array[i] % 2 == 1)
        {
            sum_of_odds+=array[i];
            ocount++;
        }
    }
    double avg_of_odds = (double)sum_of_odds / ocount;
    printf("The average of odd numbers is: %lf\n", avg_of_odds);
}

return 0;

}
