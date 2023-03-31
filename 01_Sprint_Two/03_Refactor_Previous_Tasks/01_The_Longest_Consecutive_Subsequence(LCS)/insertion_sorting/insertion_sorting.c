

#include"insertion_sorting.h"



/* 
Description		:
- This function takes a reference to an array of integers
- Sorts the array in ascending order
- Using the insertion sort algorithm
Parameters 		: Two Parametars
- address of the araay from Sint32_t data type
- var contain array size from Uint8_t data type
Return 			: Sint8_t
- returns -1 if the array is empty
- returns -2 if the array size is 0 or >10
- returns 0 if sorting is done without errors
*/

Sint8_t insertionSort(Sint32_t *array, Uint8_t arraySize)
{
	Sint8_t LOCAL_returnValue = DUMP_DATA; // assign dump data 
	if(arraySize <= ARRAY_IS_EMPTY) // check if the array is empty 
	{
		LOCAL_returnValue = RETURN_ARRAY_IS_EMPTY; // assign -1 to the var to return it
	}
	else
	{
		if(arraySize > ARRAY_MAX_SIZE || arraySize < ARRAY_MIN_SIZE ) // check if the array size is greater than max size (10) 
		{
			LOCAL_returnValue = RETURN_ARRAY_ERROR_IN_SIZE; // assign -2 to the var to return it
		}
		else
		{
			Sint8_t i, j, temp;  
		    for (i = 1; i < arraySize; i++) // loop until the size of array
		    {  
		        temp = array[i];  // take a copy from element number 1 in the array 
		        j = i - 1;  // assign current element index - 1 
		  
		        while(j>=0 && temp <= array[j])  // check if temp smaller than j or not && j gearter than or equal 0
		        {    
		            array[j+1] = array[j]; // assign array[j] in array[j+1]     
		            j = j-1;    // decrement j
		        }    
		        array[j+1] = temp;    // assign temp in the new index 
		    }
		    LOCAL_returnValue = RETURN_SORTING_FUNCTION_DONE;
		}
	}
  return LOCAL_returnValue;
}



/* 
Description	:
- This function takes a reference to an array of integers
- Prints all array elements
Paramters 	:Two Paramter 
- address of the araay from Sint32_t data type
- var contain array size from Uint8_t data type 
Return 		: Void
 */
void printArray(Sint32_t *array, Uint8_t arraySize)
{
	for (Uint8_t i = 0; i < arraySize; i++) // loop until the end of array
	{
	    printf("%d ",array[i]); // print element in array
	}
	printf("\n");// print new line
}


