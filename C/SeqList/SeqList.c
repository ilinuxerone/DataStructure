#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <unistd.h>
#include "SeqList.h"

typedef unsigned  int TSeqListNode;
typedef struct _tag_SeqList
{
	int capacity;
	int length;
	TSeqListNode *node;
}TSeqList;

SeqList* seqlist_alloc(int capacity)
{
	TSeqList* sList = NULL;
	
	if (capacity > 0)
	{
		sList = (TSeqList*)malloc(sizeof(TSeqList) + sizeof(TSeqListNode) * capacity);
	}
	
	if (NULL != sList)
	{
		sList->capacity = capacity;
		sList->length = 0;
		sList->node = (TSeqListNode*)(sList + 1);
	}
	LOG_MSG(DEBUG, "%s\n", "alloc complete!");
	return sList;
} 

void seqlist_free(SeqList* seqlist)
{
	if (NULL != seqlist)
	{
		free(seqlist);	
	}
}

void seqlist_clear(SeqList* seqlist)
{
	TSeqList* sList = (TSeqList*)seqlist;
	
	if (NULL != sList)
	{
		sList->length = 0;
	}
}

int seqlist_length(SeqList* seqlist)
{
	TSeqList* sList = (TSeqList*)seqlist;
	int ret = -1;
	
	if (NULL != sList)
	{
		ret	= sList->length;
	}
	
	return ret;
}

int seqlist_capacity(SeqList* seqlist)
{
	TSeqList* sList = (TSeqList*)seqlist;
	int ret = -1;
	
	if (NULL != sList)
	{
		ret = sList->capacity;	
	}
	
	return ret;
}

int seqlist_add(SeqList* seqlist, SeqListNode* node, int pos)
{
	TSeqList* sList = (TSeqList*)list;
	int ret = (sList != NULL);
	int i = 0;
	
	ret = ret && (sList->length + 1 <= sList->capacity);
	ret = ret && (0 <= pos);
	
	if (ret)
	{
			
	}
	
	return 0;
}

SeqListNode* seqlist_get(SeqList* seqlist, int pos)
{
	
	
	return NULL;
}
SeqListNode* seqlist_del(SeqList* seqlist, int pos)
{
	
	
	return NULL;
}
