#ifndef _LINKQUEUE_H_
#define _LINKQUEUE_H_
#include"DoubleLinkList.h"

struct LinkQueue
{
  DLlist queue;
  ElementType FrontData;
};
typedef struct LinkQueue LQueue;
int InitLQueue(LQueue *lq);
void QPush(LQueue *lq,ElementType element);
ElementType* QPop(LQueue *lq);
int IsQEmpty(LQueue *lq);
struct Node* GetFront(LQueue *lq);
int GetQueueLen(LQueue *q);
void FreeLQueue(LQueue *lq);
#endif