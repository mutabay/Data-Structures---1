#include <stdio.h>
#include <stdlib.h>

#include"Arr_Stack.h"
#include"SLL_Stack.h"
#include"Arr_Queue.h"
#include"SLL_Queue.h"
#include"BST.h"
#include"DLL.h"

#define ARR_STACK_CAPACITY 10
#define STACK_COUNT 10
#define ARR_QUEUE_CAPACITY 10

int main()
{
    //ARR-STACK TESTING
    /*
    DATA_TYPE data;
    Arr_Stack * arr_stack = NULL;
    arr_stack = CreateArrStack(ARR_STACK_CAPACITY);
    int i;
    for (i = 0 ; i < ARR_STACK_CAPACITY + 2 ;  i++)
    {
        if (FALSE == IsFull(arr_stack))
            Push(arr_stack, i * i);
        else
            printf("StackOverflow\n");
    }
    PrintArray(arr_stack);

    for (i = 0 ; i < ARR_STACK_CAPACITY + 2 ; i++)
    {
        if ( TRUE == Peek(arr_stack,&data) )
            printf("%d Peeked\n",data);
        else
            printf("Stack is empty\n");

        if ( TRUE == Pop(arr_stack , &data))
            printf("%d is deleted\n",data);
        else
            printf("Stack is empty\n");
    }

    PrintArray(arr_stack);
    */


    //SLL STACK TESTING
    /*

    DATA_TYPE pReturn;
    SLLI * pHead = NULL;
    pHead = CreateSLLI(5);
    printSLLI(pHead);
    printf("-----------------------------\n");
    pHead = PushSLL(pHead, 15);
    pHead = PushSLL(pHead, 20);
    pHead = PushSLL(pHead, 25);
    pHead = PushSLL(pHead, 45);
    printSLLI(pHead);
    printf("-----------------------------\n");
    PeekSLL(pHead);
    printf("-----------------------------\n");
    pHead = PopSLL(pHead,&pReturn);
    printf("%d Popped\n",pReturn);
    pHead = PopSLL(pHead,&pReturn);
    printf("%d Popped\n",pReturn);
    pHead = PopSLL(pHead,&pReturn);
    printf("%d Popped\n",pReturn);
    pHead = PopSLL(pHead,&pReturn);
    printf("%d Popped\n",pReturn);

    */


    //ARR-QUEUE TESTING
    /*
    Arr_Queue * arr_queue = CreateQueque(ARR_QUEUE_CAPACITY);
    int i;
    for(i = 0 ; i < ARR_QUEUE_CAPACITY + 2 ; i++)
    {
        if (TRUE == Enqueue(arr_queue,i*i))
            printf("%d is ENQUEUED\n",i*i);
        else
            printf("ENQUEUE NOT SUCCESFULL\n");
    }

    DATA_TYPE pReturn;
    for(i = 0 ; i < ARR_QUEUE_CAPACITY ; i++)
    {
        if (TRUE == Peek_ArrQueue(arr_queue,&pReturn))
            printf("%d is PEEKED\n",pReturn);
        else
            printf("PEEK NOT SUCCESFULL\n");

        if(TRUE == Dequeue(arr_queue,&pReturn))
            printf("%d obtained from queue\n", pReturn);
        else
            printf("GET : QUEUE IS EMPTY!!!\n");
    }

    DestroyQueue(arr_queue);

    */

    //SLL-QUEUE TESTING
    /*
    DATA_TYPE datum ;
    SLL_Queue * pQueue = CreateSLLQueueItem();
    pQueue = EnqueueSLLI(pQueue,15);
    printSLLI_Queue(pQueue);
    printf("------------------------\n");
    pQueue = EnqueueSLLI(pQueue,20);
    pQueue = EnqueueSLLI(pQueue,8);
    pQueue = EnqueueSLLI(pQueue,5);
    pQueue = EnqueueSLLI(pQueue,2);
    printSLLI_Queue(pQueue);
    printf("-----ENQUEUEIS SUCCESFULL--------\n");


        pQueue = DequeueSLLI(pQueue,&datum);
        printf("%d is dequeued\n",datum);

        pQueue = DequeueSLLI(pQueue,&datum);
        printf("%d is dequeued\n",datum);

        pQueue = DequeueSLLI(pQueue,&datum);
        printf("%d is dequeued\n",datum);

        pQueue = DequeueSLLI(pQueue,&datum);
        printf("%d is dequeued\n",datum);

        pQueue = DequeueSLLI(pQueue,&datum);
        printf("%d is dequeued\n",datum);


    printSLLI_Queue(pQueue);
    pQueue = EnqueueSLLI(pQueue,56);
    printSLLI_Queue(pQueue);

    */


    BST * pRoot = NULL;
    pRoot = CreateBST(10);
    pRoot = InsertBST(pRoot,12);
    pRoot = InsertBST(pRoot,8);
    pRoot = InsertBST(pRoot,7);
    pRoot = InsertBST(pRoot,9);
    pRoot = InsertBST(pRoot,11);
    pRoot = InsertBST(pRoot,13);
    pRoot = InsertBST(pRoot,5);
    pRoot = InsertBST(pRoot,3);



    PrintBST(pRoot);

    DATA_TYPE toFind = 12;
    if (TRUE == Search(pRoot,toFind))
        printf("%d is found\n",toFind);
    else
        printf("%d is not found\n",toFind);

    DATA_TYPE toFind2 = 5;
    if (TRUE == Search(pRoot,toFind2))
        printf("%d is found\n",toFind2);
    else
        printf("%d is not found\n",toFind2);

    DATA_TYPE MaxValue = FindMax(pRoot);
    printf("%d is the max value\n",MaxValue);

    DATA_TYPE MinValue = FindMin(pRoot);
    printf("%d is the min value\n",MinValue);

    int height1 = Height1(pRoot);
    printf("Heigth is %d\n",height1);

    int height = Height(pRoot);
    printf("Heigth is %d\n",height);

    DATA_TYPE toFind3 = 212;
    int depth = Depth(pRoot,toFind3);
    printf("Depth of %d is %d\n",toFind3,depth);

    printf("----------------------\n");

    printLevelOrder(pRoot);

    printf("----------------------\n");

    int NodeCount = CountOfNodes(pRoot);
    printf("Count of node is %d\n",NodeCount);

    if (TRUE == IsBinary(pRoot))
        printf("Yes this is binary\n");

    printf("----------------------\n");

    BST * OddVertex = NULL;
    OddVertex = CopyOdd(pRoot,OddVertex);
    printLevelOrder(OddVertex);

    printf("----------------------\n");


    printf("----------------------\n");
    int leaf = getLeafCount(pRoot);
    printf("%d\n",leaf);

    int nonleaf = nonLeafNodes(pRoot);
    printf("%d\n",nonleaf);

    int oneleaf = SingleChildNode(pRoot);
    printf("%d\n",oneleaf);

    return 0;
}
