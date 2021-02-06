#ifndef SLL_QUEUE_H_INCLUDED
#define SLL_QUEUE_H_INCLUDED
#include"General.h"

typedef struct SingleLinkedList_Queue
{
    SLLI * front;
    SLLI * rear;
}SLL_Queue;

SLLI * CreateSingleLinkedListItem(DATA_TYPE toCreate);
SLL_Queue * CreateSLLQueueItem();
void DestroySLLItem(SLLI * pTemp);
SLL_Queue * EnqueueSLLI (SLL_Queue * pQueue,DATA_TYPE toAdd);
SLL_Queue * DequeueSLLI(SLL_Queue * pQueue,DATA_TYPE * datum);
BOOL PeekSLL_Queue(SLL_Queue * pQueue, DATA_TYPE * datum);
void printSLLI_Queue(SLL_Queue * pQueue);


#endif // SLL_QUEUE_H_INCLUDED
