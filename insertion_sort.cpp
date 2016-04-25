/*
Author: Vivek Vikram Singh
Date : 24-04-16
C++ implementation of Insertion sort.
Input ; number of integers(n), range of integers(r)
Ouput : sorted array
Program will generate a random array of "n" integers within range 0 to "r"
and may contain duplicate integerss. 
*/
#include "cpp_utilities.h"
#include <iostream>
using namespace std;

//Insertion sort function
void insertion_sort(int_vec &nums);

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
	insertion_sort(nums);
	cout<<"vector sfter sorting :";
	print_vector(nums);
	return 0;
}//main()

void insertion_sort(int_vec &nums)
{
	int i, j, pivot, size = nums.size();
	for(i=0; i<size-1; i++)
	{
		j= i+1;
		pivot = nums[j];
		while( j>0 && nums[j-1] >pivot)
		{
			nums[j] = nums[j-1];
			j--;
		}
		nums[j]= pivot;
	}
}// insertion_sort()