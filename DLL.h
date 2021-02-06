#ifndef DLL_H_INCLUDED
#define DLL_H_INCLUDED
#include"General.h"


typedef struct DoublyLinkedList
{
    int data;
    struct DoublyLinkedList * next;
    struct DoublyLinkedList * prev;

}DLLI;

DLLI * PrepareItem (int data);

DLLI * AddItemToEnd( DLLI * pHead , int toAdd);

void PrintDoubleLinkedList( DLLI * pHead);

DLLI * DeleteItem(DLLI * pHead, int toDelete);


int FindNodeCount(DLLI * pHead);


#endif // DLL_H_INCLUDED
