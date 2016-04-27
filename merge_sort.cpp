/*
Author: Vivek Vikram Singh
Date : 24-04-16
C++ implementation of Merge sort.
Input ; number of integers(n), range of integers(r)
Ouput : sorted array
Program will generate a random array of "n" integers within range 0 to "r"
and may contain duplicate integerss. 
*/
#include "cpp_utilities.h"
#include <iostream>
using namespace std;

//merge sort function
void merge_sort(int_vec &nums, int low, int high);
//merge function
void merge(int_vec &nums, int low, int mid, int high);

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
	merge_sort(nums, 0, n-1);
	cout<<"vector sfter sorting :";
	print_vector(nums);
	return 0;
}//main()

void merge_sort(int_vec &nums, int low, int high)
{
	if(low<high)	//At least two elements in array
	{
		int mid = low + (high-low)/2;
		merge_sort(nums, low, mid);
		merge_sort(nums, mid+1, high);
		merge(nums, low, mid, high);
	}
}// merge_sort()

void merge(int_vec &nums, int low, int mid, int high)
{
	int left_els, right_els, in1, in2, in3;
	int i;
	left_els = mid-low+1;
	right_els = high-mid;
	//Creating two sub-vectors
	int_vec left_sub, right_sub;
	left_sub.resize(left_els);
	right_sub.resize(right_els);
	//Copying into two sub arrays, so that original array can be over-written
	for(i=0; i<left_els; i++)
		left_sub[i] = nums[low+i];
	for(i=0; i<right_els; i++)
		right_sub[i] = nums[ mid +1+i];
	//Initializing the indexes
	in1=0;
	in2=0;
	in3 = low;
	//Comparision and Writing
	while(in1 < left_els && in2 <right_els)
	{
		if(left_sub[in1] <=right_sub[in2])
		{
			nums[in3] = left_sub[in1];
			in1++;
		}
		else
		{
			nums[in3] = right_sub[in2];
			in2++;
		}
		in3++;
	}
	//Copying remaning parts of left ans right sub arrays, repectively
	while(in1<left_els)
	{
		nums[in3] = left_sub[in1];
		in1++;
		in3++;
	}
	while(in2<right_els)
	{
		nums[in3] = right_sub[in2];
		in2++;
		in3++;
	}
}//merge()

