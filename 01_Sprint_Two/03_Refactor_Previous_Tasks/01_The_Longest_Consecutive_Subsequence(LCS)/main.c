/*
 ============================================================================
 Name        : main.c
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
#include"servies/STD_Types.h"
#include"insertion_sorting/insertion_sorting.h"
#include"lcs/lcs.h"


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


