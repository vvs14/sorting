/*
Author: Vivek Vikram Singh
Date : 30-04-16
C implementation of Heap sort.
Input ; number of integers(n), range of integers(r)
Ouput : sorted array
Program will generate a random array of "n" integers within range 0 to "r"
and may contain duplicate integerss. 
Reference : http://www.cs.umd.edu/~meesh/351/mount/lectures/lect13-heapsort.pdf
*/
#include "c_utilities.h"
#include <stdio.h>
#include <stdlib.h>

//Heapsort function
void heap_sort(int *arr, int size);
//BuildHeap Function
void build_heap(int *arr, int size);
//MaxHeapfy Function for ascending order sorted array
void max_heapify(int *arr, int root, int size);
// Min Heapify function for descending order sorted array
void min_heapify(int *arr, int root, int size);

int main(int argc, char const *argv[])
{
	int n,r;
	int *arr = NULL; 	//So that does not access garbage value accidently
	printf("Enter the number of elements and range of numbers respec. : \n");
	scanf("%d %d",&n, &r);
	arr = generate_array(n,r);	//generate array of n number within 0 to r-1
	printf("Array before sorting : \n");
	print_array(arr, n);
	heap_sort(arr, n);
	printf("Array after sort : \n");
	print_array(arr, n);
	return 0;
}//main()


void heap_sort(int *arr, int size)
{
	int last_el;
	build_heap(arr, size);		//first of all, build the heap
	for(last_el = size-1; last_el>=1; last_el--)
	{
		//printf("Swapping values at 0 : %d and at %d  : %d \n", arr[0], last_el, arr[last_el]);
		swap_values(&arr[0], &arr[last_el]);	//arr[0] is root element heap
		max_heapify(arr, 0, last_el);	//heapify with s
		//min_heapify(arr, 0, last_el);
	}
}//heap_sort()

void build_heap(int *arr, int size)
{
	int in_node;
	for( in_node= (size/2) -1; in_node>=0; in_node--)	//arr[size/2 -1] is bottom most internal node which has at least 1 child.
		max_heapify(arr, in_node, size);	//heapify the each internal node one by one
		//min_heapify(arr, in_node, size);	//heapify the each internal node one by one
}// build_heap()

void max_heapify(int *arr, int root, int size)
{
	int left, right, max;
	left = 2* root +1;
	right = left+1;
	max = root;
	//comparision to get position of max element
	if (left<size && arr[left] > arr[max])
		max = left;
	if (right<size && arr[right] > arr[max])
		max = right;
	if( max != root)	//if max has been changed from root to one of its children
	{
		//printf("Swapping values at  %d  :  %d and at %d  : %d \n", max, arr[max], root, arr[root]);
		swap_values(&arr[max], &arr[root]);	//swap those values
		max_heapify(arr, max, size);	//heapify that child
	}
}//max_heapify()

void min_heapify(int *arr, int root, int size)
{
	int left, right, min;
	left = 2* root +1;
	right = left+1;
	min = root;
	//comparision to get position of max element
	if (left<size && arr[left] < arr[min])
		min = left;
	if (right<size && arr[right] < arr[min])
		min = right;
	if( min != root)	//if max has been changed from root to one of its children
	{
		//printf("Swapping values at  %d  :  %d and at %d  : %d \n", min, arr[min], root, arr[root]);
		swap_values(&arr[min], &arr[root]);	//swap those values
		min_heapify(arr, min, size);	//heapify that child
	}
}//min_heapify()