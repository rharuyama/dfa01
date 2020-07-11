
#include <stdio.h>
#include <stdlib.h> // to include malloc

typedef struct Node Node;
typedef Node* Stack;

struct Node{
  int data;
  Node* prev;
};

void Push(Node** ptop, int newData);
void Pop(Node** ptop);
void Display(Node* top);
void Init(Node** ptop);

void Push(Node** ptop, int newData){ // replace top with *ptop
  Node* newNode = malloc(sizeof(Node));
  newNode->data = newData;
  newNode->prev = *ptop;
  *ptop = newNode; // change value of top
}

void Pop(Node** ptop){
  *ptop = (*ptop)->prev;
}

void Display(Node* top){
  Node* cur = top;
  printf("top ->");
  while(cur){
    printf(" %d", cur->data);
    cur = cur->prev;
  }
  printf("\n");
}

