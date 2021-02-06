#ifndef ARR_STACK_H_INCLUDED
#define ARR_STACK_H_INCLUDED
#include"General.h"

typedef struct stackInArray
{
    DATA_TYPE * data;
    int capacity;
    int size;
    int top;
}Arr_Stack;

Arr_Stack * CreateArrStack(int capacity);

BOOL IsEmpty(Arr_Stack * pStack);
BOOL IsFull(Arr_Stack * pStack);

BOOL Push(Arr_Stack * pStack,DATA_TYPE toAdd);
BOOL Pop(Arr_Stack * pStack,DATA_TYPE * pReturn);
BOOL Peek(Arr_Stack * pStack, DATA_TYPE * pReturn);

void PrintArray(Arr_Stack * pStack);

#endif // ARR_STACK_H_INCLUDED
