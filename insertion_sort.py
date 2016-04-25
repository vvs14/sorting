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

#Insertion sort function
def insertion_sort(numlist):
	size = len(numlist)
	for i in range(size-1):
		j= i+1;
		pivot = numlist[j]
		while j>0 and numlist[j-1]>pivot:
			numlist[j] = numlist[j-1]
			j -= 1
		numlist[j] = pivot

if __name__ == '__main__':	# Run this program as standalone program : http://effbot.org/pyfaq/tutor-what-is-if-name-main-for.htm
	n = int(raw_input(" Enter the numnber of ints: "))
	r = int(raw_input("Enter range  of ints : "))
	num_list = generate_list(n,r)
	print "List before sorting : "
	print_list(num_list)
	insertion_sort(num_list)
	print "List after sorting : "
	print_list(num_list)