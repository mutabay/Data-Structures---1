#include"Arr_Queue.h"

Arr_Queue * CreateQueque(int capacity)
{
    Arr_Queue * arr_Queue;
    arr_Queue = AllocateMemory(sizeof(Arr_Queue),EXIT_PROGRAM);
    arr_Queue->capacity = capacity;
    arr_Queue->size = 0;
    arr_Queue->data = AllocateMemory(sizeof(DATA_TYPE) * capacity,EXIT_PROGRAM);
    arr_Queue->front = 0;
    arr_Queue->back = 0;
    return arr_Queue;
}

void DestroyQueue(Arr_Queue * arr_Queue)
{
    free(arr_Queue->data);
    free(arr_Queue);
}

BOOL IsFull_Queue(Arr_Queue * arr_Queue)
{
    return (arr_Queue->size == arr_Queue->capacity);
}
BOOL IsEmpty_Queue(Arr_Queue * arr_Queue)
{
    return (arr_Queue->size == 0);
}

BOOL Enqueue(Arr_Queue * arr_Queue , DATA_TYPE toAdd)
{
    if(FALSE == IsFull_Queue(arr_Queue))
    {
        arr_Queue->data[arr_Queue->back] = toAdd;
        ++arr_Queue->back;
        arr_Queue->back = arr_Queue->back % arr_Queue->capacity;
        ++arr_Queue->size;
        return TRUE;
    }
    return FALSE;
}

BOOL Dequeue(Arr_Queue * arr_Queue , DATA_TYPE * pReturn)
{
    if (FALSE == IsEmpty_Queue(arr_Queue))
    {
        *pReturn = arr_Queue->data[arr_Queue->front];
        ++arr_Queue->front;
        arr_Queue->front = arr_Queue->front % arr_Queue->capacity;
        --arr_Queue->size;
        return TRUE;
    }
    return FALSE;
}

BOOL Peek_ArrQueue(Arr_Queue * arr_Queue , DATA_TYPE * pReturn)
{
    if (FALSE == IsEmpty_Queue(arr_Queue))
    {
        *pReturn = arr_Queue->data[arr_Queue->front];
        return TRUE;
    }
    return FALSE;
}






