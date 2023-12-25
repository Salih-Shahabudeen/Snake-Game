#include "Food.h"


Food::Food(GameMechs& gameMechanics)
{
    mechRef = &gameMechanics;
    // foodPos.x = 0;
    // foodPos.y = 0;
    // foodPos.symbol = '*';
    foodBucket = new objPosArrayList(); 
    
}

Food::~Food()
{
    // Deallocate memory for the foodBucket
    delete foodBucket;
}

void Food::generateFood(objPosArrayList &blockOff)
{
    

    
    int randomX;
    int randomY;
    bool okPos = true;
    srand(static_cast<unsigned int>(time(nullptr)));
    for (int i = 0; i<=5; i ++){
        do
        {
            //set boolean variable for determining whether position is valid
            okPos = true;

            //randomly generate x and y coordinates
            randomX = rand() % ((mechRef->getBoardSizeX()) - 2) + 1; 
            randomY = rand() % ((mechRef->getBoardSizeY()) - 2) + 1;

            // iterate through the blockOff list to determine any conflicts between the current and previous position
            for(int i = 0; i < blockOff.getSize(); ++i)
            {
                // create tempPosition as an objPos datatype
                objPos tempPosition;

                //store the value of each i into tempPosition
                blockOff.getElement(tempPosition, i);

                // check if that indexes value matches with the random positions generated
                if(tempPosition.x == randomX && tempPosition.y == randomY)
                {
                    //if it matches, flag that the position is not correct and reenter the dowhile loop
                    okPos = false;
                    // no need to check if the next index is invalid if the current one is
                    break;
                }

            } 

        }while (!okPos);
        if (i <= 3)
        {
        objPos foodPosition(randomX,randomY,'*');
        foodBucket->insertHead(foodPosition);
        }
        else if (rand()%2 == 0)
        {
        objPos foodPosition(randomX,randomY,'%');
        foodBucket->insertHead(foodPosition);
        }else
        {
        objPos foodPosition(randomX,randomY,'$');
        foodBucket->insertHead(foodPosition);
        }
        
    }
}

  
objPosArrayList* Food::getFoodPos()
{
    //returnPos = foodPos;
    // return the reference to the foodBucket array list
    return foodBucket;
}