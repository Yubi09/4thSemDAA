#include<stdio.h>
#include<stdlib.h>

typedef struct head{
  struct object *head;
  struct object *tail;
  int size;
} Head;

typedef struct object{
  int data;
  struct object *next;
  Head *prev;
} Object;

int findSet(Head *x)
{
  return x->head->prev;
}

int SameSet(Head *x, Head *y)
{
  return (findSet(x) == findSet(y));
}

Head *makeSet(int data){
  Head *header = (Head *)malloc(sizeof(Head));
  header->head = (Object *)malloc(sizeof(Object));
  header->tail = (Object *)malloc(sizeof(Object));
  header->size = 1;

  header->head->data = data;
  header->head->next = NULL;
  header->head->prev = header;

  header->tail = header->head;
  return header;
}

void Union(Head *x, Head *y)
{
  Head *x = x->head->prev;
  Head *y = y->head->prev;
  if (x->size > y->size)
  {
    Object *temp = y->head, *prev;
    while(temp)
    {
      prev = temp;
      temp->prev = x;
      temp = temp->next;
    }
    x->tail->next = y->head;  
    x->tail = prev;
    x->size += y->size;
    return;
  }
  Object *temp = x->head, *prev;
  while(temp)
  {
    prev = temp;
    temp->prev = y;
    temp = temp->next;
  }
  y->tail->next = x->head;
  y->tail = prev;
  y->size += x->size;
}

