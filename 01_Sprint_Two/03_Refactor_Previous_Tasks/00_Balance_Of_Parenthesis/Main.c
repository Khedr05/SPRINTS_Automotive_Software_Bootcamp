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
#include"Servies/STD_TYPES.h"
#include"Stack/stack.h"
#include"BalancedParanthethes/BalancedParanthethes.h"


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

