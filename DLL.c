#include"DLL.h"

DLLI * PrepareItem (int data)
{
    DLLI * pItem = AllocateMemory(sizeof(DLLI),EXIT_PROGRAM);

    pItem->data = data;
    pItem->next = NULL;
    pItem->prev = NULL;

    return pItem;
}

DLLI * AddItemToEnd( DLLI * pHead , int toAdd)
{
    //CONVERT TO DLLI
    DLLI * pItem = PrepareItem(toAdd);

    //EMPTY LİST
    if (NULL == pHead)
        return pItem;
    //AT LEAST ONE ITEM
    else
    {
        DLLI * pTemp = pHead;
        while(NULL != pTemp->next )
            pTemp = pTemp->next;

        pTemp->next = pItem;
        pItem->prev = pTemp;

        return pHead;
    }

}

void PrintDoubleLinkedList( DLLI * pHead)
{
    while(NULL != pHead)
    {
        printf("Item ----->%d\n",pHead->data);
        pHead = pHead->next;
    }
}


DLLI * DeleteItem(DLLI * pHead, int toDelete)
{
    DLLI * pTemp = pHead;
    while(NULL!= pTemp && pTemp->data != toDelete)
        pTemp = pTemp->next;

    if (NULL != pTemp)
    {   //SET LINKS
        if (NULL != pTemp->prev)
            pTemp-> prev->next = pTemp->next;
        if (NULL != pTemp->next)
            pTemp->next->prev = pTemp->prev;

        //FIRST ITEM WİLL BE REMOWED
        if(pTemp == pHead)
            pHead = pTemp->next;
        //DELETE ITEM
        pTemp->next = NULL;
        pTemp->prev = NULL;
        free(pTemp);
    }

    return pHead;
}

int FindNodeCount(DLLI * pHead)
{
    int counter = 0;
    while(NULL != pHead)
    {
        pHead = pHead->next;
        counter++;
    }
    return counter;
}
