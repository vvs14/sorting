/*
Author: Vivek Vikram Singh
Date : 24-04-16
C implementation of Bubble sort.
Input ; number of integers(n), range of integers(r)
Ouput : sorted array
Program will generate a random array of "n" integers within range 0 to "r"
and may contain duplicate integerss. 
*/

#include "c_utilities.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> //USE FLAG "-std=c11" WHILE COMPILATION FOR THIS HEADER FILE

//Bubble sort function
void bubble_sort(int *arr, int size);

int main(int argc, char const *argv[])
{
	int n,r;
	int *arr = NULL;	//So that does not access garbage value accidently
	printf("Enter the number of elements and range of numbers respec. : \n");
	scanf("%d %d",&n, &r);
	arr =generate_array(n, r);	//generate array of n number within 0 to r-1
	printf("Array before sorting : \n");
	print_array(arr, n);
	bubble_sort(arr, n);
	printf("Array after sort : \n");
	print_array(arr, n);
	free(arr);
	return 0;
}//main()

void bubble_sort(int *arr, int size)
{
	int i,j;
	bool swapped;
	for(i=0; i<size; i++)//size number of passes
	{	
		swapped=false;
		for(j=0; j<size-i-1; j++)// Observe in any example, in each pass, "size-i-1" elements are compared
		{
			if (arr[j] > arr[j+1] )
			{
				swapped = true;
				swap_values(&arr[j], &arr[j+1]); 
			}
		}
		if(swapped==false)
			break;
	}
}//bubble_sort()