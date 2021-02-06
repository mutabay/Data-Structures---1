#include"BST.h"

/* 170706031
 *
 * PSEUDO CODE
 *void PrintFromBottom_Left( Node * root)
 *
 * control root's null situation
 * if ( NULL == root )
 *      return;
 *
 * //Initialize a variable horizontalDistance with 0 of the root node,
 * //keep on adding left child to queue along with the horizontal distance
 * //as horizontalDistance -1 and right chils as horizontalDistance + 1
 * int horizontalDistance =0 ;
 *
 * Treemap which stores key value pair
 * Sorted on key value
 * //Use a TreeMap which stores key value pair sorted on key.
 *
 * Create Queue to store tree nodes in level
 * Order Traversal
 *
 * Assign initialized horizontal distance
 * value to root node and add it to the queue - push().
 * //Every time, we encounter a new horizontal distance or an existing
 * //horizontal distance put the node data for the horizontal distance as
 * //key. For the first time it will add to the map, next time it will
 * //replace the value. This will make sure that the bottom most element
 * //for that horizontal distance is present in the map and if you see the
 * //tree from beneath that you will see that element.
 *
 *  Loop until the queue is empty (standard level order loop)
 *
 *  Loop {
 *
 *  }
 *
 *
 *
 *
 *
 *
 * 170706031
 *
 * Minimum Height of tree
 * Record Size = 310000000
 *  Index/ Key Size = 2 byte
 *  Disk block read/write size = 15 872
 *  Record Countha
 * Record Count = 310000000
 *
 */




BST * CreateBST(DATA_TYPE data)
{
    BST * pRoot;
    pRoot = AllocateMemory(sizeof(BST),EXIT_PROGRAM);
    pRoot->right = NULL;
    pRoot->left = NULL;
    pRoot->data = data;
    return pRoot;
}
BST * InsertBST(BST * vertex,DATA_TYPE toAdd)
{
    if (NULL == vertex)
        return CreateBST(toAdd);

    if (toAdd > vertex->data)
        vertex->right = InsertBST(vertex->right,toAdd);
    else
        vertex->left = InsertBST(vertex->left,toAdd);
    return vertex;
}
void PrintBST(BST * vertex)
{
    if (NULL == vertex)
        return;
    PrintBST(vertex->left);
    printf("Data is ->%d\n",vertex->data);
    PrintBST(vertex->right);
}

BOOL Search(BST * vertex,DATA_TYPE toFind)
{
    if(NULL == vertex)
        return FALSE;

    if (toFind == vertex->data)
        return TRUE;

    else if (toFind < vertex->data)
        return Search(vertex->left,toFind);
    else if (toFind > vertex->data)
        return Search(vertex->right,toFind);

}

BOOL SearchIter(BST * vertex,DATA_TYPE toFind)
{
    while (NULL != vertex)
    {
        if (toFind == vertex->data)
            return TRUE;
        else if (toFind < vertex->data)
            vertex = vertex->left;
        else if (toFind > vertex->data)
            vertex = vertex->right;
    }
    return FALSE;
}
DATA_TYPE FindMax(BST * vertex)
{
    while (NULL != vertex->right)
        vertex = vertex->right;

    return vertex->data;
}

DATA_TYPE FindMin(BST * vertex)
{
    while(NULL != vertex->left)
        vertex = vertex->left;
    return vertex->data;
}
int Height1 (BST * vertex)
{
    if (NULL == vertex)
        return -1;
    int lHeight = Height1(vertex->left);
    int rHeight = Height1(vertex->right);

    if (lHeight < rHeight)
        return rHeight +1;
    else
        return lHeight +1;
}

int Height(BST * vertex)
{
    if (NULL == vertex)
        return -1;
    return ( 1 + MAX(Height(vertex->left),Height( vertex->right)));
}

int Depth (BST * vertex , DATA_TYPE toFind)
{
    int counter = 0;
    while(NULL != vertex)
    {
        if (toFind == vertex->data)
            return counter;
        else if (toFind < vertex->data)
        {
            vertex = vertex->left;
            counter++;
        }
        else if (toFind > vertex->data)
        {
            vertex = vertex->right;
            counter++;
        }
    }
    return -1;

}

void printLevelOrder(BST * vertex)
{
    int height = Height(vertex);
    int i;
    for (i = 0; i < height + 1 ; i++)
    {
        printGivenLevel(vertex,i);
        printf("\n");
    }

}

void printGivenLevel(BST * vertex,int depth)
{
    if (NULL == vertex)
        return;

    if (0 == depth )
        printf("%d ",vertex->data);

    else if(depth > 0)
    {
        printGivenLevel(vertex->left,depth - 1);
        printGivenLevel(vertex->right,depth - 1);
    }
}

int CountOfNodes(BST * vertex)
{
    if (NULL == vertex)
        return 0;
    else
        return CountOfNodes(vertex->left) + 1 + CountOfNodes(vertex->right);
}

BOOL IsBinary(BST * vertex)
{
    if (NULL == vertex)
        return TRUE;
    if (NULL != vertex->right && FindMin(vertex->right) < vertex->data )
        return FALSE;
    if (NULL != vertex->left && FindMax(vertex->left) >= vertex->data)
        return FALSE;
    if (FALSE == IsBinary(vertex->left ) || FALSE == IsBinary(vertex->right) )
        return FALSE;
}

BOOL IsSame(BST * vertex1,BST * vertex2)
{
    if (NULL == vertex1 && NULL == vertex2)
        return TRUE;
    else if (NULL != vertex1 && NULL != vertex2)
    {
        return (vertex1->data == vertex2->data &&
                IsSame(vertex1->left,vertex2->left) &&
                IsSame(vertex1->right,vertex2->right));
    }
    else
        return FALSE;
}


BOOL Path(BST * vertex,int sum)
{
    int pathSum;
    if (NULL == vertex)
        return (0 == sum);
    else
    {
        pathSum = sum - vertex->data;
        return ( Path(vertex->left,pathSum) || Path(vertex->right,pathSum));
    }
}

BST * CopyOdd(BST * vertex,BST * OddVertex)
{
    if(NULL != vertex)
    {
        if (1 == vertex->data % 2)
            OddVertex = InsertBST(OddVertex,vertex->data);
        OddVertex = CopyOdd(vertex->left,OddVertex);
        OddVertex = CopyOdd(vertex->right,OddVertex);
    }
    return OddVertex;

}

int getLeafCount(BST * vertex)
{
    if (NULL == vertex)
        return 0;
    if(NULL == vertex->left && NULL == vertex->right)
        return 1;
    else
        return getLeafCount(vertex->left) + getLeafCount(vertex->right);
}

int counter = 0;
int nonLeafNodes(BST * vertex)
{
    if (NULL == vertex)
        return 0;
    nonLeafNodes(vertex->left);
    if (vertex->right != NULL || vertex->left != NULL )
        counter++;
    nonLeafNodes(vertex->right);
    return counter;
}
int couter = 0;
int SingleChildNode(BST * vertex)
{
    if (NULL != vertex)
    {
        if (NULL == vertex->right && NULL != vertex->left || NULL ==vertex->left && NULL != vertex->right)
            couter++;
        SingleChildNode(vertex->left);
        SingleChildNode(vertex->right);
        return couter;
    }





}
void Convert2DLL(BST * vertex,BST ** pHead)
{
    if (NULL == vertex)
        return;
    //Right Subtree
    Convert2DLL(vertex->right,pHead);
    //Insert Node
    vertex->right = *pHead;

    if (*pHead != NULL)
        (*pHead)->left = vertex;
    *pHead = vertex;
    //Left Subtree
    Convert2DLL(vertex,pHead);
}

