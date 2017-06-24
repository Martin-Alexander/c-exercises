#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int data;
  struct Node *next;
} node;

// node * lastNode(node *firstNode){
//   node *currentNode = firstNode;

//   while(1){
//     if((*currentNode).next == NULL){
//       return currentNode;
//     } else {
//       currentNode = (*currentNode).next;
//     }
//   }
// }

// void newNode(int data, node *firstNode){
//   node *myLastNode = lastNode(firstNode);

//   node newNode = {1, NULL};
//   (*myLastNode).next = &newNode;
// }

void newNode(int data, node *lastNode){

  node newNode;
  newNode.data = data;
  newNode.next = NULL;
  (*lastNode).next = &newNode;
}

void printNodes(node *firstNode){
  node *currentNode = firstNode;

  while(currentNode != NULL){
    printf("%d\n", (*currentNode).data);
    currentNode = (*currentNode).next;
  }
}

void main(){

  node node1 = {0, NULL};
  node node2 = {1, NULL};
  node node3 = {2, NULL};

  node1.next = &node2;
  node2.next = &node3;

  node newNode;
  newNode.data = 3;
  newNode.next = NULL;
  node3.next = &newNode;

  // newNode(3, &node3);

  printNodes(&node1);

}