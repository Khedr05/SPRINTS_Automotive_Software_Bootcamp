

#include"BalancedParanthethes.h"


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