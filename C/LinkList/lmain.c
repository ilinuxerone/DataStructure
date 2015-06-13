#include <stdio.h>
#include <stdlib.h>
#include "LinkList.h"


struct Value
{
    LinkListNode head;
    int v;
};

int main(int argc, char *argv[]) 
{
    int i = 0;
    LinkList* list = list_init();
    
    struct Value v1;
    struct Value v2;
    struct Value v3;
    struct Value v4;
    struct Value v5;
    
    v1.v = 1;
    v2.v = 2;
    v3.v = 3;
    v4.v = 4;
    v5.v = 5;
    
    list_add(list, (LinkListNode*)&v1, list_length(list));
    list_add(list, (LinkListNode*)&v2, list_length(list));
    list_add(list, (LinkListNode*)&v3, list_length(list));
    list_add(list, (LinkListNode*)&v4, list_length(list));
    list_add(list, (LinkListNode*)&v5, list_length(list));
    
    for(i=0; i<list_length(list); i++)
    {
        struct Value* pv = (struct Value*)list_get(list, i);
        
        printf("%d\n", pv->v);
    }
    
    while( list_length(list) > 0 )
    {
        struct Value* pv = (struct Value*)list_del(list, 0);
        
        printf("%d\n", pv->v);
    }
    
    list_destroy(list);
    
    return 0;
}

