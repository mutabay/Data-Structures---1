#include"SLL_Stack.h"
#include"General.h"

SLLI * CreateSLLI (DATA_TYPE toCreate)
{
    SLLI * pHead;
    pHead = AllocateMemory(sizeof(SLLI),EXIT_PROGRAM);
    pHead->data = toCreate;
    pHead->next = NULL;
    return pHead;
}

void DestroySLLI(SLLI * pTemp)
{
    pTemp->next = NULL;
    free(pTemp);
}

SLLI * PushSLL(SLLI * pHead, DATA_TYPE toAdd)
{
    if (NULL == pHead)
        return CreateSLLI(toAdd);
    else
    {
        SLLI * pNew = CreateSLLI(toAdd);
        pNew->next = pHead;
        pHead = pNew;
        return pHead;
    }
}

SLLI * PopSLL(SLLI * pHead,DATA_TYPE * pReturn)
{
    if(NULL ==  pHead)
        return NULL;
    else
    {
        SLLI * pTemp = pHead;
        *pReturn = pTemp->data;
        pHead = pHead->next;
        DestroySLLI(pTemp);
        return pHead;
    }
}

void PeekSLL(SLLI * pHead)
{
    printf("%d is Peeked\n",pHead->data);
}

void printSLLI(SLLI * pHead)
{
    while (NULL != pHead)
    {
        printf("SLL STACK IS ->%d\n",pHead->data);
        pHead = pHead->next;
    }
}
