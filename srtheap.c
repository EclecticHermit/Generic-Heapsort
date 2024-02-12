#include <stdlib.h>
#include <string.h>
#include "srt.h"

void heapify(void *base, size_t nelem, size_t size, int (*comparison)(const void *, const void *), size_t index)
{	

	char *parent=(char *)base+size*(index);
	char *childLeft=(char *)base+size*(2*index+1);
	char *childRight=(char *)base+size*(2*index+2);
	
	char *nodeLargest=parent;
	
	if((2*index+1)<nelem && comparison(childLeft,parent) > 0)
	{
		nodeLargest=childLeft;
	}
	if((2*index+2)<nelem && comparison(childRight,nodeLargest) > 0)
	{
		nodeLargest=childRight;
	}
	
	if(nodeLargest != parent)
	{
		if(nodeLargest == childLeft)
		{
			index=2*index+1;
			swap(parent, childLeft, size);
		}
		if(nodeLargest == childRight)
		{
			index=2*index+2;
			swap(parent, childRight, size);
		}
		heapify(base, nelem, size, comparison, index);
	}
}
void srtheap(void *base, size_t nelem, size_t size, int (*compar)(const void *, const void *))
{
	for(int i=nelem/2+1; i>=0; --i)
	{	
		heapify(base, nelem, size, compar, i);
	}
	for(int i=nelem-1; i>=0; --i)
	{
		char *top=(char *)base+0;
		char *current=(char *)base+size*i;
		swap(top, current, size);
		heapify(base, i, size, compar, 0);
	}

}

