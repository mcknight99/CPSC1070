#include <stdio.h>
#include <stdlib.h> //for malloc


struct node{
  int data;//payload
  struct node* next; //address
} *head;

//prototypes
void createList(int n); //prototyping a linked list of n nodes
void displayList();


int main(){
  puts("\nStarting our demo on linked lists in C!\n");

  int n = 0;
  int data = 0;

  printf("enter in the number of nodes you wish: ");
  scanf("%d", &n);

  if(n>0) {
    //we can create our list
    createList(n);

    //make sure we created a list
    displayList();
  } else {
    printf("Unable to create a linked list of size %d\n", n);
    printf("Please re-run program with a number greater than 0\n");
  }

  
  
  puts("\nGoodbye, world!\n");
}

// @param inNode = length as int
void createList(int inNode) {

  //assertion: inNode has a value > 0
  struct node *newNode, *temp;
  int readIn = 0;
  int counter = 0;

  head = (struct node*) malloc(sizeof(struct node));
  //assert head returns a pointer to the address of a node, or null
  if(head == NULL) {
    printf("ERror: memory was not allocated for the head!\n");
  } else {
    //assert memory was allocated for a node
    printf("Enter in the value of node 1: ");
    scanf("%d", &readIn);

    //populate
    head->data=readIn;
    head->next=NULL;

    temp = head;
    
    for(counter = 2; counter<=inNode; counter++) {
      newNode = (struct node*) malloc(sizeof(struct node));
      if(newNode == NULL) {
	printf("Error: memory was not allocated for the node%d!\n", counter);
      } else {
	printf("Enter the value of node %d: ", counter);
	scanf("%d", &readIn);

	//set the new node we just created
	newNode->data=readIn;
	newNode->next=NULL;

	//link in the new node:
	temp->next = newNode;
	temp=temp->next;

	
      }
    }
    
    
  }
}


void displayList() {
  struct node* tempNode;
  unsigned int nodeNum = 1;

  if(head==NULL) {
    printf("The list is empty so there's nothing to print!\n");
  } else {
    tempNode = head;
    while(tempNode != NULL) {
      printf("Node [%d]'s value is %d\n", nodeNum, tempNode->data);
      nodeNum++;
      tempNode = tempNode->next;
    }
  }
  

}
