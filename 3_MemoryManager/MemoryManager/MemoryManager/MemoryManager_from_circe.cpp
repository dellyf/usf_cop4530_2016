#include <cassert>
#include <iostream>
#include "dlUtils.h"
#include "MemoryManager.h"

MemoryManager::MemoryManager(unsigned int memtotal) : memsize(memtotal)
{
	baseptr = new unsigned char[memsize];
	blockdata originalBlock(memsize, true, baseptr);
	firstBlock = new dlNode<blockdata>(originalBlock, NULL, NULL);
}

void MemoryManager::showBlockList()
{
	printDlList(firstBlock, "->");
}

void MemoryManager::splitBlock(dlNode<blockdata> *p, unsigned int chunksize)
{ // Put your code below
	baseptr=new unsigned char[p->info.blocksize - chunksize];
	blockdata split_b(p->info.blocksize - chunksize, true, baseptr);
	insertAfter(firstBlock, p, split_b);
}

unsigned char * MemoryManager::malloc(unsigned int request)
{ // Put your code below

	dlNode<blockdata> *B = firstBlock;

	for (B=firstBlock; B!= NULL; B=B->next)
	{
		if (B->info.free == true)// && B->info.blocksize >= request){
		{	if (B->info.blocksize >= request){
				splitBlock(B, request);	
				B->info.free=false;
				B->info.blocksize=request;
				return B->info.blockptr;
			}
			else
			{
				B->info.blocksize = request;
				B->info.free = false;
				return B->info.blockptr;
			}	
		}
		else
		{
			return NULL;
		}
	}
}

void MemoryManager::mergeForward(dlNode<blockdata> *p)
{ // Put your code below
	
	p->info.blocksize += p->next->info.blocksize;
	dlNode<blockdata> *merge = p->next;
	p->next = p->next->next;
	delete merge;
}

void MemoryManager::mergeBackward(dlNode<blockdata> *p)
{ // Put your code below

	p->info.blocksize += p->next->info.blocksize;
	dlNode<blockdata> *merge = p->prev;
	p->prev = p;
	delete merge;
}

void MemoryManager::free(unsigned char *ptr2block)
{ // Put your code below

	dlNode<blockdata> *free_b = firstBlock;
	for (free_b = firstBlock; free_b != NULL; free_b = free_b->next)
	{
		if (free_b->info.blockptr == ptr2block)
		{
			free_b->info.free = true;

			if (free_b->prev != NULL) {
				if (free_b->prev->info.free == true) {
					mergeForward(free_b);
				}
			}
			if (free_b->next->info.free == true) {
				mergeForward(free_b);
			}
		}
	}
}
