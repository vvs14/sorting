/*
Author: Vivek Vikram Singh
Date : 24-04-16
C implementation of Insertion sort.
Input ; number of integers(n), range of integers(r)
Ouput : sorted array
Program will generate a random array of "n" integers within range 0 to "r"
and may contain duplicate integerss. 
*/
#include "c_utilities.h"
#include <stdio.h>
#include <stdlib.h>

//insertion sort function
void insertion_sort(int *arr, int size);

int main(int argc, char const *argv[])
{
	int n,r;
	int *arr = NULL;	//So that does not access garbage value accidently
	printf("Enter the number of elements and range of numbers respec. : \n");
	scanf("%d %d",&n, &r);
	arr = generate_array(n,r);	//generate array of n number within 0 to r-1
	printf("Array before sorting : \n");
	print_array(arr, n);
	insertion_sort(arr, n);
	printf("Array after sort : \n");
	print_array(arr, n);
	free(arr);
	return 0;
}//main()

void insertion_sort(int *arr, int size)
{
	int pivot,i,j;
	for(i=0; i<size-1; i++)
	{
		j= i+1;
		pivot = arr[j];
		while(j>0 && arr[j-1] > pivot )
		{
			arr[j] = arr[j-1];
			j--;
		}
		arr[j] = pivot;
	}
}// insertion_sort()