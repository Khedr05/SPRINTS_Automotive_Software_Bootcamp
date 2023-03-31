

#ifndef INSERTION_SORTING_H_
#define INSERTION_SORTING_H_

#include"../servies/STD_Types.h"
#include<stdio.h>

#define DUMP_DATA 						 5

#define ARRAY_IS_EMPTY					 0
#define ARRAY_MAX_SIZE					 10
#define ARRAY_MIN_SIZE					 1

#define RETURN_SORTING_FUNCTION_DONE	 0

#define RETURN_ARRAY_IS_EMPTY			-1
#define RETURN_ARRAY_ERROR_IN_SIZE 		-2


Sint8_t insertionSort(Sint32_t *array, Uint8_t arraySize);
void printArray(Sint32_t *array, Uint8_t arraySize);

#endif