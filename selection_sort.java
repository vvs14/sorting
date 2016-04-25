/*
Author: Vivek Vikram Singh
Date : 23-04-16
Java implementation of Selection sort.
Input ; number of integers(n), range of integers(r)
Ouput : sorted array
Program will generate a random array of "n" integers within range 0 to "r"
and may contain duplicate integerss. 
*/

import java.util.Scanner;

class SelectionSort{
	//Selection sort function
	void selectionSort(int[] arr){
		int i, j, min, minPos;
		int arrSize = arr.length;
		for(i=0; i<arrSize-1; i++){
			minPos = i;
			min = arr[minPos];
			for(j=i+1; j<arrSize; j++){
				if( arr[j]<min){
					minPos = j;
					min = arr[minPos];
				}
			}
			if(minPos != i)
				Utilities.swapInArray(i, minPos, arr);
		}
	}//Selection()

	public static void main(String []args){
		SelectionSort selObject = new SelectionSort();
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
		selObject.selectionSort(arr);
		System.out.println("Array After sorting :");
		Utilities.printArray(arr);
	}//main()
}//class SelectionSort