#include"FunctionGenerator.h"

void * AllocateMemory( int size , BOOL bExit)
{
    void * pvMem;
    pvMem = malloc(size);
    if(!pvMem)
    {
        printf("Memory Cannot Allocated");
        if(bExit)
            exit(1);
    }
    return pvMem;
}

int GenerateRandomInteger( int maxValue)
{
    return ( rand() % (maxValue + 1) );
}

int * GenerateRandomIntArray(int arrSize , int maxValue)
{
    int * pArr;
    pArr = AllocateMemory(sizeof(int) * arrSize , TRUE);

    int i;
    for (i = 0 ; i < arrSize ; i++)
    {
        pArr[i] = GenerateRandomInteger(maxValue);
    }

    return pArr;
}

char GenerateRandomChar(BOOL Uppercase)
{
    if ( Uppercase)
        return (char)((int)'A' + rand() % ALPHABET_LENGTH);
    else
        return (char)((int)'a' + rand() % ALPHABET_LENGTH);
}

char * GenerateRandomString ( BOOL Uppercase , int maxlength)
{
    int size = GenerateRandomInteger( maxlength) + 1 ;

    char * pSzstr = AllocateMemory(sizeof(char) * (size + 1) , TRUE );
    int i;
    for (i = 0 ; i < size ; i++)
    {
        pSzstr[i] = GenerateRandomChar(Uppercase);
    }
    pSzstr[size] = '\0';

    return pSzstr;
}


int FindMinValue( int * pArr , int arr_size)
{
    int i;
    int min_value = pArr[0];
    for (i = 0 ; i < arr_size; i++)
    {
        if (pArr[i] < min_value )
            min_value = pArr[i];

    }
    return min_value;
}

int FindMinValueIndex( int * pArr , int arr_size)
{
    int i;
    int min_index;
    for ( i = 0 ; i < arr_size ; i++)
    {
        if ( pArr[i] < pArr[min_index])
            min_index = i;
    }
    return min_index;
}

int FindMinValueIndexInterval( int * pArr , int start , int end)
{
    int i;
    int min_index = start;

    for (i = start + 1 ; i < end ; i++)
    {
        if ( pArr[i] < pArr[min_index])
            min_index = i;
    }
    return min_index;
}

void SwapInIntArray(int * pArr, int first, int second)
{
    int temp = pArr[first];
    pArr[first] = pArr[second];
    pArr[second] = temp;
}

void SimpleSort(int * pArr , int arr_size)
{
    int i;
    int min_index;
    for ( i = 0 ; i < arr_size - 1 ; i++)
    {
        min_index = FindMinValueIndexInterval(pArr , i , arr_size);
        SwapInIntArray(pArr , i , min_index);
    }
}

BOOL IsInOrder(int * pArr, int arr_size)
{
    int i;

    for(i = 0 ; i < arr_size - 1; i++)
    {
        if (pArr[i] > pArr[i+1] )
            return FALSE;
    }

    return TRUE;
}

int FindInIntArray( int * pArr, int arr_size , int toFind)
{
    int i;

    for (i = 0 ; i < arr_size ; i++)
    {
        if (pArr[i] == toFind)
            return i;
    }
    return NOT_FOUND;
}

int FindInIntArrayInterval(int * pArr, int start , int end,int toFind)
{
    int i ;

    for ( i = start ; i < end ; i++)
    {
        if (pArr[i] == toFind)
            return i;
    }
    return NOT_FOUND;

}



IntArray * CreateIntArray(int size)
{
    IntArray * pArr;
    pArr = AllocateMemory(sizeof(IntArray), TRUE);
    pArr->arr = AllocateMemory(sizeof(int) * size , TRUE);
    pArr->item_count = 0;
    pArr->capacity = size;

    return pArr;
}

BOOL AddItemToIntArray(IntArray * pArr, int toAdd)
{
    if ( pArr->item_count == pArr->capacity)
        return FALSE;

    pArr->arr[pArr->item_count] = toAdd;
    pArr->item_count++;
    return TRUE;
}

void PrintIntArray(IntArray * pArr)
{
    int i;
    for (i=0;i<pArr->item_count;i++)
    {
        printf("[%d].Element of array is : %d\n",i , pArr->arr[i]);
    }
}

BOOL RemoveFromIntArray(IntArray * pArr , int toDelete)
{
    int i;
    int indexToFind;

    for (i = 0 ; i < pArr->item_count ; i++)
    {
        if (pArr->arr[i] == toDelete)
            {
                indexToFind = i;
                break;
            }
    }

    if ( i == pArr->item_count)
        return FALSE;

    for (i = indexToFind ; i < pArr->item_count - 1 ; i++)
        pArr->arr[i] = pArr->arr[i + 1];

    pArr->item_count--;

    return TRUE;
}
