/*
Author: Vivek Vikram Singh
Date : 24-04-16
C implementation of Merge sort.
Input ; number of integers(n), range of integers(r)
Ouput : sorted array
Program will generate a random array of "n" integers within range 0 to "r"
and may contain duplicate integerss. 
Read README.md for compilation and execution procedure.
*/
#include "c_utilities.h"
#include <stdio.h>
#include <stdlib.h>

//MergeSort sort function
void merge_sort(int *arr, int low, int high);
//MergeFunction
void merge(int *arr, int low, int mid, int high);

int main(int argc, char const *argv[])
{
	int n,r;
	int *arr = NULL;	//So that does not access garbage value accidently
	printf("Enter the number of elements and range of numbers respec. : \n");
	scanf("%d %d",&n, &r);
	arr = generate_array(n,r);// DO NOT FORGET the deallocate the memory allocated by "new" or "malloc"
	printf("Array before sorting : \n");
	print_array(arr, n);
	merge_sort(arr, 0, n-1);
	printf("Array after sort : \n");
	print_array(arr, n);
	free(arr);
	return 0;
}//main()

void merge_sort(int *arr, int low, int high)
{
	if(low<high)	//At least two elements in array
	{
		int mid = low + (high-low)/2;
		merge_sort(arr, low, mid);
		merge_sort(arr, mid+1, high);
		merge(arr, low, mid, high);
	}
}// merge_sort()

void merge(int *arr, int low, int mid, int high)
{
	int left_els, right_els, in1, in2, in3;
	int i;
	left_els = mid-low+1;
	right_els = high-mid;
	int *left_arr = malloc(left_els*sizeof(int));// DO NOT FORGET the deallocate the memory allocated by "new" or "malloc"
	int *right_arr = malloc(right_els*sizeof(int));// DO NOT FORGET the deallocate the memory allocated by "new" or "malloc"
	//Copying into two sub arrays, so that original array can be over-written
	for(i=0; i<left_els; i++)
		left_arr[i] = arr[low+i];
	for(i=0; i<right_els; i++)
		right_arr[i] = arr[ mid +1+i];

	//Initializing the indexes
	in1=0;
	in2=0;
	in3 = low;
	//Comparision and Writing
	while(in1 < left_els && in2 <right_els)
	{
		if(left_arr[in1] <=right_arr[in2])
		{
			arr[in3] = left_arr[in1];
			in1++;
		}
		else
		{
			arr[in3] = right_arr[in2];
			in2++;
		}
		in3++;
	}

	while(in1<left_els)
	{
		arr[in3] = left_arr[in1];
		in1++;
		in3++;
	}

	while(in2<right_els)
	{
		arr[in3] = right_arr[in2];
		in2++;
		in3++;
	}
	// DO NOT FORGET the deallocate the memory allocated by "new" or "malloc"
	free(left_arr);
	free(right_arr);
}//merge()