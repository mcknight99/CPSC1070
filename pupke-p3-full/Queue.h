//Sam Pupke
//CPSC 1070
//11 Nov 2023

#ifndef QUEUE_H
#define QUEUE_H

#include <cstddef> //for using NULL return values for T

//i wonder if i can use templates instead of making string specific
//(i'm trying to not use the textbook because writing this myself could be great for learning)
//ok so autograder doesn't like templates so i made a backup of the templates and redid the class for chars :(
//template T so if we wanted to stack strings, ints, floats, etc into the queue, then we don't need extra code

struct Node {
  char data;
  Node* next;
  Node(char item) : data(item), next(nullptr) {} //constructor for a Node, storing the T param item in data, and next as a nullptr //I actually did follow the textbook for the node struct for guidance but I wanted to construct differently
};

class Queue{

public:

  //default constructor for a Queue
  Queue();

  //add a template to the end of the queue
  void enqueue(char item);

  //removes the front element of the queue
  void dequeue();

  //remove the front element of the queue, returning it
  void dequeue(char &c);

  //return the rear element in the queue
  char rear();
  
  //return the front element in the queue
  char front();

  //returns true if the queue is full 
  bool isFull();

  //returns true if the queue is empty
  bool isEmpty();

  //returns the front, then dequeues it and puts it at the rear
  char cycle();

  //clears the entire queue by dequeueing while full
  void clear();

  //returns the size of the queue
  int size();

  //clone a queue for resetting in cipher
  Queue clone(const Queue& original);
private:
  Node* frontPtr;
  Node* rearPtr;

};

#endif
