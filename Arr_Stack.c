#include"Arr_Stack.h"

Arr_Stack * CreateArrStack(int capacity)
{
    Arr_Stack * pStack = AllocateMemory(sizeof(Arr_Stack),EXIT_PROGRAM);
    pStack->capacity = capacity;
    pStack->data = AllocateMemory(sizeof(DATA_TYPE) * capacity,EXIT_PROGRAM);
    pStack->size = 0;
    pStack->top = -1;
    return pStack;
}

BOOL IsEmpty(Arr_Stack * pStack)
{
    if (0 == pStack->size)
        return TRUE;
    else
        return FALSE;
}

BOOL IsFull(Arr_Stack * pStack)
{
    if (pStack->capacity == pStack->size)
        return TRUE;
    else
        return FALSE;
}

BOOL Push(Arr_Stack * pStack,DATA_TYPE toAdd)
{
    if (TRUE == IsFull(pStack))
        return FALSE;
    else{
        ++pStack->top;
        pStack->data[pStack->top] = toAdd;
        ++pStack->size;
        return TRUE;
    }
}

BOOL Pop(Arr_Stack * pStack,DATA_TYPE * pReturn)
{
    if(TRUE == IsEmpty(pStack))
        return FALSE;
    else{
        *pReturn = pStack->data[pStack->top];
        --pStack->top ;
        --pStack->size;
        return TRUE;
    }
}
BOOL Peek(Arr_Stack * pStack, DATA_TYPE * pReturn)
{
    if (TRUE == IsEmpty(pStack))
        return FALSE;
    else{
        *pReturn = pStack->data[pStack->top];
        return TRUE;
    }
}

void PrintArray(Arr_Stack * pStack)
{
    int i;
    if (TRUE == IsEmpty(pStack))
        printf("Stack is empty\n");
    else{
        for (i = 0 ; i < pStack->size; i++)
            printf("[%d]data is -> %d\n",i,pStack->data[i]);
    }
}


