'''
Author: Vivek Vikram Singh
Date : 23-04-16
Python implementation of Selection sort.
Input ; number of integers(n), range of integers(r)
Ouput : sorted array
Program will generate a random array of "n" integers within range 0 to "r"
and may contain duplicate integerss. 
'''
from utilities import generate_list, print_list

#Selection sort function of "num_list" list of ints
def selection_sort(num_list):
	list_len = len(num_list)	#get the length of list of ints
	for i in range(list_len-1):	# Loop from 0 to 2nd last min_el
		min_pos = i 			# Take i'th as min element position
		min_el = num_list[min_pos]	# min element at position  "min_pos"
		for j in range(i+1, list_len):	#start from next element to last elemnt of list
			if num_list[j] < min_el:	#find the min element and its position
				min_pos = j
				min_el = num_list[min_pos]
		if min_pos != i:	#if min element is NOT same as taken initially, then swap
			num_list[i], num_list[min_pos] = num_list[min_pos], num_list[i]

if __name__ == '__main__':	# Run this program as standalone program : http://effbot.org/pyfaq/tutor-what-is-if-name-main-for.htm
	n = int(raw_input(" Enter the numnber of ints: "))
	r = int(raw_input("Enter range  of ints : "))
	num_list = generate_list(n,r)
	print "List before sorting : "
	print_list(num_list)
	selection_sort(num_list)
	print "List after sorting : "
	print_list(num_list)