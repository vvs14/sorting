/*
Author: Vivek Vikram Singh
Date : 30-04-16
Java implementation of Heap sort.
Input ; number of integers(n), range of integers(r)
Ouput : sorted array
Program will generate a random array of "n" integers within range 0 to "r"
and may contain duplicate integerss. 
Reference : http://www.cs.umd.edu/~meesh/351/mount/lectures/lect13-heapsort.pdf
*/

import java.util.Scanner;

class HeapSort{
	//heapSort method
	void heapSort(int []arr){
		int lastElement, size;
		buildHeap(arr);
		size = arr.length;
		for(lastElement= size-1; lastElement>=1; lastElement--){
			Utilities.swapInArray(0, lastElement, arr);
			maxHeapify(arr, 0, lastElement);
			//minHeapify(arr, 0, lastElement);
		}
	}//heapSort()

	void buildHeap(int []arr){
		int size, i;
		size = arr.length;
		for( i= size/2 -1; i>=0; i--){
			maxHeapify(arr, i, size);
			//minHeapify(arr, i, size);
		}
	}//buildHeap()

	void maxHeapify(int []arr, int root, int size){
		int left, right, max;
		left = 2*root+1;
		right = left+1;
		max = root;
		if (left < size && arr[left] > arr[max])
			max = left;
		if(right < size && arr[right] > arr[max])
			max = right;
		if(max != root){
			Utilities.swapInArray(max, root, arr);
			maxHeapify(arr, max, size);
		}
	}//maxHeapify()

	void minHeapify(int []arr, int root, int size){
		int left, right, min;
		left = 2*root+1;
		right = left+1;
		min = root;
		if (left < size && arr[left] < arr[min])
			min = left;
		if(right < size && arr[right] < arr[min])
			min = right;
		if(min != root){
			Utilities.swapInArray(min, root, arr);
			minHeapify(arr, min, size);
		}
	}//minHeapify()


	public static void main(String []args){
		HeapSort object = new HeapSort();
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
		object.heapSort(arr);
		System.out.println("Array After sorting :");
		Utilities.printArray(arr);
	}//main()

}//class HeapSort