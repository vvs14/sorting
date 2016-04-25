/*
Author: Vivek Vikram Singh
Date : 23-04-16
C implementation of Selection sort.
Input ; number of integers(n), range of integers(r)
Ouput : sorted array
Program will generate a random array of "n" integers within range 0 to "r"
and may contain duplicate integerss. 
*/
#include "cpp_utilities.h"
#include <iostream>
using namespace std;

//Selection sort function
void selection_sort(int_vec &nums);

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
	selection_sort(nums);
	cout<<"vector sfter sorting :";
	print_vector(nums);
	return 0;
}//main()

void selection_sort(int_vec &nums)
{
	int min, min_pos, i, j;
	int size = nums.size();
	for(i=0; i<size-1; i++)
	{
		min_pos = i;
		min = nums[min_pos];
		for(j=i+1; j<size; j++)
		{
			if (nums[j]<min)
			{
				min_pos = j;
				min = nums[min_pos];
			}
		}
		if (min_pos !=i)
			swap_values(&nums[min_pos], &nums[i]);
	}
}// selection_sort()
