#ifndef _LINKLIST_H_
#define _LINKLIST_H_

typedef void LinkList;
//typedef struct _tag_LinkListNode LinkListNode;
typedef struct _tag_LinkListNode
{
    LinkListNode* next;
}LinkListNode;

LinkList* list_init();

void list_destroy(LinkList* list);

void list_clear(LinkList* list);

int list_length(LinkList* list);

int list_add(LinkList* list, LinkListNode* node, int pos);

LinkListNode* list_get(LinkList* list, int pos);

LinkListNode* list_del(LinkList* list, int pos);

#endif

