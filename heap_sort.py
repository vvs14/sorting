'''
Author: Vivek Vikram Singh
Date : 30-04-16
Python implementation of Heap sort.
Input ; number of integers(n), range of integers(r)
Ouput : sorted array
Program will generate a random array of "n" integers within range 0 to "r"
and may contain duplicate integerss. 
Reference : http://www.cs.umd.edu/~meesh/351/mount/lectures/lect13-heapsort.pdf
'''

from utilities import generate_list, print_list

#HeapSort Function
def heap_sort(num_list):
	build_heap(num_list)
	size = len(num_list)
	for last_el in range(size-1, 0,-1):
		num_list[0], num_list[last_el] = num_list[last_el], num_list[0]
		max_heapify(num_list, 0, last_el)
		#min_heapify(num_list, 0, last_el)

#Function for build heap
def build_heap(num_list):
 	size = len(num_list)
 	for in_node in range(size/2-1, -1, -1):
 		max_heapify(num_list, in_node, size)
 		#min_heapify(num_list, in_node, size)

#Max heapify function
def max_heapify(num_list, root, size):
	left = 2*root+1
	right = left+1
	maximum = root
	if left <size and num_list[left] > num_list[maximum]:	maximum = left
	if right <size and num_list[right] > num_list[maximum]:	maximum = right
	if not maximum ==root:
		num_list[maximum], num_list[root]= num_list[root], num_list[maximum]
		max_heapify(num_list, maximum, size) 

#Min heapify function
def min_heapify(num_list, root, size):
	left = 2*root+1
	right = left+1
	minimum = root
	if left <size and num_list[left] < num_list[minimum]:	minimum = left
	if right <size and num_list[right] < num_list[minimum]:	minimum = right
	if not minimum ==root:
		num_list[minimum], num_list[root]= num_list[root], num_list[minimum]
		min_heapify(num_list, minimum, size)


if __name__ == '__main__':	# Run this program as standalone program : http://effbot.org/pyfaq/tutor-what-is-if-name-main-for.htm
	n = int(raw_input(" Enter the numnber of ints: "))
	r = int(raw_input("Enter range  of ints : "))
	num_list = generate_list(n,r)
	print "List before sorting : "
	print_list(num_list)
	heap_sort(num_list)
	print "List after sorting : "
	print_list(num_list)