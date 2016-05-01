/*
Author: Vivek Vikram Singh
Date : 01-05-16
Java implementation of Quick sort.
Input ; number of integers(n), range of integers(r)
Ouput : sorted array
Program will generate a random array of "n" integers within range 0 to "r"
and may contain duplicate integerss. 
read README.md for correct compilation and execution procedures of these programs.
*/

import java.util.Scanner;

class QuickSort{
	//Partition method
	int partition( int []arr, int low, int high){
		int left, right, pivot;
		left = low;
		pivot = arr[left]; //pivot is chosen as left most element of array
		for (right=left+1; right<=high; right++){
			if(arr[right]<pivot){
				left++;
				Utilities.swapInArray(left, right, arr);
			}
		}
		Utilities.swapInArray(left, low, arr);
		return left;
	}//partition()

	void quickSort(int []arr, int low, int high){
		if(low<high){
			int pos = partition(arr, low, high);
			quickSort(arr, low, pos-1);
			quickSort(arr, pos+1, high);
		}
	}//quickSort()


	public static void main(String []args){
		QuickSort object = new QuickSort();
		Scanner sc = new Scanner(System.in);
		int n,r;
		System.out.println("Enter the No. of ints : ");
		n = sc.nextInt();
		int []arr = new int[n];
		System.out.println("Enter the range of ints : ");
		r = sc.nextInt();
		Utilities.generateArray(arr, r);
		System.out.println("Array before sorting :");
		Utilities.printArray(arr);
		object.quickSort(arr, 0, n-1);
		System.out.println("Array After sorting :");
		Utilities.printArray(arr);
	}//main()

}//class QuickSort