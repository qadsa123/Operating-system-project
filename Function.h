
#include"Header.h"

pthread_t t_id[9];//identifying the threads
sem_t L1;//semaphore lock 1
sem_t L2;//semaphore lock 2

/*diplaying the board using semaphore wait and to exit I use the pthread exit.
Making boxes for all the indexes with the available indexes present in there.*/
void* Display_ludoBoard(void* argu)
{
    sem_wait(&L1);
    LUDOgame* obj = (LUDOgame*)argu;
    cout << "\t\t\t\t     20F-0248\n";
    cout << "\t                         _________________\n";
    cout << "\t                        │__" << obj->ludoBoard[27] << "__│__" << obj->ludoBoard[28] << "__│__" << obj->ludoBoard[29] << "__│                        \n";
    cout << "\t      " << obj->ludoBoard[0] << "           " << obj->ludoBoard[1] << "     │__" << obj->ludoBoard[26] << "__│__" << obj->ludoBoard[73] << "__│__" << obj->ludoBoard[30] << "__│     " << obj->ludoBoard[4] << "           " << obj->ludoBoard[5] << "      \n";
    cout << "\t                        │__" << obj->ludoBoard[25] << "__│__" << obj->ludoBoard[74] << "__│__" << obj->ludoBoard[31] << "__│                        \n";
    cout << "\t                        │__" << obj->ludoBoard[24] << "__│__" << obj->ludoBoard[75] << "__│__" << obj->ludoBoard[32] << "__│                        \n";
    cout << "\t      " << obj->ludoBoard[2] << "           " << obj->ludoBoard[3] << "     │__" << obj->ludoBoard[23] << "__│__" << obj->ludoBoard[76] << "__│__" << obj->ludoBoard[33] << "__│     " << obj->ludoBoard[6] << "           " << obj->ludoBoard[7] << "      \n";
    cout << "\t _______________________│__" << obj->ludoBoard[22] << "__│__" << obj->ludoBoard[77] << "__│__" << obj->ludoBoard[34] << "__│_______________________ \n";
    cout << "\t│   │   │   │   │   │   │                 │   │   │   │   │   │   │\n";
    cout << "\t│ " << obj->ludoBoard[16] << " │ " << obj->ludoBoard[17] << " │ " << obj->ludoBoard[18] << " │ " << obj->ludoBoard[19] << " │ " << obj->ludoBoard[20] << " │ " << obj->ludoBoard[21] << " │                 │ " << obj->ludoBoard[35] << " │ " << obj->ludoBoard[36] << " │ " << obj->ludoBoard[37] << " │ " << obj->ludoBoard[38] << " │ " << obj->ludoBoard[39] << " │ " << obj->ludoBoard[40] << " │\n";
    cout << "\t│___│___│___│___│___│___│                 │___│___│___│___│___│___│\n";
    cout << "\t│   │   │   │   │   │   │                 │   │   │   │   │   │   │\n";
    cout << "\t│ " << obj->ludoBoard[67] << " │ " << obj->ludoBoard[68] << " │ " << obj->ludoBoard[69] << " │ " << obj->ludoBoard[70] << " │ " << obj->ludoBoard[71] << " │ " << obj->ludoBoard[72] << " │                 │ " << obj->ludoBoard[82] << " │ " << obj->ludoBoard[81] << " │ " << obj->ludoBoard[80] << " │ " << obj->ludoBoard[79] << " │ " << obj->ludoBoard[78] << " │ " << obj->ludoBoard[41] << " │\n";
    cout << "\t│___│___│___│___│___│___│                 │___│___│___│___│___│___│\n";
    cout << "\t│   │   │   │   │   │   │                 │   │   │   │   │   │   │\n";
    cout << "\t│ " << obj->ludoBoard[66] << " │ " << obj->ludoBoard[65] << " │ " << obj->ludoBoard[64] << " │ " << obj->ludoBoard[63] << " │ " << obj->ludoBoard[62] << " │ " << obj->ludoBoard[61] << " │                 │ " << obj->ludoBoard[47] << " │ " << obj->ludoBoard[46] << " │ " << obj->ludoBoard[45] << " │ " << obj->ludoBoard[44] << " │ " << obj->ludoBoard[43] << " │ " << obj->ludoBoard[42] << " │\n";
    cout << "\t│___│___│___│___│___│___│_________________│___│___│___│___│___│___│\n";
    cout << "\t                        │__" << obj->ludoBoard[60] << "__│__" << obj->ludoBoard[87] << "__│__" << obj->ludoBoard[48] << "__│                        \n";
    cout << "\t      " << obj->ludoBoard[8] << "           " << obj->ludoBoard[9] << "     │__" << obj->ludoBoard[59] << "__│__" << obj->ludoBoard[86] << "__│__" << obj->ludoBoard[49] << "__│     " << obj->ludoBoard[12] << "           " << obj->ludoBoard[13] << "      \n";
    cout << "\t                        │__" << obj->ludoBoard[58] << "__│__" << obj->ludoBoard[85] << "__│__" << obj->ludoBoard[50] << "__│                        \n";
    cout << "\t                        │__" << obj->ludoBoard[57] << "__│__" << obj->ludoBoard[84] << "__│__" << obj->ludoBoard[51] << "__│                        \n";
    cout << "\t      " << obj->ludoBoard[10] << "           " << obj->ludoBoard[11] << "     │__" << obj->ludoBoard[56] << "__│__" << obj->ludoBoard[83] << "__│__" << obj->ludoBoard[52] << "__│     " << obj->ludoBoard[14] << "           " << obj->ludoBoard[15] << "      \n";
    cout << "\t                        │__" << obj->ludoBoard[55] << "__│__" << obj->ludoBoard[54] << "__│__" << obj->ludoBoard[53] << "__│                        \n";
    sem_post(&L1);
    pthread_exit(NULL);
}

/*token playable means the tokens present on the board it means
token that ramaining to play with*/
int tokenPlayable(int player)
{
    int x = 0;
    for (int i = 0; i < obj.tokenNum; i++)
    {
        if (obj.playTokens[player][i] != ' ')
        {
            x++;
        }
    }
    return x;
}

/*update the display after the player turn and giving the turn
to the next player we use thread to display the board created*/
void updateDisp(int player)
{
    string playerName = obj.namePlayer[player];
    cout << "This is the turn of " << playerName << endl;
    pthread_create(&t_id[0], NULL, Display_ludoBoard, (void*)&obj);
    pthread_join(t_id[0], NULL);
}

/*available tokens present in home you can take out any of it
when you get 6 and also check if the tokens are present inside
the house or not*/
bool availableToken_Home(int player, char c)
{
    int counter = 0;
    for (int i = 0; i < obj.tokenNum; i++)
    {
        if (obj.playTokens[player][i] == c)
        {
            counter++;
            return counter;
        }
    }
    return counter;
}

/*function to check the tokens after the dice is rolled means if the
token is ot on the field and dice give you something except 6 you cannot
move any thing in the field and if 6 come token will be taken out from
the house to the field and if it is less then 6 and token is present in
the field we can only move that token*/
void diceToken_cond(int player, int dice)
{
    if ((dice != 6 and !token_InField(obj.playerSelect)))
    {
        return;
    }
    if (dice == 6 and !token_InField(obj.playerSelect))
    {
        pthread_create(&t_id[obj.playerSelect], NULL, bringToken_Field, NULL);
        pthread_join(t_id[obj.playerSelect], NULL);
    }
    else if (token_InField(obj.playerSelect))
    {
        movmentToken(obj.playerSelect, obj, dice);
    }
}

/*kill token function first check the position for token is empty or there already
a token present playerKill is the variable which token will be killed. First we will
detect the player if it is on the safe place we will not be able to kill it and also
you cannot kill your own token or place two token at one place. I use the kill_t1
here that will tell us that the token is killed and the index on which it is killed
and also the score of the token will get zero and using thread to get that token out
that was killed*/
void killToken(int playerIndex, int player, int pos, LUDOgame& obj, int dice)
{
    if (obj.ludoBoard[pos] != ' ')
    {
        int i, j;
        int playerKill, index;
        for (i = 0; i < 4; i++)
        {
            for (j = 0; j < obj.tokenNum; j++)
            {
                if (obj.token[i][j] == obj.ludoBoard[pos])
                {
                    playerKill = i;
                    index = j;
                    break;
                }
            }
        }
        if (pos == startIndex_tok[playerKill])
        {
            if (playerKill == player)
            {
                cout << "Token already present there\n";
            }
            else
            {
                cout << "Cannot be killed player is at start\n";
            }
            if (token_InField(player) >= 2)
            {
                cout << "Choose other token\n";
                movmentToken(player, obj, dice);
                Kill_t1 = true;
            }
            else
            {
                Kill_t1 = true;
                return;
            }
        }
        else if (playerKill == player)
        {
            cout << "Same house token cannot kill each other\n";
            if (token_InField(player) >= 2)
            {
                cout << "Choose other token\n";
                movmentToken(player, obj, dice);
                Kill_t1 = true;
            }
            else
                return;
        }
        else
        {
            int pos_ludoBoard = homePosition_tok[playerKill][index];
            obj.ludoBoard[pos] = ' ';
            obj.tokenPlay_infield[playerKill][index] = ' ';
            obj.score[playerKill][index] = 0;
            obj.ludoBoard[pos_ludoBoard] = obj.ludoBoard[pos];
            obj.playTokens[playerKill][index] = obj.token[playerKill][index];
            if (pos == startIndex_tok[player])
            {
                fieldCheck_tok = true;
                pthread_create(&t_id[1], NULL, bringToken_Field, NULL);
                pthread_join(t_id[1], NULL);
                Kill_t1 = true;
            }
        }
    }
}

/*token movement will be done if there is only one token it will move the value
of the dice otherwise if two or more tokens are present in the field you can move
any of them and if dice gives you 6 it will ask you that you want a token out from
the house or want to move the tokens already on the field and if the token is at the
last positions and value comes greater than required it cannot move it if it is the
last token or the other token donoy come out of the house*/
void movmentToken(int player, LUDOgame& obj, int dice)
{
    char choice = 'z';
    bool move = true;
    if (dice == 6 and tokenPlayable(player))
    {
        move = false;
        cout << "Do you want to take another token out?" << endl;
        cout << "Type (Y) if you want and (N) if you don't want: ";
        do
        {
            cin >> choice;
            cout << endl;
            if (choice != 'Y' and choice != 'N')
            {
                cout << "you can only select from (Y) and (N): ";
            }
        } while (choice != 'Y' and choice != 'N');
    }
    if (choice == 'Y')
    {
        pthread_create(&t_id[1], NULL, bringToken_Field, NULL);
        pthread_join(t_id[1], NULL);
    }
    else if (choice == 'N' or move)
    {
        char choose;
        int index;
        cout << "Which token you want to move: ";
        do
        {
            index = -1;
            cin >> choose;
            for (int i = 0; i < obj.tokenNum; i++)
                if (obj.token[player][i] == choose)
                    index = i;
            if (index == -1 or obj.tokenPlay_infield[player][index] != choose)
                cout << "Token not present. choose right one: ";

        } while (index == -1 or obj.tokenPlay_infield[player][index] != choose);
        int total_dice2 = obj.score[player][index] + dice;
        if (total_dice2 == 56)
        {
            cout << "Token arrive home" << endl;
            funcToken_won(player, index);
            return;
        }
        else if (total_dice2 > 55)
        {
            cout << "Cannot move ahead";
            if (token_InField(player) == 2 or token_InField(player) == 3)
            {
                cout << "Choose another token\n";
                movmentToken(player, obj, dice);
                checkKill_t1 = true;
            }
            else
            {
                return;
            }
        }
        positionToken_handle(player, index, dice, obj);
        if (dice == 6)
        {
            dice = rand() % 6 + 1;
            updateDisp(player);
            cout << "You got a 6 so\n";
            cout << "Dice rolled: " << dice << endl;
            movmentToken(player, obj, dice);
        }
    }
}

/*token positions will be handeled as the score of the token is stored as it move
from the starting position to the current position our index number should be greater
than 16 and if our score get greater than 67 we will mode it and take it back to 16 or
greater than 16. If the token is zero we will add the score to it and if it is killing
another token we will make it to zero and in the end we will update its score*/
void positionToken_handle(int player, int index, int dice, LUDOgame& obj)
{
    int start = startIndex_tok[player];
    int previous = start + obj.score[player][index];
    int totalDice = previous + dice;
    int position;
    if (player >= 1)
    {
        if (previous > 67)
            previous %= 52;
        if (obj.score[player][index] + dice > 50)
        {
            handler_homePath(player, index, dice, obj, previous);
            return;
        }
        if (previous == 67)
        {
            position = 15 + dice;
            killToken(index, player, position, obj, dice);
            if (Kill_t1 or checkKill_t1)
            {
                Kill_t1 = false;
                checkKill_t1 = false;
                return;
            }
            obj.ludoBoard[position] = obj.ludoBoard[previous];
        }
        else if (totalDice > 67)
        {
            position = (totalDice) % 52;
            killToken(index, player, position, obj, dice);
            if (Kill_t1 or checkKill_t1)
            {
                Kill_t1 = false;
                checkKill_t1 = false;
                return;
            }
            obj.ludoBoard[position] = obj.ludoBoard[previous];
        }
        else
        {
            position = totalDice;
            killToken(index, player, position, obj, dice);
            if (Kill_t1 or checkKill_t1)
            {
                Kill_t1 = false;
                checkKill_t1 = false;
                return;
            }
            obj.ludoBoard[position] = obj.ludoBoard[previous];
        }
        obj.ludoBoard[previous] = ' ';
    }
    else
    {
        position = totalDice;
        killToken(index, player, position, obj, dice);
        if (Kill_t1 or checkKill_t1)
        {
            Kill_t1 = false;
            checkKill_t1 = false;
            return;
        }
        obj.ludoBoard[position] = obj.ludoBoard[previous];
        obj.ludoBoard[previous] = ' ';
    }
    obj.score[player][index] += dice;
}

/*tokens that are present outside there home means they
are on the field*/
int token_InField(int player)
{
    int x = 0;
    for (int i = 0; i < obj.tokenNum; i++)
    {
        if (obj.tokenPlay_infield[player][i] != ' ')
        {
            x++;
        }
    }
    return x;
}

/*there is a limit of score to each token as after passsing specific indexes
they will move inside there homes that will be given to each player tokens from
where those tokens will move inside the house and the score of the token is
indremented with the value of the dice gives us*/
void handler_homePath(int player, int index, int dice, LUDOgame& obj, int previous)
{
    if (obj.score[player][index] >= 51)
    {
        if (player == 1)
        {
            previous = obj.score[player][index] + 22;
        }
        else if (player == 2)
        {
            previous = obj.score[player][index] + 32;
        }
        else if (player == 3)
        {
            previous = obj.score[player][index] + 27;
        }
    }
    int ludoBoard_pos = obj.score[player][index] + dice;
    if (player == 1)
    {
        ludoBoard_pos += 22;
    }
    else if (player == 2)
    {
        ludoBoard_pos += 32;
    }
    else if (player == 2)
    {
        ludoBoard_pos += 27;
    }
    obj.ludoBoard[ludoBoard_pos] = obj.ludoBoard[previous];
    obj.ludoBoard[previous] = ' ';
    obj.score[player][index] += dice;
}

/*we use a temproray variable in this case x to check that your token
has reached your home base or how many other has reached the house*/
int arriHome(int player)
{
    int x = 0;
    for (int i = 0; i < obj.tokenNum; i++)
    {
        if (obj.wonToken[player][i] != ' ')
        {
            x += 1;
        }
    }
    return x;
}

/* using the token won function and taking there mod as we want to get 16 as it is
the most small value in the board and we have to get all the next values greater than
that value. Also assigning the index numbers from where the token will move inside there
houses to complete. Checking the token that are out of the house and moving them outside
of the players tokken array as they have finish and if more tokens present i will give
bonus turn to the player to move other tokens*/
void funcToken_won(int player, int index)
{
    int tempPos = startIndex_tok[player] + obj.score[player][index];
    if (player != 0)
    {
        if (tempPos > 67)
        {
            tempPos %= 52;
        }
        if (obj.score[player][index] >= 51)
        {
            if (player == 1)
            {
                tempPos = obj.score[player][index] + 22;
            }
            else if (player == 2)
            {
                tempPos = obj.score[player][index] + 32;
            }
            else if (player == 3)
            {
                tempPos = obj.score[player][index] + 27;
            }
        }
    }
    obj.tokenPlay_infield[player][index] = ' ';
    obj.playTokens[player][index] = ' ';
    obj.ludoBoard[tempPos] = ' ';
    obj.wonToken[player][index] = obj.token[player][index];
    if (arriHome(player) == obj.tokenNum)
    {
        cout << obj.namePlayer[player] << " is the winner\n";
        winner = true;
        return;
    }
    int dice = rand() % 6 + 1;
    updateDisp(player);
    cout << "Another turn as one of your token finish\n";
    cout << "Dice rolled: " << dice << endl;
    if (dice != 6 and !token_InField(player))
    {
        return;
    }
    else if (dice == 6 and !token_InField(player))
    {
        pthread_create(&t_id[1], NULL, bringToken_Field, NULL);
        pthread_join(t_id[1], NULL);

    }
    else if (token_InField(player))
    {
        movmentToken(player, obj, dice);
    }
}

/*at start we use semaphore so no thread will distrub this process this
is used to bring the tokenout to the field to play there can be max of
four tokens that can come on the field and if all four are out we cannot
take another token out. If all the tokens are out we have to choose which
token can use the turn and if the tokken is at home we will get it out by
a 6 and place it to the first index of its home frome where it starts and
storing the home indexes empty to know no token is present in home*/
void* bringToken_Field(void* argu)
{
    sem_wait(&L2);
    if (arriHome(obj.playerSelect) == 4 or token_InField(obj.playerSelect) == obj.tokenNum)
    {
        return NULL;
    }
    int index;
    if (!fieldCheck_tok)
    {
        cout << "Token to take out ( ";
        for (int i = 0; i < obj.tokenNum; i++)
        {
            if (obj.playTokens[obj.playerSelect][i] != ' ')
            {
                cout << obj.playTokens[obj.playerSelect][i] << ' ';
            }
        }
        cout << "): ";
        do
        {
            cin >> tokChoice_in_field;
            if ((!availableToken_Home(obj.playerSelect, tokChoice_in_field)))
            {
                cout << "Wrong select from available tokens only: ";
            }
        } while (!availableToken_Home(obj.playerSelect, tokChoice_in_field));

        fieldCheck_tok = true;
    }
    for (int i = 0; i < obj.tokenNum; i++)
    {
        if (obj.token[obj.playerSelect][i] == tokChoice_in_field)
        {
            index = i;
        }
    }
    int start = startIndex_tok[obj.playerSelect];
    if (fieldCheck_tok)
    {
        obj.ludoBoard[start] = obj.ludoBoard[homePosition_tok[obj.playerSelect][index]];
        obj.ludoBoard[homePosition_tok[obj.playerSelect][index]] = ' ';
        obj.playTokens[obj.playerSelect][index] = ' ';
        obj.tokenPlay_infield[obj.playerSelect][index] = tokChoice_in_field;
        fieldCheck_tok = false;
        int dice = rand() % 6 + 1;
        updateDisp(obj.playerSelect);
        cout << "Another turn to take the token out" << endl;
        cout << "Dice rolled: " << dice << endl;
        movmentToken(obj.playerSelect, obj, dice);
    }
    sem_post(&L2);
}

/*how our game will be started we will give all the default values
to the board start and no token will be on the field all the starting
values will be zero and giving name to the tokens according to the 
tokens that are decided to play with and the number of tokens placed
can be played with and also the board is displayed using threads it
also takes the players name and also sleep for the next turn*/
void* startGame(void* argu)
{
    char start;
    int dice = 0;
    obj.playerSelect = 0;
    char tokenName = 'A';
    int cal_tokenPlace = 0;
    for (int i = 0; i < 88; i++)
        obj.ludoBoard[i] = ' ';
    for (int i = 0; i < obj.numPlayer; i++)
    {
        for (int j = 0; j < obj.tokenNum; j++)
        {
            obj.tokenPlay_infield[i][j] = ' ';
            obj.wonToken[i][j] = ' '; 
            obj.score[i][j] = 0; 
            cal_tokenPlace = (i * 4) + j;
            obj.ludoBoard[cal_tokenPlace] = tokenName;
            obj.token[i][j] = tokenName;
            obj.playTokens[i][j] = tokenName;
            tokenName++;
        }
    }
    while (true)
    {
        for (int i = 0; i < obj.numPlayer; i++)
        {
            do
            {
                obj.playerSelect = rand() % obj.numPlayer;
            } while (selPlayer[obj.playerSelect] == 1);
            pthread_create(&t_id[obj.playerSelect], NULL, Display_ludoBoard, (void*)&obj);
            pthread_join(t_id[obj.playerSelect], NULL);
            cout << endl;
            string player_name = obj.namePlayer[obj.playerSelect];
            cout << "This is the turn of " << player_name << ": " << endl;
            dice = rand() % 6 + 1;
            cout << "Dice rolled: " << dice << endl;
            sleep(1);
            diceToken_cond(obj.playerSelect, dice);
            selPlayer[obj.playerSelect] = 1;
            if (winner)
            {
                break;
            }
        }
        if (winner)
        {
            winner = false;
            break;
        }
        for (int i = 0; i < 4; i++)
        {
            selPlayer[i] = 0;
        }
    }
    pthread_exit(NULL);
}

