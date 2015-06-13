#include <stdio.h>
#include <stdlib.h>
#include "SeqList.h"

int main(int argc, char* argv[])
{
	SeqList* list = seqlist_alloc(5);

	printf("length is: %d\n", seqlist_length(list));
	printf("capacity is :%d\n", seqlist_capacity(list));
	
	
	return 0;
	
}
