

#ifndef BALANCED_PARANTHETHES_H_
#define BALANCED_PARANTHETHES_H_

#include<string.h>
#include"../Servies/STD_Types.h"
#include"../Stack/stack.h"


#define DUMP_DATA                                                5

#define EXPRESSION_BALANCED                                      0
#define EXPRESSION_NOT_BALANCED                                 -1 
#define EXPRESSION_NEITHER_OF_PARANTHETHES_IS_USED              -2



Sint8_t isBalancedParanthethes(Uint8_t *expression);

#endif