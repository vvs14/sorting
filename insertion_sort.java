/*
Author: Vivek Vikram Singh
Date : 24-04-16
Java implementation of Insertion sort.
Input ; number of integers(n), range of integers(r)
Ouput : sorted array
Program will generate a random array of "n" integers within range 0 to "r"
and may contain duplicate integerss. 
*/

import java.util.Scanner;

class InsertionSort{
	//Insertionsort method
	void insertionSort(int []arr){
		int i, j, pivot, size = arr.length;
		for(i=0; i<size-1; i++){
			j= i+1;
			pivot = arr[j];
			while (j>0 && arr[j-1] >pivot){
				arr[j] = arr[j-1];
				j--;
			}
			arr[j] = pivot;
		}
	}// insertionSort

	public static void main(String []args){
		InsertionSort inObject = new InsertionSort();
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
		inObject.insertionSort(arr);
		System.out.println("Array After sorting :");
		Utilities.printArray(arr);
	}//main()

}//class InsertionSort