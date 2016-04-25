#ifndef CPP_UTILITIES_H
#define CPP_UTILITIES_H

#include <vector>
using namespace std;

typedef vector<int> int_vec;

//function to print elements in Vector
void print_vector(int_vec &nums);

//function to generate a vector of n elements within range r
void generate_vector(int_vec &nums, int r);

//Function to perform swap two values
void swap_values(int *a, int *b);
#endif