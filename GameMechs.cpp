#include "GameMechs.h"
#include "MacUILib.h"

GameMechs::GameMechs()
{
    input = NULL;
    exitFlag = false;
    loseFlag - false;
    boardSizeX = 20;
    boardSizeY = 10;
    score = 0;
}

GameMechs::GameMechs(int boardX, int boardY)
{
    input = NULL;
    exitFlag = false;
    loseFlag = false;
    boardSizeX = boardX;
    boardSizeY = boardY;
    score = 0;
}

// do you need a destructor?
// no distructor needed since memory isnt allocated for anything in gameMechs

bool GameMechs::getExitFlagStatus()
{
    return exitFlag;
}

bool GameMechs::getLoseFlagStatus()
{
    return loseFlag;
}

char GameMechs::getInput()
{
    if (MacUILib_hasChar())
    {
        input = MacUILib_getChar();        
    }

    switch(input)
    {
        case 27:
            setExitTrue();
            break;
        
        default:
            break;
    }
    return input;
}


int GameMechs::getBoardSizeX()
{
    return boardSizeX;

}

int GameMechs::getBoardSizeY()
{
    return boardSizeY;
}


void GameMechs::setExitTrue()
{
    exitFlag = true;
}

void GameMechs::setLoseFlag()
{
    loseFlag = true;
}

void GameMechs::setInput(char this_input)
{
    this_input = input;
}

void GameMechs::clearInput()
{
    input = NULL;
}

int GameMechs::getScore()
{
    return score;
}

void GameMechs::incrementScore()
{
    score += 1;
}

