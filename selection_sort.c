/*
Author: Vivek Vikram Singh
Date : 23-04-16
C implementation of Selection sort.
Input ; number of integers(n), range of integers(r)
Ouput : sorted array
Program will generate a random array of "n" integers within range 0 to "r"
and may contain duplicate integerss. 
*/

#include "c_utilities.h"
#include <stdio.h>
#include <stdlib.h>

//Selection sort function
void selection_sort(int *arr, int size);

int main(int argc, char const *argv[])
{
	int n,r;
	int *arr = NULL;	//So that does not access garbage value accidently
	printf("Enter the number of elements and range of numbers respec. : \n");
	scanf("%d %d",&n, &r);
	arr = generate_array(n,r);	//generate array of n number within 0 to r-1
	printf("Array before sorting : \n");
	print_array(arr, n);
	selection_sort(arr, n);
	printf("Array after sort : \n");
	print_array(arr, n);
	free(arr);
	return 0;
}//main()

void selection_sort(int *arr, int size)
{
	int i, j, min, min_pos;
	for (i=0; i<size-1; i++)	
	{
		min_pos = i;	// Min pos is taken as I
		min = arr[min_pos];	// Element at min_pos is taken as min element
		for(j=i+1; j<size; j++)	//From next element (to min), go up to last element
		{
			if(arr[j]<min)		// If current element is smaller, take it as min and note pos
			{
				min_pos = j;
				min  = arr[min_pos];
			}
		}
		if(min_pos!= i)	// if element at min_pos is NOT same as i (taken above)
			swap_values(&arr[i], &arr[min_pos]); //swap min with i'th array elemnt	
	}
}//selection_sort()

