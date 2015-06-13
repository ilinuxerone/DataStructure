#ifndef __SEQLIST_H_
#define __SEQLIST_H_

#define DEBUG
#ifdef DEBUG
	#define LOG_MSG(level, fmt, args...)  {printf("%s--%s:(%d)-[%s]", #level, __FILE__, __LINE__, __func__);	printf(fmt, ##args);}
#else
	#define LOG_MSG()
#endif


typedef void SeqList;
typedef void SeqListNode;

SeqList* seqlist_alloc(int capacity);

void seqlist_free(SeqList* seqlist);

void seqlist_clear(SeqList* seqlist);

int seqlist_length(SeqList* seqlist);

int seqlist_capacity(SeqList* seqlist);

int seqlist_add(SeqList* seqlist, SeqListNode* node, int pos);

SeqListNode* seqlist_get(SeqList* seqlist, int pos);

SeqListNode* seqlist_del(SeqList* seqlist, int pos);

#endif

