#include <iostream>
#include <cstdlib>	//for rand()
#include "cpp_utilities.h"	

using namespace std;

//function to print vector elements
void print_vector(int_vec &nums)
{
	int i, len;
	len = nums.size();
	for(i=0; i<len; i++)
		cout<<nums[i]<<" ";
	cout<<"\n";
}//print_vector

//Function to create array of n integers with range 0 to r-1
void generate_vector(int_vec &nums, int r)
{
	int i, len;
	time_t t;
	len = nums.size();
	//Initializing random number generator
	srand((unsigned) time (&t));
	for(i=0; i<len; i++)
		nums[i] = rand()%r;
}//generate_vector

//Function to perform swap two values
void swap_values(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}//swap_in_vector()