Sorting algorithms and application implementation in C, C++, Java and Python.

---> In almost all programs, we take INPUT Number of elements (n), range of numbers (r)  to generate an array/vector/list of "n" integers within range "0" to "r-1".

--->In windows, you need to install GCC compiler. Easy way to install it is to install CodeBlocks IDE and set path to gcc in Windows Path variable.

--->Additional Files for Program Compilation and Execution

C : c_utilities.h and c_utilities.c

C++ : cpp_utilities.h and cpp_utilities.cpp

Download given respective files and keep in the same directory as source file.


	C Programs: 

	Compilation (Ubuntu/Windows) : gcc <source_file_name> c_utilities.c -o <object_file_name>
	
	Running (Ubuntu) : ./object_file_name
	
	Running (Windows) : object_file_name.exe

	Example: 
	
	gcc -g selection_sort.c c_utilities.c -o selection_sort
	
	ub: ./selection_sort
	
	win: selection_sort.exe


	
	C++ Programs: 
	
	Compilation (Ubuntu/Windows) : g++ -o <object_file_name> <source_file_name> cpp_utilities.cpp
	
	Running (Ubuntu) : ./object_file_name
	
	Running (Windows) : object_file_name.exe

	Example:

	gcc -g -o selection_sort selection_sort.cpp cpp_utilities.cpp 
	
	ub: ./selection_sort
	
	win: selection_sort.exe



---> Python sorting programs require one addtional file to run "utilities.py". Download this file along with source file you want to run and keep all the file in same directory/folder.
	
	Executing Python programs: python <source_file_name>

	Example: python selection_sort.py

---> Java programs require an additional class named as Utilities, written in "Utilities.java" source file. You need to download and keep the sorting source file and "Utilities.java" file together in same directory. Assuming all pre-requisites for running java program are there in your system. For compilation and execution, follow the procedure mentioned below:

	Compilation : javac sorting_source.java Utilities.java
	
	javac selection_sort.java Utilities.java

	Execution : java ClassNameInSortingSourceFile

	java SelectionSort
