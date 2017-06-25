#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
  int data;
  struct Node *next;
} node;

node * newNode(node *lastNode);
void printNodes(node *firstNode);
node * findNode(node *firstNode);
void deleteNode(node *selectedNode, node *firstNode);
void updateNode(node *selectedNode, node *firstNode);

void main() {

  node *firstNode = NULL;
  node *lastNode = NULL;
  node *selectedNode;

  char input[16];
  char command[16];

  while(1) {
    printf("Command: ");
    fgets(input, 15, stdin);
    sscanf(input, "%s", command);
    if (strncmp(command, "quit", 4) == 0 || strncmp(command, "exit", 4) == 0) {
      break;
    } else if (strncmp(command, "add", 3) == 0) {
      if (firstNode == NULL) {
        firstNode = newNode(lastNode);
        lastNode = firstNode;
      } else {
        lastNode = newNode(lastNode);
      }
    } else if (strncmp(command, "print", 5) == 0) {
      printf("List of data:\n");
      printNodes(firstNode);
    } else if (strncmp(command, "delete", 6) == 0) {
      selectedNode = findNode(firstNode);
      if (selectedNode == firstNode) {
        firstNode = (*selectedNode).next;
      }
      deleteNode(selectedNode, firstNode);
    } else if (strncmp(command, "update", 6) == 0) {
      selectedNode = findNode(firstNode);
      updateNode(selectedNode, firstNode);
    }
  }
}

node * newNode(node *lastNode) {

  printf("Data: ");
  char input[16];
  fgets(input, 15, stdin);

  node *newNode = malloc(sizeof(node));
  sscanf(input, "%d", &((*newNode).data));
  (*newNode).next = NULL;
  if (lastNode != NULL) {
    (*lastNode).next = newNode;
  }
  return newNode;
}

void printNodes(node *firstNode) {

  int counter = 0;
  node *currentNode = firstNode;

  while(currentNode != NULL){
    counter++;
    printf("%d - %d\n", counter, (*currentNode).data);
    currentNode = (*currentNode).next;
  }
}

node * findNode(node *firstNode) {

  printNodes(firstNode);

  char input[16];
  int selectedIndex;
  int counter = 1;

  printf("Select by index: ");
  fgets(input, 15, stdin);
  sscanf(input, "%d", &selectedIndex);

  node *currentNode = firstNode;

  while(currentNode != NULL) {
    if (counter == selectedIndex) {
      return currentNode;
    }
    currentNode = (*currentNode).next;
    counter++;
  }
}

void deleteNode(node *selectedNode, node *firstNode) {

  node *currentNode = firstNode;

  while (currentNode != NULL) {
    if ((*currentNode).next == selectedNode ) {
      (*currentNode).next = (*selectedNode).next;
    }
    currentNode = (*currentNode).next;
  }
}

void updateNode(node *selectedNode, node *firstNode) {
  
  char input[16];
  int newData;

  printf("New data: ");
  fgets(input, 15, stdin);
  sscanf(input, "%d", &newData);

  node *currentNode = firstNode;

  while (currentNode != NULL) {
    if (currentNode == selectedNode ) {
      (*currentNode).data = newData;
    }
    currentNode = (*currentNode).next;
  }  
}