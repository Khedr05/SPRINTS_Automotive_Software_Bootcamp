

#ifndef LCS_H_
#define LCS_H_

#include"../servies/STD_Types.h"
#include"../insertion_sorting/insertion_sorting.h"

#define DUMP_DATA 						 5

#define RETURN_FUNCTION_OTHERWISE	 	 0
#define RETURN_ARRAY_IS_EMPTY			-1
#define RETURN_ARRAY_ERROR_IN_SIZE 		-2
#define RETURN_NO_SEQ					-3

Sint8_t lcsGetSize(Sint32_t *array, Uint8_t arraySize, Uint8_t *sizeofLCS);

#endif