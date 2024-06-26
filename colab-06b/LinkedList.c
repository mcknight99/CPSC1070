//Sam Pupke
//CPSC 1071: 010, E3:A++
//5 Dec 2023

#include "LinkedList.h"
#include <stdlib.h>
#include <string.h>
//will need insert, delete, isEmpty()

//@param insert gets put betwen values in the list @param value1 and @param value2
//return 1 if it could, 0 if it couldn't
int insertBetween(struct LinkedList* list, char* insert, const char* value1, const char* value2) {
  struct Node* current = list->head->next; //going to iterate starting at first and second values
  struct Node* last = list->head; //we need to keep the last node to make sure the new inserted node goes between the last and current, with the last now pointing to the new and the new pointing to the current. 
  while(last->next!=NULL) {
    if(strcmp(value1, last->data)==0 && strcmp(value2, current->data)==0) { //if the two node datas match param1 and 2
      struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
      strcpy(newNode->data, insert); //the newNode has data @param insert

      newNode->next=current; //the newNode points to the second node
      last->next=newNode; //the last node points to the newNode
      return 1; //return true if the function could insert @param insert between @param value2 and @param value2
    }
    current=current->next;
    last=last->next;
    
  }
  return 0;//return false if the function couldn't insert @param insert between @param value1 and @param value2
}


//print the list in order
void printList(struct LinkedList* list) {
  struct Node* current = list->head;
  current = current->next;
  int length = getLength(list)-1;

  if(length>2) { //printing a, b, and c.
    printf("You've entered the following nodes: %s", list->head->data);
    int i;
    for(i = 0; i<length-1; i++) { //-2 because the last will have "and", and we're skipping the first one to prevent a leading comma
      printf("%s, ", current->data);
      current = current->next;
    }
    printf("and %s\n", current->data);
  } else if(length==2) {
    printf("You've entered the following nodes: %s", current->data);
    current = current->next;
    printf(" and %s\n", current->data);
  } else if(length==1) {
    printf("You've entered the following node: %s\n", current->data);
  } else if (length==0) {
    printf("You've entered no nodes!\n");
  } else {
    printf("You've entered an imaginary amount of nodes, so many nodes you've overflowed the int counter, or a negative amount of nodes. wtf?\n");
  }

  
}


//insert a node at the end of the list
void insertNode(struct LinkedList* list, const char* newData) {
  struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
  struct Node* last = list->head;

  // Set data and next pointer for the new node
  strcpy(newNode->data, newData);
  newNode->next = NULL;

  // If the list is empty, make the new node the head
  if(list==NULL) {
    list = newNode;
    return;
  }

  // Traverse to the end of the list
  while(last->next!=NULL) {
    last = last->next;
  }

  // Insert the new node at the end
  last->next = newNode;  
}

//return as an int because bool doesn't exist
int isEmpty(struct LinkedList* list) {
  if(list==NULL) {
    return 1;
  } else {
    return 0;
  }
}

//make a linked list returning the head
struct Node* makeList(void) {
  struct Node* head = NULL;
  head = (struct Node*)malloc(sizeof(struct Node));
  strcpy(head->data, "");
  head->next=NULL;
  return head;
}

//deallocate all
void emptyList(struct LinkedList* list) {
  struct Node* current = list->head;
  struct Node* next;
  while(current!=NULL) {
    next = current->next;
    free(current);
    current = next;
  }
  list->head=NULL;
}

//return the length of the list from head to tail node
int getLength(struct LinkedList* list)  {
  int length = 0;
  struct Node* current = list->head;

  while(current!=NULL) {
    length++;
    current = current->next;
  }
  return length;
}
