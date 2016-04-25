/*
Author: Vivek Vikram Singh
Date : 24-04-16
Java implementation of Bubble sort.
Input ; number of integers(n), range of integers(r)
Ouput : sorted array
Program will generate a random array of "n" integers within range 0 to "r"
and may contain duplicate integerss. 
*/

import java.util.Scanner;

class BubbleSort{
	
	//Bubble Sort method
	void bubbleSort(int[] arr){
		int i, j, size = arr.length;
		boolean swapped;
		for(i=0; i<size; i++){
			swapped= false;
			for(j=0; j<size-i-1; j++){
				if(arr[j]>arr[j+1]){
					swapped=true;
					Utilities.swapInArray(j, j+1, arr);
				}
			}
		}
	}//bubbleSort()

	public static void main(String []args){
		BubbleSort bubbleObject = new BubbleSort();
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
		bubbleObject.bubbleSort(arr);
		System.out.println("Array After sorting :");
		Utilities.printArray(arr);
	}//main()
}//class BubbleSort