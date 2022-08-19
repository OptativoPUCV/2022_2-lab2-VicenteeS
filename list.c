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
  //l->size = 0;
  l->current = NULL;

     return (l);
}

void * firstList(List * list) {
  if(list == NULL) return NULL;
  Node *n = list->head;
    return (n);
}

void * nextList(List * list) {
    return NULL;
}

void * lastList(List * list) {
    return NULL;
}

void * prevList(List * list) {
    return NULL;
}

void pushFront(List * list, void * data) {
  //if(list == NULL) return NULL;
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

void pushCurrent(List * list, void * data) {
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
    return NULL;
}

void cleanList(List * list) {
    while (list->head != NULL) {
        popFront(list);
    }
}