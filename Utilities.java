/*
Utility functions for programs in Java
*/
import java.util.Random;

public class Utilities{
	//Method to generate an array of n integers within range 0 to r-1
	public static void generateArray(int []arr, int r){
		Random randomGenerator = new Random();	//http://www.javapractices.com/topic/TopicAction.do?Id=62
		int i, n = arr.length;
		for (i=0; i<n; i++){
			arr[i] = randomGenerator.nextInt(r);
		}
	}// generateArray()

	//Method to print array elements
	public static void printArray(int []arr){
		int i, size = arr.length;
		for(i=0; i<size; i++){
			System.out.print(arr[i] +" ");
		}
		System.out.println();
	}//printArray()

	//Method to swap values in array
	public static void swapInArray(int i, int j, int []arr){
		int temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
	}//swapInArray()
	
}//class Utilities