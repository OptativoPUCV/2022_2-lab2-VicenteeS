#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "list.h"

typedef struct Node Node;

struct Node {
    void * data;
    Node * next;
    Node * prev;
};

struct List {
    Node * head;
    Node * tail;
    Node * current;
};

typedef List List;

Node * createNode(void * data) {
    Node * new = (Node *)malloc(sizeof(Node));
    assert(new != NULL);
    new->data = data;
    new->prev = NULL;
    new->next = NULL;
    return new;
}

List * createList() {
  List *l = (List *) malloc (sizeof(List));
  l->head = NULL;
  l->current = NULL;

     return (l);
}

void * firstList(List * list) 
{ 
  Node *nodo = list->head;
  list->current = nodo;
  
  if(nodo != NULL)
  {
    void *primero = nodo->data;
    return (primero);
  }
  else
  {
    return(NULL);
  }
}

void * nextList(List * list) 
{
  Node *nodo;
  if(list->current != NULL)
  {
    nodo = list->current->next;
    list->current = nodo;
    
    if(nodo != NULL)
    {
      void *siguiente = nodo->data;
      return (siguiente);
    }  
    else
    {
      return(NULL);
    }
  }
  else
  {
    return (NULL);
  }
}

void * lastList(List * list) 
{
  Node *nodo = list->tail;
  list->current = nodo;
  
  if(nodo != NULL)
  {
    void *ultimo = nodo->data;
    return (ultimo);
  }
  else
  {
    return(NULL);
  }
}

void * prevList(List * list) 
{
  Node *nodo;
  if(list->current != NULL)
  {
    nodo = list->current->prev;
    list->current = nodo;
      
    if(nodo != NULL)
    {  
      void *anterior = nodo->data;
      return (anterior);  
    }
    else
    {
      return(NULL);
    }
  }
  else
  {
    return NULL;
  } 
}

void pushFront(List * list, void * data) 
{
  Node *newNode = createNode(data);
  
  if(list->head != NULL)
  {
    list->head->prev = newNode;
    newNode->next = list->head;  
    list->head = newNode;
  }
  else
  {
    list->head = newNode;
    list->tail = newNode;
  }
}

void pushBack(List * list, void * data) {
    list->current = list->tail;
    pushCurrent(list,data);
}

void pushCurrent(List * list, void * data) 
{
  Node *newNode = createNode(data);
  
  if(list->current == list->tail)
  {
    list->current->next = newNode;
    newNode->prev = list->current;
    list->tail = newNode;
  }
  else
  {
    Node *nextNode = list->current->next;
    list->current->next = newNode;
    newNode->prev = list->current;
    newNode->next = nextNode;
    nextNode->prev = newNode;
  }
}

void * popFront(List * list) {
    list->current = list->head;
    return popCurrent(list);
}

void * popBack(List * list) {
    list->current = list->tail;
    return popCurrent(list);
}

void * popCurrent(List * list) {
  
  Node *nodo = list->current;
  
  if(nodo == NULL) return NULL;
  
  if(list->head == nodo)
  {
    nodo->next->prev = NULL;
    list->head = nodo->next;
    list->current = nodo->next;    
    void * dato = nodo->data;
    free(nodo);
    return(dato);
  }
  else
  {
    if(list->tail == nodo)
    {
      nodo->prev->next = NULL;
      list->tail = nodo->prev;
      list->current = NULL;    
      void * dato = nodo->data;
      free(nodo);
      return(dato);
    }
    else
    {
      nodo->prev->next = nodo->next;
      nodo->next->prev = nodo->prev;
      list->current = nodo->next;    
      void * dato = nodo->data;
      free(nodo);
      return(dato);
    }
  }
}

void cleanList(List * list) {
    while (list->head != NULL) {
        popFront(list);
    }
}