

#include"lcs.h"



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


