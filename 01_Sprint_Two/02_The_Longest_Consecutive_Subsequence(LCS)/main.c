/*
 ============================================================================
 Name        : X-O_Game.c
 Author      : Sherif Ashraf Ali
 Version     :
 Copyright   : Sherif Ashraf Ali
 Description : The Longest Consecutive Subsequence(LCS) is a subset of the original array where the 
 			   numbers are in sorted order, from lowest to highest, and are in consecutive, increasing order.
 ============================================================================
 */


/*=============================================== Includes ======================================================== */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"STD_Types.h"

/*=============================================== Macros ======================================================== */

#define DUMP_DATA 						 5

#define ARRAY_IS_EMPTY					 0
#define ARRAY_MAX_SIZE					 10
#define ARRAY_MIN_SIZE					 1

#define RETURN_FUNCTION_OTHERWISE	 	 0
#define RETURN_ARRAY_IS_EMPTY			-1
#define RETURN_ARRAY_ERROR_IN_SIZE 		-2
#define RETURN_NO_SEQ					-3

#define RETURN_SORTING_FUNCTION_DONE	 0

/*=============================================== Global Declaration ======================================================== */


/*=============================================== Function Prototype ======================================================== */

Sint8_t insertionSort(Sint32_t *array, Uint8_t arraySize);
void printArray(Sint32_t *array, Uint8_t arraySize);
Sint8_t lcsGetSize(Sint32_t *array, Uint8_t arraySize, Uint8_t *sizeofLCS);

/*=============================================== Main Function Implemantation ======================================================== */


void main(void) 
{
	Uint8_t i = 0;
	Sint32_t new_arr[30];
	char user_input[9], *ptr;
	Sint8_t returnvalue = 0,seq = 0;

		printf("Enter Elements\n"); // print massage

		while (fgets(user_input, sizeof(user_input), stdin)) // scan the string from user
		{
			if (!strcmp(user_input, "\n")) break; // if user press enter break the loop
			new_arr[i++] = strtol(user_input, &ptr, 10); // convert the char to number and store it in new array
		}

	printf("Sorted array in ascending order:\n"); // print massage
	printArray(new_arr,i); // print sorted array 

	returnvalue = lcsGetSize(new_arr,i,&seq); // call function to get the sequance
	
	if(returnvalue == RETURN_ARRAY_IS_EMPTY) // if function return -1 then the array is empty
	{
		printf("Array Is Empty");
	}
	else if(returnvalue == RETURN_ARRAY_ERROR_IN_SIZE) // if function return -2 then the array size is invalid
	{
		printf("Array Size Error");
	}
	else if(returnvalue == RETURN_NO_SEQ) // if function return -3 then the array has no sequance
	{
		printf("No Seq In The Array");
	}
	else if(returnvalue == RETURN_FUNCTION_OTHERWISE) // if function return zero then the function done succesfuly 
	{
		printf("Seq Length Is : %d",seq);
	}
}




/*=============================================== Functions Implementation ======================================================== */


/*=============================================== insertionSort Functions Implementation ======================================================== */

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




/* Description:
- This function takes a reference to an array,
- array size, and
- reference to store the size of the LCS
- Using the insertion sort algorithm
- The function will search for the LCS in the array and
- stores its size
Return:
- returns -1 if the array is empty
- returns -2 if the array size is 0 or >10
- returns -3 if there is no LCS,
(i.e all array elements are not consecutive at all)
- returns 0 otherwise
*/
Sint8_t lcsGetSize(Sint32_t *array, Uint8_t arraySize, Uint8_t *sizeofLCS)
{
	Sint8_t LOCAL_ReturnSortFunction = DUMP_DATA;
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
			LOCAL_ReturnSortFunction = insertionSort(array,arraySize); // call sorting function to sort the array
			int length = 1; // intialize length and assign it by 1 
		    int longestConsecutiveSeq = 1; // intialize and assign it by 1 
		    int i =0; // intialize counter and assign it by 0
		    for ( i = 0; i < arraySize - 1; i++) // loop until end of the array
		    {
		        if(array[i] == array[i+1]) // if element i and i+1 equal skip it
		        {
		            continue;
		        }
		        else if (array[i] + 1 == array[i + 1]) // if element i +1   and array [i+1] equal 
		        {
		            length++; // increment length
		        }
		        else
		        {
		            length = 1; 
		        }
		        longestConsecutiveSeq = (longestConsecutiveSeq > length)? longestConsecutiveSeq: length; 

		        // if longestConsecutiveSeq greater than length return longestConsecutiveSeq else return length
		    }

		    *sizeofLCS = longestConsecutiveSeq; // return the longestConsecutiveSeq in the reffernce 
		    if(longestConsecutiveSeq == 0) // if the longestConsecutiveSeq equal zero return no sequance 
		    {
		    	LOCAL_returnValue = RETURN_NO_SEQ;	
		    }
		    else
		    {
		    	LOCAL_returnValue = RETURN_FUNCTION_OTHERWISE;	// else return otherwise
		    }
		    
		}
	}
  return LOCAL_returnValue;
}