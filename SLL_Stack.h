#ifndef SLL_STACK_H_INCLUDED
#define SLL_STACK_H_INCLUDED

#include"General.h"



SLLI * CreateSLLI (DATA_TYPE toCreate);
void DestroySLLI(SLLI * pTemp);

SLLI * PushSLL(SLLI * pHead, DATA_TYPE toAdd);
SLLI * PopSLL(SLLI * pHead,DATA_TYPE * pReturn);
void PeekSLL(SLLI * pHead);


void printSLLI(SLLI * pHead);




#endif // SLL_STACK_H_INCLUDED
