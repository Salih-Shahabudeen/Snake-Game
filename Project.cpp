#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "Player.h"
#include "GameMechs.h"
#include "Food.h"

using namespace std;

#define DELAY_CONST 100000

GameMechs *myGM;
Food *myFood;
Player *myPlayer;

void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);

int main(void)
{

    Initialize();

    while (myGM->getExitFlagStatus() == false)
    {
        GetInput();
        RunLogic();
        DrawScreen();
        LoopDelay();
    }

    CleanUp();
}

void Initialize(void)
{
    MacUILib_init();
    MacUILib_clearScreen();

    myGM = new GameMechs(26, 13);
    myFood = new Food(*myGM);
    myPlayer = new Player(myGM,myFood);
    objPosArrayList blockOff;
    myFood->generateFood(blockOff);
}

void GetInput(void)
{
}

void RunLogic(void)
{
    myPlayer->updatePlayerDir();
    myPlayer->movePlayer(); 
}

void DrawScreen(void)
{
    MacUILib_clearScreen();

    objPosArrayList *playerPosList = myPlayer->getPlayerPos();
    objPosArrayList *foodBucket = myFood->getFoodPos();

    //objPos foodPos;
    //myFood->getFoodPos(foodPos);


    for (int i = 0; i < myGM->getBoardSizeY(); i++)
    {
        // print bottom and top border
        for (int k = 0; k < myGM->getBoardSizeX() ; k++)
        {
            // print top and bottom border
            if (i == myGM->getBoardSizeY() - 1 || i == 0)
            {
                MacUILib_printf("#");
            }

            // print right and left border
            if (i > 0 && i < myGM->getBoardSizeY() - 1)
            {
                if (k == myGM->getBoardSizeX() -1 || k == 0)
                {
                    MacUILib_printf("#");
                }
                else
                {
                    bool isPlayerPos = false;
                    for (int j = 0; j < playerPosList->getSize(); j++)
                    {
                        objPos playerPos;
                        playerPosList->getElement(playerPos, j);

                        if (k == playerPos.x && i == playerPos.y)
                        {
                            MacUILib_printf("%c", playerPos.symbol);
                            isPlayerPos = true;
                            break;
                        }
                    }
                    bool isFoodPos = false;
                    for (int j = 0; j < foodBucket->getSize(); j++)
                    {
                        objPos foodPos;
                        foodBucket->getElement(foodPos, j);
                        objPos headPos;
                        playerPosList->getHeadElement(headPos);
                        if (k == foodPos.x && i == foodPos.y && !(foodPos.x == headPos.x && foodPos.y == headPos.y))
                        {
                            MacUILib_printf("%c", foodPos.symbol);
                            isFoodPos = true;
                            break;
                        }
                    }
                    if (!isPlayerPos && !isFoodPos)
                    {
                        MacUILib_printf(" ");
                    }
                }
            }
        }
        MacUILib_printf("\n");
    }
    MacUILib_printf("Use W,A,S,D to move, and Esc to end game\n");
    MacUILib_printf("'%c' Gives 5 points and makes Snake 10 units bigger\n'$' gives 10 points. Have Fun!!\n",'%');
    MacUILib_printf("Score: %d", myGM->getScore());
}

void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}

void CleanUp(void)
{
    MacUILib_clearScreen();
    if (myGM->getLoseFlagStatus()){
        MacUILib_printf("Game Over\nFinal Score: %d", myGM->getScore());
    }
    MacUILib_uninit();
}
