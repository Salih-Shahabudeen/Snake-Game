#include "objPosArrayList.h"

// Check lecture contents on general purpose array list construction, 
// and modify it to support objPos array list construction.


//constructor
objPosArrayList::objPosArrayList()
{
    aList = new objPos[ARRAY_MAX_CAP];
    sizeList = 0;
    sizeArray = ARRAY_MAX_CAP;
}

//destructor
objPosArrayList::~objPosArrayList()
{
    delete[] aList;
}

//returns size
int objPosArrayList::getSize()
{
    return sizeList;
}

//shits all blocks to the right form the end of array
//then sets the first index to the head and adds one to the size of list
void objPosArrayList::insertHead(objPos thisPos)
{
    for (int i = sizeList; i > 0 ; i --){
        aList[i].setObjPos(aList[i-1]);
    }
    aList[0].setObjPos(thisPos);
    sizeList++;

}

//doesn't shift anything but makes the last index a tail and adds one to 
//size of list (goes form left to right)
void objPosArrayList::insertTail(objPos thisPos)
{
    for (int i = 0; i < sizeList ; i ++){
        aList[i].setObjPos(aList[i]);
    }
    aList[sizeList].setObjPos(thisPos);
    sizeList++;
}

//shifts evey thing to the left and removes the last index (empty)
//deletes size of list by one
void objPosArrayList::removeHead()
{
    for (int i = 0; i < sizeList ; i ++){
        aList[i].setObjPos(aList[i+1]);
    }
    sizeList--;
}

//deletes size of list by one removing last element
void objPosArrayList::removeTail()
{
    sizeList--;
}

//gives the position of index 0/head
void objPosArrayList::getHeadElement(objPos &returnPos)
{
    returnPos.setObjPos(aList[0]);
}

//gives the position of final idex/tail
void objPosArrayList::getTailElement(objPos &returnPos)
{
    returnPos.setObjPos(aList[sizeList - 1]);
}

//returns the element given by the index
void objPosArrayList::getElement(objPos &returnPos, int index)
{
    returnPos.setObjPos(aList[index]);
}