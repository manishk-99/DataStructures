#include <stdio.h>
#include <stdlib.h>
struct Node {
  int data;
  struct Node* next;
};
struct Node* top;
void Push(int data) {
  struct Node* temp = (struct Node*)malloc(sizeof(struct Node*));
  temp->data = data;
  temp->next = top;
  top = temp;
}

void pop () {
  struct Node* temp = top;
  top = top->next;
  free(temp);
}
void print ()  {
  struct Node* temp = top;
  while(temp!= NULL) {
    printf("%d ", temp->data);
    temp = temp->next;
  }
  printf("\n");
}
int main(void) {
  top = NULL;
  Push(2);
  Push(3);
  Push(4);
  Push(5);
  Push(6);
  Push(7);
  Push(8);
  print();
  pop();
  print();
  pop();
  print();
  pop();
  print();
  pop();
  print();
  pop();
  print();
  pop();
  print();
  return 0;
}