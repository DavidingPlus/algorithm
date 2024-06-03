#ifndef  _DOUBLELINKLIST_H_
#define _DOUBLELINKLIST_H_
#define ElementType void*
#include<stdio.h>
#include<stdlib.h>
struct Node
{
  ElementType data;
  struct Node* next;
  struct Node* prev;
};
struct DLinkList
{
   struct Node *head;
   struct Node *tail;
   int len;
};
typedef struct DLinkList  DLlist;
int InitDLinkList(DLlist *list);
void InsertTail(DLlist *list,ElementType element);
void InsertHead(DLlist *list,ElementType element);
void RemoveByIndex(DLlist *list,int index);
void RemoveByElement(DLlist* list,ElementType element);
int FindFirstByElement(DLlist *list,ElementType element);
int GetListLen(DLlist *list);
void Travel(DLlist *list,void (*func)(ElementType));
void FreeDLinkList(DLlist *list);
#endif