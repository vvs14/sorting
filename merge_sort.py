'''
Author: Vivek Vikram Singh
Date : 24-04-16
Python implementation of Insertion sort.
Input ; number of integers(n), range of integers(r)
Ouput : sorted array
Program will generate a random array of "n" integers within range 0 to "r"
and may contain duplicate integerss. 
'''

from utilities import generate_list, print_list

#Mergesort function
def merge_sort(num_list, low, high):
	if low< high:
		mid = low + (high-low)/2
		merge_sort(num_list, low, mid)
		merge_sort(num_list, mid+1, high)
		merge(num_list, low, mid, high)

#Merge function
def merge(num_list, low, mid, high):
	left_els = mid-low+1;
	right_els = high-mid;
	#Calculate the number of elements in each half of list
	left_list = [None]*left_els
	right_list = [None]*right_els
	#copy elements in two sub_lists
	for i in range( left_els):
		left_list[i] = num_list[low+i]
	for i in range(right_els):
		right_list[i] = num_list[mid+1+i]
	in1 =0
	in2 =0
	in3 = low
	#Comparision and writing to num_list
	while in1 <left_els and in2 < right_els:
		if left_list[in1] <= right_list[in2]:
			num_list[in3] = left_list[in1]
			in1 +=1
		else:
			num_list[in3] = right_list[in2]
			in2 +=1
		in3 +=1
	#Copying remaining elements
	while in1 <left_els:
		num_list[in3]= left_list[in1]
		in1 +=1
		in3 +=1
	while in2 <right_els:
		num_list[in3]= right_list[in2]
		in2 +=1
		in3 +=1

if __name__ == '__main__':	# Run this program as standalone program : http://effbot.org/pyfaq/tutor-what-is-if-name-main-for.htm
	n = int(raw_input(" Enter the numnber of ints: "))
	r = int(raw_input("Enter range  of ints : "))
	num_list = generate_list(n,r)
	print "List before sorting : "
	print_list(num_list)
	merge_sort(num_list, 0, n-1)
	print "List after sorting : "
	print_list(num_list)