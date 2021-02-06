#include"SLL_Queue.h"

SLLI * CreateSingleLinkedListItem(DATA_TYPE toCreate)
{
    SLLI * pItem = AllocateMemory(sizeof(SLLI),EXIT_PROGRAM);
    pItem->data = toCreate;
    pItem->next = NULL;
    return pItem;
}

SLL_Queue * CreateSLLQueueItem()
{
    SLL_Queue * pQueue = AllocateMemory(sizeof(pQueue),EXIT_PROGRAM);
    pQueue->front = NULL;
    pQueue->rear = NULL;
    return pQueue;
}

void DestroySLLItem(SLLI * pTemp)
{
    pTemp->next = NULL;
    free(pTemp);
}
SLL_Queue * EnqueueSLLI (SLL_Queue * pQueue,DATA_TYPE toAdd)
{
    SLLI * pItem = CreateSingleLinkedListItem(toAdd);
    if (NULL == pQueue->rear) //EMPTY QUEUE
    {
        pQueue->front = pItem;
        pQueue->rear = pItem;
    }

    else
    {
        pQueue->rear->next = pItem;
        pQueue->rear = pQueue->rear->next;
    }

    return pQueue;
}


SLL_Queue * DequeueSLLI(SLL_Queue * pQueue,DATA_TYPE * datum)
{
    if (NULL == pQueue->front) // EMPTY QUEUE
        return NULL;
    else
    {
        SLLI * pTemp = pQueue->front;
        *datum = pTemp->data;
        pQueue->front = pQueue->front->next;
        DestroySLLItem(pTemp);
    }
    if (NULL == pQueue->front)
        pQueue->rear = NULL;

    return pQueue;
}

BOOL PeekSLL_Queue(SLL_Queue * pQueue, DATA_TYPE * datum)
{
    if (NULL == pQueue->front)
        return FALSE;
    *datum = pQueue->front->data;
    return TRUE;
}

void printSLLI_Queue(SLL_Queue * pQueue)
{
    SLLI * pTemp = pQueue->front;
    while(NULL != pTemp)
    {
        printf("Item of SLLIQUEUE->%d\n",pTemp->data);
        pTemp = pTemp->next;
    }
    if (NULL == pTemp)
        printf("There has non element\n");
}


