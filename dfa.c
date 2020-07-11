
#include <stdio.h>
#include <stdlib.h> /* to include malloc */ 
#include "stack.c"

void in_s1(Node** pstack);
void in_s2(Node** pstack);
  
Stack stack;
int accepted = 2;

int main(){
  Push(&stack, 1);
  Push(&stack, 1);
  Push(&stack, 0);
  Push(&stack, 1);
  Push(&stack, 1);
  Push(&stack, 1);
  Push(&stack, 0);
  Push(&stack, 0);
  Display(stack);

  in_s1(&stack);
  printf("accepted? : %d\n", accepted);
}

void in_s1(Node** pstack){
  printf("in_s1 called : ");
  Display(*pstack);
  if(*pstack== NULL){
    accepted = 1;
  }else if((*pstack)->data == 1){
    Pop(pstack);
    in_s1(pstack);
  }else if((*pstack)->data == 0){
    Pop(pstack);
    in_s2(pstack);
  }else{
    printf("Error -- in_s1");
  }
}

void in_s2(Node** pstack){
  printf("in_s2 called : ");
  Display(*pstack);
  if(*pstack== NULL){
    accepted = 0;
  }else if((*pstack)->data == 1){
    Pop(pstack);
    in_s2(pstack);
  }else if((*pstack)->data == 0){
    Pop(pstack);
    in_s1(pstack);
  }else{
    printf("Error -- in_s2");
  }
}
