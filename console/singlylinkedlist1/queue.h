
// Queue - First In First Out

#pragma once

typedef struct NODE NODE;

struct NODE
{
	int value;
	NODE* Next;
};

class CQueue
{
private:
	NODE* First, * Last;
	int Count;

public:	
	CQueue();
	~CQueue();

	int GetCount();
	bool IsEmpty();
	void Add(int value);
	void Remove(int *value);
};

