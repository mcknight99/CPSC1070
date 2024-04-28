//Sam Pupke
//CPSC 1070
//11 Nov 2023

#include "Queue.h"

//default constructor for a queue
Queue::Queue() {
  frontPtr=nullptr;
  rearPtr=nullptr;
}

//add a template to the end of the queue
void Queue::enqueue(char item) {
 
  Node* newNode = new Node(item); //new node template pointer using the item parameter
  if(isEmpty()) {
    frontPtr = rearPtr = newNode; //if the queue is empty, the front is the rear is the newNode
  } else if(!isFull()){
    rearPtr->next = newNode; //the "previous" rear (about to change) link to the next node is changed from null (presumably) to the newNode ptr
    rearPtr = newNode; // the rear node pointer is now the newest added to the queue
  }
}

//remove the front element of the queue
void Queue::dequeue() {
  char c = 0;
  dequeue(c);
}

//remove the front element of the queue, returning it through &c
void Queue::dequeue(char &c) {
  if(isEmpty()) {
    return; //cannot dequeue from an empty queue
  }
  Node* scratch = frontPtr;
  c = frontPtr->data;
  frontPtr = frontPtr->next;
  delete scratch;
}

//return the rear element in the queue
char Queue::rear() {
  if(rearPtr!=nullptr) {//prevent a segfault by making sure the pointer isnt null
    return rearPtr->data;
  } else {//and if it is, then return a null value of the T type static casted (otherwise it gets angy)
    return static_cast<char>(NULL);
  }
}

//return the front element in the queue
char Queue::front() {
  if(frontPtr!=nullptr) {//prevent a segfault by making sure the pointer isnt null
    return frontPtr->data;
  } else { //and if it is, then return a null value of the T type static casted (otherwise it gets angy)
    return static_cast<char>(NULL);
  }
}

//returns true if the queue is full (if it has things...? how can a vector be full except for just having elements)
bool Queue::isFull() {
  return size()>=100;
}

//returns true if the queue is empty
bool Queue::isEmpty() {
  return frontPtr==nullptr;
}

//returns the front, then dequeues it and puts it at the rear
char Queue::cycle() {
  char scratch = front();
  dequeue();
  enqueue(scratch);
  return scratch;
}

//clears the entire queue by dequeueing while full
void Queue::clear() {
  while(!isEmpty()) {
    dequeue();
  }
}

//returns the size of the queue
int Queue::size() {
  int count = 0;
  Node* currentPtr = frontPtr;
  while(currentPtr != nullptr) {
    count++;
    currentPtr=currentPtr->next;
  }
  return count;
}

Queue Queue::clone(const Queue& original) {
  return Queue{original};
}
