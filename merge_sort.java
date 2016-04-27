/*
Author: Vivek Vikram Singh
Date : 24-04-16
Java implementation of Merge sort.
Input ; number of integers(n), range of integers(r)
Ouput : sorted array
Program will generate a random array of "n" integers within range 0 to "r"
and may contain duplicate integerss. 
*/

import java.util.Scanner;

class MergeSort{
	//mergeSort method
	void mergeSort(int []arr, int low, int high){
		if(low<high){
			int mid = low +(high-low)/2;
			mergeSort(arr, low, mid);
			mergeSort(arr, mid+1, high);
			merge(arr, low, mid, high);
		}
	}//mergeSort()

	void merge(int []arr, int low, int mid, int high){
		int in1, in2, in3, left_els, right_els, i;
		left_els = mid-low+1;
		right_els = high-mid;
		//Creating two subarrays
		int []left_sub = new int[left_els];
		int []right_sub = new int[right_els];
		//Copying elements in two subarrays so that over-writing can be done easily.
		for(i=0; i<left_els; i++)
			left_sub[i] = arr[low+i];	//Lowest index is "low" for left part of arr
		for(i=0; i<right_els; i++)
			right_sub[i] = arr[mid+1+i];//Lowest index is "mid+1" for right part of arr
		//Initialing the indexes
		in1 = 0; in2= 0; in3 = low;
		while(in1 <left_els && in2< right_els){
			if (left_sub[in1] <= right_sub[in2]){
				arr[in3] = left_sub[in1];
				in1++;
			}
			else{
				arr[in3] = right_sub[in2];
				in2++;
			}
			in3++;
		}
		//Copying remaning parts of left ans right sub arrays, repectively
		while(in1<left_els){
			arr[in3]= left_sub[in1];
			in1++;
			in3++;
		}
		while(in2<right_els){
			arr[in3]= right_sub[in2];
			in2++;
			in3++;
		}
	}//merge()

	public static void main(String []args){
		MergeSort mgObj = new MergeSort();
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
		mgObj.mergeSort(arr, 0, n-1);
		System.out.println("Array After sorting :");
		Utilities.printArray(arr);
	}//main()

}//class InsertionSort