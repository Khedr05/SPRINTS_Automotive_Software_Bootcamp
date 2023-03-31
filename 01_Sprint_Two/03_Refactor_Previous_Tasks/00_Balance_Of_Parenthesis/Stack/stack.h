

#ifndef STACK_H_
#define STACK_H_

#include <stdio.h>
#include "../Servies/STD_Types.h"

#define DUMP_DATA                                                5


#define STACK_SIZE                                               10

#define RETURN_OTHERWISE                                         0
#define RETURN_STACK_IS_FULL                                    -1
#define RETURN_STACK_IS_EMPTY                                   -2

#define EMPTY_STACK_TOP                                         -1
#define FULL_STACK_TOP                                           9

#define NEW_VALUE_AFTER_POP                                      0



typedef struct stack { 
Uint8_t elements[STACK_SIZE];
Sint8_t top;
}ST_stack_t;


void createEmptyStack(ST_stack_t *stack);
Sint8_t push(ST_stack_t *stack, Uint8_t data);
Sint8_t pop(ST_stack_t *stack, Uint8_t *data);
Sint8_t printStack(ST_stack_t *stack);
Sint8_t getStackTop(ST_stack_t *stack, Uint8_t *topData);
Sint8_t isFull(ST_stack_t *stack);
Sint8_t isEmpty(ST_stack_t *stack);


#endif