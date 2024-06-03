#include "LinkQueue.h"
#include<stdio.h>
#define true 1
#define false 0
int InitLQueue(LQueue *lq)
{
    return InitDLinkList(&lq->queue);
}

void QPush(LQueue *lq, ElementType element)
{
    InsertTail(&lq->queue,element);
}

ElementType *QPop(LQueue *lq)
{
    if(lq->queue.len==0)
    {
        printf("the queue is empty!\n");
        return NULL;
    }
    lq->FrontData=lq->queue.head->data;
    RemoveByIndex(&lq->queue,0);
    return &lq->FrontData;
}

int IsQEmpty(LQueue *lq)
{
    if(lq->queue.len==0)
    {
        return true;
    }
    else
    {
        return false;
    }

}

struct Node *GetFront(LQueue *lq)
{
    return lq->queue.head;
}

int GetQueueLen(LQueue *q)
{
    return q->queue.len;
}

void FreeLQueue(LQueue *lq)
{
    FreeDLinkList(&lq->queue);
}
