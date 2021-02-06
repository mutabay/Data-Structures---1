#ifndef ARR_QUEUE_H_INCLUDED
#define ARR_QUEUE_H_INCLUDED
#include"General.h"

typedef struct queueInArray
{
    DATA_TYPE * data;
    int size;
    int capacity;
    int front;
    int back;
}Arr_Queue;

Arr_Queue * CreateQueque(int capacity);
void DestroyQueue(Arr_Queue * arr_Queue);
BOOL IsFull_Queue(Arr_Queue * arr_Queue);
BOOL IsEmpty_Queue(Arr_Queue * arr_Queue);
BOOL Enqueue(Arr_Queue * arr_Queue , DATA_TYPE toAdd);
BOOL Dequeue(Arr_Queue * arr_Queue , DATA_TYPE * pReturn);
BOOL Peek_ArrQueue(Arr_Queue * arr_Queue , DATA_TYPE * pReturn);

#endif // ARR_QUEUE_H_INCLUDED
