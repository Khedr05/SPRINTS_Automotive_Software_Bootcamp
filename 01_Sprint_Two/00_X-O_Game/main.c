/*
 ============================================================================
 Name        : X-O_Game.c
 Author      : Sherif Ashraf Ali
 Version     :
 Copyright   : Sherif Ashraf Ali
 Description : X-O game is a fun, traditional, and online browser game where you have 
               to use your own strategies of placing 3 marks in a horizontal, 
               vertical, or diagonal row. To win, you must be the first to get three of your marks in a row
 ============================================================================
 */


/*=============================================== Includes ======================================================== */


#include <stdio.h>
#include <stdlib.h>
#include"STD_Types.h"

/*=============================================== Macros ======================================================== */

#define DUMP_DATA       5

#define WININNG_STATE   0
#define DRAW_STATE      1
#define Continue_STATE  2

/*=============================================== Global Declarations ======================================================== */


Uint8_t GLOBAL_ABoardData[9] = {'0','1','2','3','4','5','6','7','8'}; // array contain the data of the board
Uint8_t GLOBAL_AGameSymbols[2] = {'x','o'}; // array contain symbols avaliable in the game 
Uint8_t GLOBAL_APlayersSymbols[2] = {'n','n'}; // array contain every players symbols 
Uint8_t GLOBAL_ReturnFlagUpdateBoard = FALSE; // flag rised when the board draw succes
Uint8_t GLOBAL_ReturnFlagGetGameState = Continue_STATE; // variable to store the return data from getGameState Function
Uint8_t GLOBAL_playerSymbol = 'n'; // variable hold the symbol player input it until make proccess on it




/*=============================================== Functions Prototype ============================================== */
void drawBoard(Uint8_t *board);
void updateBoard (Uint8_t *board, Uint8_t position, Uint8_t value);
Uint8_t getPlayerSymbol(Uint8_t playerNumber, Uint8_t * symbol);
void setPlayerConfig(Uint8_t *configArray);
void loadAndUpdate(Uint8_t playerNumber);
void getGameState(Uint8_t *board, Uint8_t *gameState);


/*=============================================== Main Implemntation ======================================================== */


int main(void) {

    configAgian:  // label goto when players do not choose symbols
    setPlayerConfig(GLOBAL_APlayersSymbols); // Function Calling To Let User Choose Player Symbol 
    setPlayerConfig(GLOBAL_APlayersSymbols); // Function Calling To Let User Choose Player Symbol
    if((GLOBAL_APlayersSymbols[0] == 'n') || (GLOBAL_APlayersSymbols[1] == 'n')) 
    { // Check If The Players Not Choose Symbols Correctly  
        printf("Please Config Players Symbols First \n"); // Print Massage
        goto configAgian; // Goto Label In Line #51
    }

   while(1)
   {

            //Check The Return Of Game State Function To Know State Game(Win - Draw - Continue) After Calling The Function
            drawBoard(GLOBAL_ABoardData); // Function Calling To Draw The Board Depend On The Data OF The GLOBAL_ABoardData 
            printf("Player Zero Turn\n"); // Print Massage
            loadAndUpdate(0); // Function Calling To Ask Player One For The Position He Want To Play In It 
            getGameState(GLOBAL_ABoardData,&GLOBAL_ReturnFlagGetGameState); // Function Calling To Check Game State (Win - Draw - Continue) After All Players Play In His Turn
            //Check The Return Of Game State Function To Know State Game(Win - Draw - Continue) After Calling The Function
             if(GLOBAL_ReturnFlagGetGameState == WININNG_STATE) // if return = 0 then the state is wininng
            {
                printf("Wininng\n"); // print massage
                break; // termante game
            }
            else if(GLOBAL_ReturnFlagGetGameState == DRAW_STATE) // if return = 1 then the state is draw
            {
                printf("Draw\n");// print massage
                break;// termante game
            }
            else if(GLOBAL_ReturnFlagGetGameState == Continue_STATE)// if return = 2 then the state is Continue Playing
            {
                /*{nothing}*/
            }

            printf("Player One Turn\n"); // Print Massage
            loadAndUpdate(1); // Function Calling To Ask Player Two For The Position He Want To Play In It
            getGameState(GLOBAL_ABoardData,&GLOBAL_ReturnFlagGetGameState); // Function Calling To Check Game State (Win - Draw - Continue) After All Players Play In His Turn
        if(GLOBAL_ReturnFlagGetGameState == WININNG_STATE) // if return = 0 then the state is wininng
        {
            printf("Wininng\n"); // print massage
            break; // termante game
        }
        else if(GLOBAL_ReturnFlagGetGameState == DRAW_STATE) // if return = 1 then the state is draw
        {
            printf("Draw\n");// print massage
            break;// termante game
        }
        else if(GLOBAL_ReturnFlagGetGameState == Continue_STATE)// if return = 2 then the state is Continue Playing
        {

        }
    }
    return 0;
}

/*=============================================== Functions Implemntation ======================================================== */


/*=============================================== drawBoard Functions Implemntation ======================================================== */



/*
Description : this function just print the board on console for players depend on the data in GLOBAL_ABoardData array
Paramters   : address of board
Return      : Void 
*/

void drawBoard(Uint8_t *board)
{        
    printf("    |    |     \n");// print massage
    printf("  %c |  %c | %c \n", board[0],board[1], board[2]);// print massage
    printf("____|____|_____\n");// print massage
    printf("    |    |     \n");// print massage
    printf("  %c |  %c | %c \n",board[3],board[4],board[5]);// print massage
    printf("____|____|_____\n");// print massage
    printf("    |    |     \n");// print massage
    printf("  %c |  %c | %c \n", board[6],board[7],board[8]);// print massage
    printf("    |    |     \n\n");// print massage
}



/*=============================================== updateBoard Functions Implemntation ======================================================== */


/*
Description : This function will take the board, position to update and value to set in this position 
Paramters   : address of board , position to play in it on the board , value to put it in the position
Return      : Void 
*/

void updateBoard (Uint8_t *board, Uint8_t position, Uint8_t value)
{   
    if((board[position] != 'x') && (board[position] != 'X') && (board[position] != 'o') && (board[position] != 'O'))
    { //check that the value is from avaliable symbols Or Not
        board[position] = value;  // Assign value in the board array in the same position 
        GLOBAL_ReturnFlagUpdateBoard = 1; // raise flag to know that the board update
    }
}


/*=============================================== getplayersymbol Functions Implemntation ======================================================== */


/*
Description : This function will take the player's number and asks the player to choose between X and O (case insensitive)
Paramters   : Take Two Paramters Player Number & Address Of The Symbol
Return      : Uint8_t Datatype
              This function will return 0 when the input symbol is not wrong and/or was not chosen before
              This function will return 1 when the input symbol is wrong and/or was chosen before
*/

Uint8_t getPlayerSymbol(Uint8_t playerNumber, Uint8_t * symbol)
{
    Uint8_t LOCAL_returnFlag = 1; // variable the function will return
   
    //Check That The Symbol is from allowed symbols
    if(GLOBAL_playerSymbol == 'x' || GLOBAL_playerSymbol == 'X')    
    {
        //Check That The Symbol is not reversed
        if((playerNumber == 0 || playerNumber == 1) && (symbol[0] =='x'))
        {
            LOCAL_returnFlag = 0;
        }
        else
        {
            LOCAL_returnFlag = 1;
        }
    }
    else if(GLOBAL_playerSymbol == 'o' || GLOBAL_playerSymbol == 'O') //Check That The Symbol is from allowed symbols
    {
        //Check That The Symbol is not reversed
        if((playerNumber == 0 || playerNumber == 1) && (symbol[1] =='o'))
        {
            LOCAL_returnFlag = 0;
        }
        else
        {
            LOCAL_returnFlag = 1;
        }
    }
 
  return LOCAL_returnFlag;   
}


/*=============================================== setplayerconfig Functions Implemntation ======================================================== */


/*
Description : This function will prompt and asks each user about their preferred symbols and saves it in the configArray 
Paramters   : Take One Paramters address of array to save config symbols in it 
Return      : Void 
*/
void setPlayerConfig(Uint8_t *configArray)
{
    Uint8_t LOCAL_checkFunctionReturn = 1; //variable to store return value return form calling getplayersymbol function
    Uint8_t LOCAL_playerNumber = DUMP_DATA; //variable to store player number the user enter it

    tryEnterPlayerNumberAgian: //label goto it if the user enter wrong player number 

    printf("Enter Player Number 0 Or 1\n"); //print massgae
    scanf(" %d",&LOCAL_playerNumber); //scan the player number

    if((LOCAL_playerNumber < 0 ) || (LOCAL_playerNumber >1)) // check the number of the player is wrong or not
    {
        printf("Player Number Invalid Please Try Agian \n");//print massage
        goto tryEnterPlayerNumberAgian; // goto tryEnterPlayerNumberAgian label to try enter player number agian 
    }

    tryEnterSymbolAgian: //label goto it if the user enter wrong symbol

    printf("Enter Player %d Symbol \n",LOCAL_playerNumber); // print massage
    scanf(" %c",&GLOBAL_playerSymbol);// scan player symbol he want to play with it

    //check the user enter wrong symbol or not
    if((GLOBAL_playerSymbol !='x') && (GLOBAL_playerSymbol !='X') && (GLOBAL_playerSymbol !='o') && (GLOBAL_playerSymbol !='O'))
    {
        printf("Player Symbol Invalid Please Try Agian Chosse x or o \n"); // print massage
        goto tryEnterSymbolAgian; //goto tryEnterSymbolAgian label if the user enter wrong symbol
    }

    // calling function to check symbol and if it reversed or not the return its data
    LOCAL_checkFunctionReturn = getPlayerSymbol(LOCAL_playerNumber,GLOBAL_AGameSymbols);
    if((GLOBAL_playerSymbol == 'x' || GLOBAL_playerSymbol == 'X') && LOCAL_checkFunctionReturn == 0)
    {
        // if the symbol is not wrong && the function return 0 then their is no errors
        configArray[LOCAL_playerNumber] = 'x'; // save the symbol in the config array
        GLOBAL_AGameSymbols[0] = 'r';  // change the symbol to r (reversed) in the avalable symbols array 
    }
    else if((GLOBAL_playerSymbol == 'o' || GLOBAL_playerSymbol == 'O') && LOCAL_checkFunctionReturn == 0)
    {
        // if the symbol is not wrong && the function return 0 then their is no errors
        configArray[LOCAL_playerNumber] = 'o';// save the symbol in the config array
        GLOBAL_AGameSymbols[1] = 'r';// change the symbol to r (reversed) in the avalable symbols array 
    }
}


/*=============================================== loadandupdate Functions Implemntation ======================================================== */


/*
Description : This function will take the player's number then load his config, ask him for the position then updates the board 
Paramters   : Take One Paramters player number (0 or 1) 
Return      : Void 
*/
void loadAndUpdate(Uint8_t playerNumber)
{
    
    Uint8_t LOCAL_Position = DUMP_DATA; // variable to store the position player enter it
    trytoplayinemptyposistion:
    printf("Enter Your Board Position To Fill It \n");//print massage
    scanf("%d",&LOCAL_Position);// scan the position
    // calling updateboard to save player symbol in the position he want 
    updateBoard(GLOBAL_ABoardData,LOCAL_Position,GLOBAL_APlayersSymbols[playerNumber]);
    // calling board function to draw the new board after adding user symbol in the position he want
    if(GLOBAL_ReturnFlagUpdateBoard != TRUE) // if the player play in already filled poisition
    {
        printf("You Must Play In Empty Position \n");
        goto trytoplayinemptyposistion; 
    }
    else
    {
        GLOBAL_ReturnFlagUpdateBoard = FALSE;
    }
    drawBoard(GLOBAL_ABoardData);
}

/*=============================================== getgamestate Functions Implemntation ======================================================== */


/*
Description : This function will check after each move if there is a win, draw or continue playing.
Paramters   : Take Two Paramters address of board & address of variable to return in it 
Return      : Returns 0 for winning
              Returns 1 for a draw
              Returns 2 to continue 
*/
void getGameState(Uint8_t *board, Uint8_t *gameState)
{
    // check all winning test case if one of them is achived return 0
    if(board[0] == board[1] && board[1] == board[2])
    {
        *gameState = WININNG_STATE;
    }
    else if(board[3] == board[4] && board[4] == board[5])
    {
        *gameState = WININNG_STATE;
    }
    else if(board[6] == board[7] && board[7] == board[8])
    {
        *gameState = WININNG_STATE;
    }
    else if(board[0] == board[3] && board[3] == board[6])
    {
        *gameState = WININNG_STATE;
    }
    else if(board[1] == board[4] && board[4] == board[7])
    {
        *gameState = WININNG_STATE;
    }
    else if(board[2] == board[5] && board[5] == board[8])
    {
        *gameState = WININNG_STATE;
    }
    else if(board[0] == board[4] && board[4] == board[8])
    {
        *gameState = WININNG_STATE;
    }
    else if(board[2] == board[4] && board[4] == board[6])
    {
        *gameState = WININNG_STATE;
    }//check draw case if no avilable posistion to play return 1
    else if( (board[0] != '0') && (board[1] != '1') && (board[2] != '2') && (board[3] != '3') && (board[4] != '4')
             && (board[5] != '5') && (board[6] != '6') && (board[7] != '7') && (board[8] != '8'))
    {
        *gameState = DRAW_STATE;
    }
    else //if no case is achived then continue and return 2
    {
        *gameState = Continue_STATE;
    }
}