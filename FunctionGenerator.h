#ifndef FUNCTIONGENERATOR_H_INCLUDED
#define FUNCTIONGENERATOR_H_INCLUDED

#include"General.h"

typedef struct tagIntArray
{
    int * arr;
    int item_count ;
    int capacity;
}IntArray;

void * AllocateMemory( int size , BOOL bExit);

int GenerateRandomInteger( int maxValue);
int * GenerateRandomIntArray(int arrSize , int maxValue);
char GenerateRandomChar(BOOL Uppercase);
char * GenerateRandomString ( BOOL Uppercase , int maxlength);

int FindMinValueIndexInterval( int * pArr , int start , int end);
void SwapInIntArray(int * pArr, int first, int second);
void SimpleSort(int * pArr , int arr_size);
BOOL IsInOrder(int * pArr, int arr_size);

int FindInIntArray( int * pArr, int arr_size , int toFind);
int FindInIntArrayInterval(int * pArr, int start , int end,int toFind);

IntArray * CreateIntArray(int size);
BOOL AddItemToIntArray(IntArray * pArr, int toAdd);
void PrintIntArray(IntArray * pArr);
BOOL RemoveFromIntArray(IntArray * pArr , int toDelete);





#endif // FUNCTIONGENERATOR_H_INCLUDED
