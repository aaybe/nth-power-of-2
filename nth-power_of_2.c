#include <stdio.h>
#include <time.h>

//recursive function to find power of 2
int power_of_2_recursive(int k)
{
    //base case
    if (k == 0)                                
    return 1;
    //recursive case
    else 
    return 2 * power_of_2_recursive(k - 1);        
}

//Iterative function to find power of 2 
int power_of_2_iterative(int k)
{
    int i, power;       
    i = 0;
    power = 1;
    while(i < k){
        power = power * 2;
        i = i + 1;
    }
    return power;
    }

int main()
{
    //declare number to take power of 2 and number of trials to run 
    int num, trials;
    
    //assign value to trials
    printf("Enter the number of trials to run: ");
    scanf("%i", &trials);
    
    //assign value to num
    printf("Enter the number to take the power of 2: ");
    scanf("%i", &num);
    
    //print number of trials to run
    printf("Trial runs: %i\n", trials);
    
    //measure time taken by power_of_2_recursive
    clock_t t;
    t = clock();
    int j = 0;
    for(j; j < trials; j++)
    {
        power_of_2_recursive(num);
    }
    t = clock() - t;
    double time_taken_recursive = ((double)t)/CLOCKS_PER_SEC;
    
    //print time taken by recursive function
    printf("Recursive version: %f\n", time_taken_recursive);
    
    //measure time taken by power_of_2_iterative
    clock_t n;
    n = clock();
    int i = 0;
    for(i; i < trials; i++)
    {
        power_of_2_iterative(num);
    }
    n = clock() - n;
    double time_taken_iterative = ((double)n)/CLOCKS_PER_SEC;
    
    //print time taken by iterative function 
    printf("Iterative version: %lf\n", time_taken_iterative);
    
    //if-else to find which function is more efficient and then print the difference
    if(time_taken_recursive > time_taken_iterative)
    printf("Iteration is more efective by %.4lf sec", time_taken_recursive - time_taken_iterative);
    else
    printf("Recursive is more effective by %.4lf sec", time_taken_iterative - time_taken_recursive);

    return 0;
}