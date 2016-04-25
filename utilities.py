from random import randint

#utility function to generate list of random n numbers between 0 and r
def generate_list(n, r):
	nums = list()
	for i in range(n):
		nums.append(randint(0,r))
	return nums

#utility function to print list
def print_list(l):
	for obj in l:
		print obj,"",
	print 
