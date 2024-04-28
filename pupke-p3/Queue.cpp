//Sam Pupke
//CPSC 1070
//11 Nov 2023

#include "Queue.h"

//default constructor for a queue
template <typename T>
Queue<T>::Queue() {
  frontPtr=nullptr;
  rearPtr=nullptr;
}

//add a template to the end of the queue
template <typename T>
void Queue<T>::enqueue(T item) {
 
  Node<T>* newNode = new Node<T>(item); //new node template pointer using the item parameter
  if(isEmpty()) {
    frontPtr = rearPtr = newNode; //if the queue is empty, the front is the rear is the newNode
  } else if(!isFull()){
    rearPtr->next = newNode; //the "previous" rear (about to change) link to the next node is changed from null (presumably) to the newNode ptr
    rearPtr = newNode; // the rear node pointer is now the newest added to the queue
  }
}

//remove the front element of the queue
template <typename T>
void Queue<T>::dequeue() {
  T c = 0;
  dequeue(c);
}

//remove the front element of the queue, returning it through &c
template <typename T>
void Queue<T>::dequeue(T &c) {
  if(isEmpty()) {
    return; //cannot dequeue from an empty queue
  }
  Node<T>* scratch = frontPtr;
  c = frontPtr->data;
  frontPtr = frontPtr->next;
  delete scratch;
}

//return the rear element in the queue
template <typename T>
T Queue<T>::rear() {
  if(rearPtr!=nullptr) {//prevent a segfault by making sure the pointer isnt null
    return rearPtr->data;
  } else {//and if it is, then return a null value of the T type static casted (otherwise it gets angy)
    return static_cast<T>(NULL);
  }
}

//return the front element in the queue
template <typename T>
T Queue<T>::front() {
  if(frontPtr!=nullptr) {//prevent a segfault by making sure the pointer isnt null
    return frontPtr->data;
  } else { //and if it is, then return a null value of the T type static casted (otherwise it gets angy)
    return static_cast<T>(NULL);
  }
}

//returns true if the queue is full (if it has things...? how can a vector be full except for just having elements)
template <typename T>
bool Queue<T>::isFull() {
  return size()>=100;
}

//returns true if the queue is empty
template <typename T>
bool Queue<T>::isEmpty() {
  return frontPtr==nullptr;
}

//returns the front, then dequeues it and puts it at the rear
template <typename T>
T Queue<T>::cycle() {
  T scratch = front();
  dequeue();
  enqueue(scratch);
  return scratch;
}

//clears the entire queue by dequeueing while full
template <typename T>
void Queue<T>::clear() {
  while(!isEmpty()) {
    dequeue();
  }
}

//returns the size of the queue
template <typename T>
int Queue<T>::size() {
  int count = 0;
  Node<T>* currentPtr = frontPtr;
  while(currentPtr != nullptr) {
    count++;
    currentPtr=currentPtr->next;
  }
  return count;
}

//so apparently using templates you need to instantiate the template classes because the main won't know which ones to make and won't make one for every type, so you have to instantiate the templates when you're done/ready

template class Queue<char>;
