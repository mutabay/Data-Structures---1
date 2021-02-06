#ifndef BST_H_INCLUDED
#define BST_H_INCLUDED
#include"General.h"
#include"DLL.h"

#define MAX(a,b)    ((a>b)?a:b)

typedef struct BinarySearchTree
{
    struct BinarySearchTree * left;
    struct BinarySearchTree * right;
    DATA_TYPE data;
}BST;


BST * CreateBST(DATA_TYPE data);
BST * InsertBST(BST * vertex,DATA_TYPE data);
void PrintBST(BST * vertex);
BOOL Search(BST * vertex,DATA_TYPE toFind);
BOOL SearchIter(BST * vertex,DATA_TYPE toFind);
DATA_TYPE FindMax(BST * vertex);
DATA_TYPE FindMin(BST * vertex);
int Height1 (BST * vertex);
int Height(BST * vertex);
int Depth (BST * vertex , DATA_TYPE toFind);
void printLevelOrder(BST * vertex);
void printGivenLevel(BST * vertex,int depth);
int CountOfNodes(BST * vertex);
BOOL IsBinary(BST * vertex);
BOOL IsSame(BST * vertex1,BST * vertex2);
BOOL Path(BST * vertex,int sum);
BST * CopyOdd(BST * vertex,BST * OddVertex);
BOOL getLeafCount(BST * vertex);
void Convert2DLL(BST * vertex,BST ** pHead);

#endif // BST_H_INCLUDED
