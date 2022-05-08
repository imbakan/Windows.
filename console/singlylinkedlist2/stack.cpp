
// Stack - Last In First Out

#include <stdlib.h>
#include "stack.h"

// constructor
CStack::CStack()
{
	First = NULL;
	Count = 0;
}

// destructor
CStack::~CStack()
{
	int value;

	while (!IsEmpty())
		Pop(&value);
}

// Kunin ang bilang ng mga node sa list.
int CStack::GetCount()
{
	return Count;
}

// Alamin  kung wala nang laman ang list.
bool CStack::IsEmpty()
{
	return (Count == 0);
}

// Magdagdag ng node sa ibabaw ng list.
//
//     +----+
//     |    | Node         |
//     +----+              |
//        |                |
//        v                | push
//                         |
//                         |
//                         v
//     +----+
//     |    | First
//     +----+
//        |
//        v
//     +----+
//     |    |
//     +----+
//        |
//        v
//     +----+
//     |    |
//     +----+
//        |
//        v
//      NULL
//
void CStack::Push(int value)
{
	NODE *Node;

	Node = new NODE;
	Node->value = value;
	Node->Next = NULL;

	if (IsEmpty())
	{
		First = Node;
	}
	else
	{
		Node->Next = First;
		First = Node;
	}

	Count++;
}

// Magbawas ng node sa ibabaw ng list.
//
//     +----+              ^
//     |    | First        |
//     +----+              |
//        |                |
//        v                | pop
//                         |
//                         |
//                         |
//     +----+
//     |    |
//     +----+
//        |
//        v
//     +----+
//     |    |
//     +----+
//        |
//        v
//     +----+
//     |    |
//     +----+
//        |
//        v
//      NULL
//
void CStack::Pop(int* value)
{
	NODE *Node;

	Node = First;
	*value = Node->value;

	First = First->Next;
	Count--;

	delete Node;
}
