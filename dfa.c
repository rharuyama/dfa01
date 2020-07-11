
#include <stdio.h>
#include <stdlib.h> // to include malloc

typedef struct Token Token;

struct Token{
  int data;
  Token* next;
};

void Push(Token** ptop, int newData);
void Pop(Token** ptop);
void Display(Token* top);
void in_s1(Token** top);
void in_s2(Token** ptop);
  
Token* top = NULL;
int accepted = 2;

int main(){
  Push(&top, 1);
  Push(&top, 1);
  Push(&top, 0);
  Push(&top, 1);
  Push(&top, 1);
  Push(&top, 1);
  Push(&top, 0);
  Push(&top, 0);
  Display(top);

  in_s1(&top);
  printf("accepted? : %d\n", accepted);
}

void Push(Token** ptop, int newData){ // replace top with *ptop
  Token* newToken = malloc(sizeof(Token));
  newToken->data = newData;
  newToken->next = *ptop;
  *ptop = newToken; // change value of top
}

void Pop(Token** ptop){
  *ptop = (*ptop)->next;
}

void Display(Token* top){
  Token* cur = top;
  printf("top ->");
  while(cur){
    printf(" %d", cur->data);
    cur = cur->next;
  }
  printf("\n");
}

void in_s1(Token** ptop){
  printf("in_s1 called : ");
  Display(*ptop);
  if(*ptop == NULL){
    accepted = 1;
  }else if((*ptop)->data == 1){
    Pop(ptop);
    in_s1(ptop);
  }else if((*ptop)->data == 0){
    Pop(ptop);
    in_s2(ptop);
  }else{
    printf("Error -- in_s1");
  }
}


void in_s2(Token** ptop){
  printf("in_s2 called : ");
  Display(*ptop);
  if(*ptop == NULL){
    accepted = 0;
  }else if((*ptop)->data == 1){
    Pop(ptop);
    in_s2(ptop);
  }else if((*ptop)->data == 0){
    Pop(ptop);
    in_s1(ptop);
  }else{
    printf("Error -- in_s2");
  }
}
