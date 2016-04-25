'''
Author: Vivek Vikram Singh
Date : 24-04-16
Python implementation of Bubble sort.
Input ; number of integers(n), range of integers(r)
Ouput : sorted array
Program will generate a random array of "n" integers within range 0 to "r"
and may contain duplicate integerss. 
'''
from utilities import generate_list, print_list

#Function for Bubble Sort
def bubble_sort(nums):
	size = len(nums)
	for i in range(size):
		#print "i : ",i
		swapped = False
		for j in range(size-i-1):
			#print "j :",j,
			if nums[j] >nums[j+1]:
				swapped = True
				nums[j], nums[j+1] = nums[j+1], nums[j]
		if swapped==False:	break

if __name__ == '__main__':	# Run this program as standalone program : http://effbot.org/pyfaq/tutor-what-is-if-name-main-for.htm
	n = int(raw_input(" Enter the numnber of ints: "))
	r = int(raw_input("Enter range  of ints : "))
	num_list = generate_list(n,r)
	print "List before sorting : "
	print_list(num_list)
	bubble_sort(num_list)
	print "List after sorting : "
	print_list(num_list)