/*
Author: Vivek Vikram Singh
Date : 01-05-16
C implementation of Quick sort.
Input ; number of integers(n), range of integers(r)
Ouput : sorted array
Program will generate a random array of "n" integers within range 0 to "r"
and may contain duplicate integerss. 
read README.md for correct compilation and execution procedures of these programs.
*/
#include "c_utilities.h"
#include <stdio.h>
#include <stdlib.h>

// Partition function
int partition(int *arr, int low, int high);
//Quick sort functiom
void quick_sort(int *arr, int low, int high);

int main(int argc, char const *argv[])
{
	int n,r;
	int *arr = NULL;
	printf("Enter the number of elements and range of numbers respec. : \n");
	scanf("%d %d",&n, &r);
	arr = generate_array(n,r);	//generate array of n number within 0 to r-1
	printf("Array before sorting : \n");
	print_array(arr, n);
	quick_sort(arr, 0, n-1);
	printf("Array after sort : \n");
	print_array(arr, n);
	return 0;
}//main()


int partition(int *arr, int low, int high)
{
	int left, right, pivot;	//two indexes
	left = low; //left index initialized to low
	pivot = arr[left];	//pivot is initialized to arr[low]
	for (right = left+1; right<=high; right++)	//right index start from left +1 and goes up to high
	{
		if (arr[right] < pivot)
		{
			left++;
			swap_values(&arr[left], &arr[right]);
		}
	}
	swap_values(&arr[low], &arr[left]);
	return left;
}//partition()

void quick_sort(int *arr, int low, int high)
{
	if(low<high)
	{
		int pos = partition(arr, low, high);
		quick_sort(arr, low, pos-1);
		quick_sort(arr, pos+1, high);
	}
}//quick_sort()