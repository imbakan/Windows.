
// Queue - First In First Out

#include <stdlib.h>
#include "queue.h"

// constructor
CQueue::CQueue()
{
	First = Last = NULL;
	Count = 0;
}

// destructor
CQueue::~CQueue()
{
	int value;

	while (!IsEmpty())
		Remove(&value);
}

// Kunin ang bilang ng mga node sa list.
int CQueue::GetCount()
{
	return Count;
}

// Alamin  kung wala nang laman ang list.
bool CQueue::IsEmpty()
{
	return (Count == 0);
}

// Magdagdag ng node sa hulihan ng list.
//                                                                       add
//                                                               <---------------
//      First                                             Last                     Node
//     +----+    +----+    +----+    +----+    +----+    +----+                   +----+
//     |    |--->|    |--->|    |--->|    |--->|    |--->|    |---> NULL          |    |---> NULL
//     +----+    +----+    +----+    +----+    +----+    +----+                   +----+
//
void CQueue::Add(int value)
{
	NODE *Node;

	Node = new NODE;
	Node->value = value;
	Node->Next = NULL;

	if (IsEmpty())
	{
		First = Last = Node;
	}
	else
	{
		Last->Next = Node;
		Last = Node;
	}

	Count++;
}

// Magbawas ng node sa unahan ng list.
//
//               remove
//         <-----------------
//      First                                                                 Last
//     +----+              +----+    +----+    +----+    +----+    +----+    +----+
//     |    |--->          |    |--->|    |--->|    |--->|    |--->|    |--->|    |---> NULL
//     +----+              +----+    +----+    +----+    +----+    +----+    +----+
//
void CQueue::Remove(int* value)
{
	NODE *Node;

	Node = First;
	*value = Node->value;

	First = First->Next;
	Count--;

	if(IsEmpty())
		Last = First;

	delete Node;
}

//
