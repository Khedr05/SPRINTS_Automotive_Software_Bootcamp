/*
 ============================================================================
 Name        : Balance Of Parenthesis
 Author      : Sherif Ashraf Ali
 Version     :
 Copyright   : Sherif Ashraf Ali
 Description : The problem of checking if an input string of parentheses is balanced or not 
               is a classic problem in Computer Science. The goal is to determine if a given string
               contains properly balanced and nested parentheses. This problem can be solved using 
               a stack data structure. A stack is a Last-In-First-Out (LIFO) data structure that 
               allows you to push and pop elements in a certain order.
 ============================================================================
 */


/*=============================================== Includes ======================================================== */
#include <stdio.h>
#include <string.h>
#include"STD_TYPES.h"


/*=============================================== Macros ======================================================== */

#define STACK_SIZE                                               10

#define RETURN_OTHERWISE                                         0
#define RETURN_STACK_IS_FULL                                    -1
#define RETURN_STACK_IS_EMPTY                                   -2

#define EMPTY_STACK_TOP                                         -1
#define FULL_STACK_TOP                                           9

#define DUMP_DATA                                                5

#define EXPRESSION_BALANCED                                      0
#define EXPRESSION_NOT_BALANCED                                 -1 
#define EXPRESSION_NEITHER_OF_PARANTHETHES_IS_USED              -2

#define NEW_VALUE_AFTER_POP                                      0



/*=============================================== New Data Types ======================================================== */

typedef struct stack { 
Uint8_t elements[STACK_SIZE];
Sint8_t top;
}ST_stack_t;

/*=============================================== Functions Prototype ============================================== */

void createEmptyStack(ST_stack_t *stack);
Sint8_t push(ST_stack_t *stack, Uint8_t data);
Sint8_t pop(ST_stack_t *stack, Uint8_t *data);
Sint8_t printStack(ST_stack_t *stack);
Sint8_t getStackTop(ST_stack_t *stack, Uint8_t *topData);
Sint8_t isFull(ST_stack_t *stack);
Sint8_t isEmpty(ST_stack_t *stack);
Sint8_t isBalancedParanthethes(Uint8_t *expression);

/*=============================================== Global Declarations ======================================================== */

Sint8_t returnat = DUMP_DATA;
Uint8_t expression[STACK_SIZE] = "";

/*=============================================== Main Implemntation ======================================================== */

void main(void)
{
    while(1)
    {
        printf("Enter String To Check \n");//print massage
        scanf("%s",expression);// scan the string 
        returnat = isBalancedParanthethes(expression); // calling for isBalancedParanthethes function to check the expression
        if(returnat == EXPRESSION_NOT_BALANCED)
        { 
            //if function return -1 then the expression not balnced
            printf("Not Balanced \n");
        }
        else if(returnat == EXPRESSION_BALANCED)
        {
            //if function return 0 then the expression balnced
            printf("Balanced \n");
        }
        else if(returnat == EXPRESSION_NEITHER_OF_PARANTHETHES_IS_USED)
        {
            //if function return -2 then the expression not prenthess used
            printf("Neither Of Paranthethes Is Used \n");
        }
    }
}

/*=============================================== Functions Implemntation ======================================================== */

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

/*=============================================== isBalancedParanthethes Functions Implemntation ======================================================== */

/* 
Description :
- This function takes an expression array max 10 characters
- Checks if the parentheses are balanced or not
- Checks the following parentheses types {, }, (, ) only
Paramters   : One Parametar
- variable from Uint8_t type contain string 
Return      :
- returns -2 if the neither of paranthethes is used
- returns -1 if the parentheses are not balanced
- returns 0 if the parentheses are balanced
*/

Sint8_t isBalancedParanthethes(Uint8_t *expression)
{
    Sint8_t LOCAL_LoopCounter; // counter to count in the loop
    Sint8_t LOCAL_PushCounter = 0;// counter to count the namber of elements pushed in the stack
    Sint8_t LOCAL_PopCounter = 0;// counter to count the namber of elements pushed in the stack
    Sint8_t LOCAL_ExpressionLen = strlen(expression); //strlen function return the length of the expression and assign it in the var
    ST_stack_t LOCAL_CheckerStack; // intialize object(stack) from the data type ST_stack_t
    createEmptyStack(&LOCAL_CheckerStack);// calling function and pass the address of the object(stack)
    Uint8_t LOCAL_PopedData;// var to return the index of poped data in it from the function named pop()
    Sint8_t LOCAL_ReturnValue = DUMP_DATA;// assign dump data in return value that will return by function

    // loop will looping until the least char of the string
    for(LOCAL_LoopCounter = 0 ; LOCAL_LoopCounter <= LOCAL_ExpressionLen; LOCAL_LoopCounter++)
    {   
        // check if the char is equal [ or ] 
        if(expression[LOCAL_LoopCounter] == '[' || expression[LOCAL_LoopCounter] == ']')
        {
            LOCAL_ReturnValue = EXPRESSION_NEITHER_OF_PARANTHETHES_IS_USED; // assign -2 in the var to return it
            goto TheNeitherOfParanthethesIsUsed; //goto the label TheNeitherOfParanthethesIsUsed line #375 
        }
        else
        {
            // check if the char equal ) or } 
            if(expression[0] == ')' || expression[0] == '}')
            {
                LOCAL_ReturnValue = EXPRESSION_NOT_BALANCED; // assign -1 in the var to return it
                goto CloseBracketInFirst; //goto the label CloseBracketInFirst line #374
            }//check if the char equal ( or {
            else if(expression[LOCAL_LoopCounter] == '(' || expression[LOCAL_LoopCounter] == '{')
            {   
                //calling push function to push the char in the stack and pass to it the stack and the char 
                push(&LOCAL_CheckerStack,expression[LOCAL_LoopCounter]);
                LOCAL_PushCounter++; // increment 
            }//check if the char is ) or } && the elment in stack at the top ( or {
            else if((LOCAL_CheckerStack.elements[LOCAL_CheckerStack.top] == '(' && expression[LOCAL_LoopCounter] == ')') || 
                    (LOCAL_CheckerStack.elements[LOCAL_CheckerStack.top] == '{' && expression[LOCAL_LoopCounter] == '}')) 
            {
                pop(&LOCAL_CheckerStack,&LOCAL_PopedData); // calling pop function to pop the char from stack and pass stack 
                                                          //and var to return the index of the poped char in it
                LOCAL_PopCounter++; // increment
                continue; // countinue to the loop to skip itiration 
            }
        }
    }

    // here check the flags to decided the return value 
    // if the push counter equal to pop counter and both is equal zero 
    if(LOCAL_PushCounter == LOCAL_PopCounter && LOCAL_PushCounter == 0 && LOCAL_PopCounter == 0 )
    {
        LOCAL_ReturnValue = EXPRESSION_NEITHER_OF_PARANTHETHES_IS_USED; // assign -2 in the var to return it
    }// if the push counter equal pop counter 
    else if(LOCAL_PushCounter == LOCAL_PopCounter)
    {
        LOCAL_ReturnValue = EXPRESSION_BALANCED; // assign 0 in the var to return it
    }// if push counter greater than pop counter or push counter less than pop counter
    else if(LOCAL_PushCounter > LOCAL_PopCounter || LOCAL_PushCounter < LOCAL_PopCounter)
    {
        LOCAL_ReturnValue = EXPRESSION_NOT_BALANCED; // assign -1 in the var to return it
    }

    CloseBracketInFirst:
    TheNeitherOfParanthethesIsUsed:
    return LOCAL_ReturnValue;
}