//Parinda Rahman-1931804042-section 2 cse 225
#include "Unsortedtype.h"
#include <iostream>
using namespace std;
template <class ItemType>
UnsortedType<ItemType>::UnsortedType() {
 length = 0;
 listData = NULL;
 currentPos = NULL;
}
template <class ItemType>
int UnsortedType<ItemType>::LengthIs() {
 return length;
}
template <class ItemType>
void UnsortedType<ItemType>::InsertItem(ItemType  item)
{
 NodeType* location;
 location = new NodeType;
 location->info = item;
 location->next = listData;
 listData = location;
 length++;
}

template <class ItemType>
void UnsortedType<ItemType>::ResetList()
{
 currentPos = NULL;
}
template <class ItemType>
void UnsortedType<ItemType>::GetNextItem(ItemType&  item)
{
 if (currentPos == NULL)
 currentPos = listData;
 else
 currentPos = currentPos->next;
 item = currentPos->info;
}
template <class ItemType>
void UnsortedType<ItemType>::MakeEmpty()
{
    NodeType* tempPtr;
    while (listData != NULL)
    {
        tempPtr = listData;
        listData = listData->next;
        delete tempPtr;
    }
        length = 0;
}
template <class ItemType>
UnsortedType<ItemType>::~UnsortedType()
{
    MakeEmpty();
}
