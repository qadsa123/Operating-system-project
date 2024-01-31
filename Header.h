//20F-0248 Talha BCS-5D
//librarires
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <string>
#include <unistd.h>
#include <semaphore.h>
#include <pthread.h>
using namespace std;

int homePosition_tok[4][4] = { {0, 1, 2, 3}, {4, 5, 6, 7}, {8, 9, 10, 11}, {12, 13, 14, 15} };//indexes at which the tokens are present
char tokenNames[4][4] = { {'A', 'B', 'C', 'D'}, {'E', 'F', 'G', 'H'}, {'I', 'J', 'K', 'L'}, {'M', 'N', 'O', 'P'} };//token names of all the four homes
int selPlayer[4] = { 0, 0, 0, 0 }; //Array for selecting random player for play.
int startIndex_tok[4] = { 17, 30, 56, 43 };//indexes from which tokens each players will come out
char tokChoice_in_field;//which token to move that are present in the field
bool winner = false;//false comes true when a player wins
bool Kill_t1 = false;//killing token score
bool checkKill_t1 = false;//adding the score when token reach
bool fieldCheck_tok = false;//taking the token out from the house

class LUDOgame//class containing all the variables
{
public:
    int playerSelect;//selecting the player which moves the token
    int numPlayer;//number of players to play the game
    int tokenNum;//token dice vaue to move the specific number
    char ludoBoard[88];//ludo board consisting of 88 indexes 
    char namePlayer[4][20];//names of the player playing
    char tokenPlay_infield[4][4];//number of tokens with each player playing
    char playTokens[4][4];//tokens present in the home to play
    char token[4][4];//total no of tokens
    char wonToken[4][4];//tokens that finish the game
    int score[4][4];//each token has seperate score that given to the player
};

void* Display_ludoBoard(void* argu);//displaying the board of the game

int tokenPlayable(int player);//token that are present for players to play with

void updateDisp(int player);//showing tokens movement on the table

bool availableToken_Home(int player, char c);//token present in the house to play

void diceToken_cond(int player, int dice);//token movement with the dice number

void killToken(int playerIndex, int player, int pos, LUDOgame& obj, int dice); //token killed by any other player

void movmentToken(int player, LUDOgame& obj, int dice);//token movement to go into the house

void positionToken_handle(int player, int index, int dice, LUDOgame& obj);//handles tokens poss

int token_InField(int player);//tokens present on the board playing

void handler_homePath(int player, int index, int dice, LUDOgame& obj, int previous);//tokens moving inside there home path to finish

int arriHome(int player);//token that come back to the home

void funcToken_won(int player, int index);//token that finish the game

void* bringToken_Field(void* argu);//bringing the tokens to the field

void* startGame(void* argu);//starting the game with taking iformation

LUDOgame obj;//object of the class ludogame
