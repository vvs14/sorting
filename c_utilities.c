#include <stdlib.h>	//for rand()
#include <stdio.h>
#include <time.h>
#include "c_utilities.h"

//function to print array
void print_array(int *arr, int size)
{
	int i;
	for(i=0; i<size; i++)
		printf("%d ",arr[i]);
	printf("\n");
}//end print_array

//Function to create array of n integers with range 0 to r-1
int*  generate_array(int n, int r)
{
	int *arr = malloc(n*sizeof(int));
	int i;
	time_t t;
	//Initializing random number generator
	srand((unsigned) time (&t));
	for(i=0; i<n; i++)
		arr[i] = rand()%r;
	return arr;
}//generate_array

//Function to swap two values in Array
void swap_values(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}//swap_in_array()
