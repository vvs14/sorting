'''
Author: Vivek Vikram Singh
Date : 1-05-16
Python implementation of Quick sort.
Input ; number of integers(n), range of integers(r)
Ouput : sorted array
Program will generate a random array of "n" integers within range 0 to "r"
and may contain duplicate integerss. 
read README.md for correct compilation and execution procedures of these programs.
'''

from utilities import generate_list, print_list

#Partition function
def partition(num_list, low, high):
	left = low
	pivot = num_list[left]	#pivot is chosen as left most element of array
	for right in range(left+1, high+1):
		if num_list[right] < pivot:
			left+=1
			num_list[left], num_list[right] = num_list[right], num_list[left]
	num_list[left], num_list[low] = num_list[low], num_list[left]
	return left

#Quick sort
def quick_sort(num_list, low, high):
	if low < high:
		pos = partition(num_list, low, high)
		quick_sort(num_list, low, pos-1)
		quick_sort(num_list, pos+1, high)

if __name__ == '__main__':	# Run this program as standalone program : http://effbot.org/pyfaq/tutor-what-is-if-name-main-for.htm
	n = int(raw_input(" Enter the numnber of ints: "))
	r = int(raw_input("Enter range  of ints : "))
	num_list = generate_list(n,r)
	print "List before sorting : "
	print_list(num_list)
	quick_sort(num_list, 0, n-1)
	print "List after sorting : "
	print_list(num_list)