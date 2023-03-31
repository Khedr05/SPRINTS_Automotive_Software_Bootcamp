
#include"stack.h"

/*=============================================== createemptystack Functions Implemntation ======================================================== */

/* 
Description :
- This function takes a reference to a stacks type
- Initialize this stack with Zeros
- Initialize the top with -1
Paramters  : One Paramter address of the stack from ST_stack_t
Return     : Void
*/

void createEmptyStack(ST_stack_t *stack)
{
    stack->elements[STACK_SIZE] = 0; // intialize all stack element with zero
    stack->top = EMPTY_STACK_TOP; // assign stack top with -1
}

/*=============================================== push Functions Implemntation ======================================================== */

/* 
Description  :
- This function takes a reference to the stack and data to store
- Stores the data passed into the stack
Paramters    : Two Paramters
- address of the stack from ST_stack_t type
- data will be pushed in the stack
Return       : Sint8_t
- returns -1 if the stack is full
- returns 0 otherwise
*/


Sint8_t push(ST_stack_t *stack, Uint8_t data)
{
    Sint8_t LOCAL_ReturnValue = DUMP_DATA; // assign the variable function will return with dumpdata (5)
    if(stack->top == (FULL_STACK_TOP)) // if stack top equal stack size -1 (10-1 = 9) then the stack is full
    {
        LOCAL_ReturnValue = RETURN_STACK_IS_FULL; // assign -1 in the var mean the stack is full can not push any data
    }
    else
    {
        // else stack not full we can push data
        stack->top++; // increment top
        stack->elements[stack->top] = data;// assign the data in the stack 
        LOCAL_ReturnValue = RETURN_OTHERWISE;// assign 0 in the var mean the stack is otherwise
    }
    return LOCAL_ReturnValue;
}

/*=============================================== pop Functions Implemntation ======================================================== */

/* 
Description  :
 - This function takes a reference to the stack
 - Stores the data popped from the stack in a data variable
 Paramters      : Take Two Paramters
 - address of stack from ST_stack_t type
 - address of variable to store index value of the poped element in it
 Return         : Sint8_t
 - returns -2 if the stack is empty
 - returns 0 otherwise
 */

Sint8_t pop(ST_stack_t *stack, Uint8_t *data)
{
    Sint8_t LOCAL_ReturnValue = DUMP_DATA;
    if(stack->top == EMPTY_STACK_TOP) // check if the top of stack is equal -1 mean the stack is empty
    {
        LOCAL_ReturnValue = RETURN_STACK_IS_EMPTY; // return -2 means that the stack is empty so no data to pop from stack
    }
    else
    {
        // else if the stack is not empty 
        *data = stack->elements[stack->top]; // assign the value of the stack top in the var
        stack->elements[stack->top] = NEW_VALUE_AFTER_POP; // pop the last pushed data in the stack
        stack->top--; // decrement the top
        LOCAL_ReturnValue = RETURN_OTHERWISE; // return 0 means otherwise
    }
    return LOCAL_ReturnValue;   
}


/*=============================================== printstack Functions Implemntation ======================================================== */

/* 
Description   :
 - This function takes a reference to the stack
 - Prints all stack's data starting from the top
 Paramter     : One Paramter 
 - address of stack from ST_stack_t data type
 Return       :
 - returns -1 if the stack is full
 - returns -2 if the stack is empty
 - returns 0 otherwise
 */

Sint8_t printStack(ST_stack_t *stack)
{
    Sint8_t LOCAL_ReturnValue = DUMP_DATA; // assign dump data in return value that will return by function
    Uint8_t LOCAL_PrintCounter = 0; // assign 0 to the counter so we can incremment it
    if(stack->top == (FULL_STACK_TOP)) // check the top of stack is full 
    {
        LOCAL_ReturnValue = RETURN_STACK_IS_FULL; // assign -1 in the return value to return it
    }
    else if(stack->top == EMPTY_STACK_TOP) // check the top of stack is empty
    {
        LOCAL_ReturnValue = RETURN_STACK_IS_EMPTY; // assign -2 in the return value to return it
    }
    else
    {
        LOCAL_ReturnValue = RETURN_OTHERWISE; // assign 0 in the return value to return it
    }

    if(stack->top > EMPTY_STACK_TOP) // check if the stack top is greater than empty stack top (-1)
    {
        while(LOCAL_PrintCounter <= stack->top) // check if the counter less than or equal the stack top 
        {
            printf(" %d \t",stack->elements[LOCAL_PrintCounter]);//priint the elment
            LOCAL_PrintCounter++;//increment the counter
        }
        printf("\n\n");//print newline
    }
    return LOCAL_ReturnValue;
}

/*=============================================== getstacktop Functions Implemntation ======================================================== */

/* Description  :
- This function takes a reference to the stack
- Stores its top data into a variable
Paramters      : Two Parameters 
- address of stack from ST_stack_t data type
- address of var to return value of stack top in it
Return         : Sint8_t
- returns -2 if the stack is empty
- 0 otherwise
*/

Sint8_t getStackTop(ST_stack_t *stack, Uint8_t *topData)
{
    Sint8_t LOCAL_ReturnValue = DUMP_DATA; // assign dump data in return value that will return by function
    *topData = stack->top; // assign the top of stack in the topdata pointer
    if(stack->top == EMPTY_STACK_TOP) // check if the stack is empty or not
    {
        LOCAL_ReturnValue = RETURN_STACK_IS_EMPTY; // assign -2 in the var to return it
    }
    else
    {
        LOCAL_ReturnValue = RETURN_OTHERWISE; // assign 0 in the var to return it
    }
    return LOCAL_ReturnValue;
}


/*=============================================== isfull Functions Implemntation ======================================================== */


/* Description  :
- This function takes a reference to the stack
- Checks if the stack is full or not
Parametars      : One Parameters
- address of stack from ST_stack_t data type
Return          : Sint8_t
- returns -1 if the stack is full
- 0 otherwise
*/

Sint8_t isFull(ST_stack_t *stack)
{
    Sint8_t LOCAL_ReturnValue = DUMP_DATA; // assign dump data in return value that will return by function
    if(stack->top == (FULL_STACK_TOP)) // check if the stack is full
    {
        LOCAL_ReturnValue = RETURN_STACK_IS_FULL; //assign -1 in the var to return it
    }
    else
    {
        LOCAL_ReturnValue = RETURN_OTHERWISE; //assign 0 in the var to return it
    }
    return LOCAL_ReturnValue;
}

/*=============================================== isempty Functions Implemntation ======================================================== */


/* Description  :
- This function takes a reference to the stack
- Checks if the stack is empty or not
Paramters       : One Paramters
- address of the stack of ST_stack_t data type
Return          : Sint8_t
- returns -2 if the stack is empty
- 0 otherwise
*/

Sint8_t isEmpty(ST_stack_t *stack)
{
    Sint8_t LOCAL_ReturnValue = DUMP_DATA; // assign dump data in return value that will return by function
    if(stack->top == EMPTY_STACK_TOP) // check if the stack is empty
    {
        LOCAL_ReturnValue = RETURN_STACK_IS_EMPTY; //assign -2 in the var to return it
    }
    else
    {
        LOCAL_ReturnValue = RETURN_OTHERWISE; //// assign 0 in the var to return it
    }
    return LOCAL_ReturnValue;
}
