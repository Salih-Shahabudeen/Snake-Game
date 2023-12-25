#ifndef FOOD_H
#define FOOD_H

#include <time.h>
#include <stdlib.h>
#include "GameMechs.h"
#include "objPos.h"
#include "objPosArrayList.h"

// call Game mechanics class
class GameMechs;

class Food
{
    private:
    //objPos foodPos;
    GameMechs* mechRef;
    objPosArrayList* foodBucket;

    public:
    Food(GameMechs& gameMechanics);
    ~Food();
    objPosArrayList* getFoodPos();
    void generateFood(objPosArrayList &blockOff);
};

#endif