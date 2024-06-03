#include<stdio.h>
#include<stdlib.h>
#include"DoubleLinkList.h"
#define true 1
#define false 0
int InitDLinkList(DLlist *list)
{
    list->len=0;
    list->head=NULL;
    list->tail=NULL;
    return true;
}
struct Node* CreateNode(ElementType element)
{
    struct Node* NewNode=(struct Node*)malloc(sizeof(struct Node));
    if(NewNode==NULL)
    {
        printf("CreateNode malloc error");
        return NULL;
    }
    NewNode->data=element;
    NewNode->next=NULL;
    NewNode->prev=NULL;
    return NewNode;
}
void InsertTail(DLlist *list, ElementType element)
{
  struct Node*newNode=CreateNode(element);
  if(newNode==NULL)
  {
    printf("inserttail CreateNode error!\n");
    return ;
  }
  if(list->len==0)
  {
   list->head=newNode;
   list->tail=newNode;
  }
  else
  {   
  list->tail->next=newNode;
  newNode->prev=list->tail;
  list->tail=newNode;
  }
  list->len++;
}
void Travel(DLlist *list,void (*func)(ElementType))
{
    struct Node*TravelPoint=list->head;
    while(TravelPoint!=NULL)
    {
      if(func!=NULL)
      {
        func(TravelPoint->data);
      }
      TravelPoint=TravelPoint->next;
    }
    printf("\n");
  
}
int FindFirstByElement(DLlist *list, ElementType element)
{ int count=-1;
   struct  Node *TravelPoint=list->head;
   while(TravelPoint!=NULL)
   {
    if(TravelPoint->data==element)
      return count+1;
      count++;
      TravelPoint=TravelPoint->next;
   }

  return -1;
}
int GetListLen(DLlist *list)
{
  return list->len;
}
void RemoveByElement(DLlist *list, ElementType element)
{
  int count=FindFirstByElement(list,element);
   while(count!=-1)
   {
      RemoveByIndex(list,count); 
      count=FindFirstByElement(list,element);
   }
}
void RemoveByIndex(DLlist *list, int index)
{
   if(index<0||index>=list->len)
   {
    printf("RemoveByIndex invaild error! \n");
    return ;
   }
   if(index==0)
   {
    if(list->len==1)
    {
      free(list->head);
      list->head=NULL;
      list->tail=NULL;
      list->len--;
      return;
    }
    struct  Node *temp=list->head;
    list->head=list->head->next;
    list->head->prev=NULL;
    free(temp);
    list->len--;
    return ;
   }
      if(index==list->len-1)
   {   
      
    struct  Node *temp=list->tail;
    list->tail=list->tail->prev;
    list->tail->next=NULL;
    free(temp);
    list->len--;
    return ;
   }
   struct  Node *TravelPoint=list->head;
   while(index!=0)
   {
      TravelPoint=TravelPoint->next;
      index--;
   }
   TravelPoint->prev->next=TravelPoint->next;
   TravelPoint->next->prev=TravelPoint->prev;
   free(TravelPoint);
   list->len--;

}
void InsertHead(DLlist *list, ElementType element)
{
    struct Node*newNode=CreateNode(element);
  if(newNode==NULL)
  {
    printf("inserttail CreateNode error!\n");
    return ;
  }
  if(list->len=0)
  {
    list->head=newNode;
    list->tail=newNode;
  }
    else
  {   
    list->head->prev=newNode;
    newNode->next=list->head;
    list->head=newNode;   
  }
}
void FreeDLinkList(DLlist *list)
{
  while(list->head!=NULL)
  {
    struct Node*temp=list->head; 
    list->head=list->head->next;

    free(temp);
  }
  list->len=0;
  list->head=NULL;
  list->tail=NULL;
}


