/*
Author: Vivek Vikram Singh
Date : 24-04-16
C++ implementation of Bubble sort.
Input ; number of integers(n), range of integers(r)
Ouput : sorted array
Program will generate a random array of "n" integers within range 0 to "r"
and may contain duplicate integerss. 
*/

#include "cpp_utilities.h"
#include <iostream>
#include <cstdbool>	//USE FLAG "-std=c++11" WHILE COMPILATION FOR THIS HEADER FILE TO WORk
using namespace std;

//Function for bubble sort
void bubble_sort(int_vec &nums);

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
	bubble_sort(nums);
	cout<<"vector sfter sorting :";
	print_vector(nums);
	return 0;
}//main()

void bubble_sort(int_vec &nums)
{
	int i,j, size= nums.size();
	bool swapped;
	for(i=0; i<size; i++)
	{
		swapped = false;
		for(j=0; j<size-i-1; j++)
		{
			if( nums[j] >nums[j+1])
			{
				swapped = true;
				swap_values(&nums[j], &nums[j+1]);
			}
		}
		if(swapped==false)
			break;
	}
}//bubble_sort()