/*
Author: Vivek Vikram Singh
Date : 30-04-16
C++ implementation of Heap sort.
Input ; number of integers(n), range of integers(r)
Ouput : sorted array
Program will generate a random array of "n" integers within range 0 to "r"
and may contain duplicate integerss. 
Reference : http://www.cs.umd.edu/~meesh/351/mount/lectures/lect13-heapsort.pdf
*/
#include "cpp_utilities.h"
#include <iostream>
using namespace std;

//Heapsort function
void heap_sort(int_vec &nums);
//BuildHeap Function
void build_heap(int_vec &nums);
//MaxHeapfy Function for ascending order sorted array
void max_heapify(int_vec &nums, int root, int size);
// Min Heapify function for descending order sorted array
void min_heapify(int_vec &nums, int root, int size);

int main(int argc, char const *argv[])
{
	int_vec nums;			//vector to store integers.
	int n, r;
	cout<<"Number of ints and range: \n";
	cin>>n>>r;
	nums.resize(n);
	generate_vector(nums, r);
	cout<<"vector before sorting :";
	print_vector(nums);
	heap_sort(nums);
	cout<<"vector sfter sorting :";
	print_vector(nums);
	return 0;
}//main()

void heap_sort(int_vec &nums)
{
	int last_el,size;
	size= nums.size();
	build_heap(nums);
	for(last_el = size-1; last_el>=1; last_el--)
	{
		swap_values(&nums[0], &nums[last_el]);
		max_heapify(nums, 0, last_el);
		//min_heapify(nums, 0, last_el);
	}
}//heap_sort()

void build_heap(int_vec &nums)
{
	int in_node, size;
	size = nums.size();
	for (in_node= size/2 -1; in_node>=0; in_node--)
		max_heapify(nums, in_node, size);
		//min_heapify(nums, in_node, size);
}//build_heap()

void max_heapify(int_vec &nums, int root, int size)
{
	int left, right, max;
	left = 2*root+1;
	right = left+1;
	max = root;
	if( left<size && nums[left] > nums[max])
		max = left;
	if(right<size && nums[right] > nums[max])
		max = right;
	if (max != root)
	{
		swap_values(&nums[max], &nums[root]);
		max_heapify(nums, max, size);
	}
}// max_heapify()

void min_heapify(int_vec &nums, int root, int size)
{
	int left, right, min;
	left = 2*root+1;
	right = left+1;
	min = root;
	if( left<size && nums[left] < nums[min])
		min = left;
	if(right<size && nums[right] < nums[min])
		min = right;
	if (min != root)
	{
		swap_values(&nums[min], &nums[root]);
		min_heapify(nums, min, size);
	}
}// min_heapify()


