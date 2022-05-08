
// Stack - Last In First Out

#pragma once

typedef struct NODE NODE;

struct NODE
{
	int value;
	NODE* Next;
};

class CStack
{
private:
	NODE* First;
	int Count;

public:	
	CStack();
	~CStack();

	int GetCount();
	bool IsEmpty();
	void Push(int value);
	void Pop(int *value);
};
