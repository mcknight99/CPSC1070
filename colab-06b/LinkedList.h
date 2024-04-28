//Sam Pupke
//CPSC 1071: 010, E3:A++
//5 Dec 2023

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.h"

struct LinkedList{
  struct Node* head;
};

//insert a node at the end of the list
void insertNode(struct LinkedList* list, const char* newData);

//return 1 if the head node is null, return 0 if the head node isn't null
int isEmpty(struct LinkedList* list);

//print the list in order
void printList(struct LinkedList* list);

//deallocate all 
void emptyList(struct LinkedList* list);

//make a linked list returning the head
struct Node* makeList(void);

//return the length of the list from head to tail node
int getLength(struct LinkedList* list);

//@param insert gets put between values in the list @param value1 and @param value2
//return 1 if it could, 0 if it couldn't
int insertBetween(struct LinkedList* list, char* insert, const char* value1, const char* value2);

#endif
