/*
Author: Vivek Vikram Singh
Date : 01-05-16
C++ implementation of Quick sort.
Input ; number of integers(n), range of integers(r)
Ouput : sorted array
Program will generate a random array of "n" integers within range 0 to "r"
and may contain duplicate integerss. 
read README.md for correct compilation and execution procedures of these programs.
*/

#include "cpp_utilities.h"
#include <iostream>
using namespace std;

//Partition function
int partition (int_vec &nums, int low, int high);
//Quick Sort
void quick_sort(int_vec &nums, int low, int high);

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
	quick_sort(nums,0,n-1);
	cout<<"vector sfter sorting :";
	print_vector(nums);
	return 0;
}//main()

int partition(int_vec &nums, int low, int high)
{
	int left, right, pivot;
	left = low;
	pivot = nums[left];	//pivot is chosen as left most element of array
	for( right = left+1; right<=high; right++)
	{
		if( nums[right]< pivot)
		{
			left++;
			swap_values(&nums[left], &nums[right]);
		}
	}
	swap_values(&nums[low], &nums[left]);
	return left;
}//partition()

void quick_sort(int_vec &nums, int low, int high)
{
	if(low<high)
	{
		int pos = partition(nums, low, high);
		quick_sort(nums, low, pos-1);
		quick_sort(nums, pos+1, high);
	}
}//quick_sort()