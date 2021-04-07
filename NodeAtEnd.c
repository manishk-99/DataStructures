#include<stdio.h>
#include<stdlib.h>
struct Node {
  int data;
  struct Node* next;
};
struct Node* head;
void insert (int data) {
  struct Node* temp1 = (struct Node*)malloc(sizeof(struct Node*)) ;
  temp1->data = data;
  temp1->next = NULL;
  if(head == NULL) {
    head = temp1;
    return;
  }
  struct Node* temp2 = head;
  while(temp2->next != NULL) {
    temp2 = temp2->next;
  }
  temp2->next = temp1;
}
void print() {
  struct Node* temp = head;
  while(temp!= NULL) {
    printf("%d ", temp->data);
    temp =  temp->next;
  }
}
int main(void) {
  head = NULL;
  insert(2);
  insert(3);
  insert(4);
  insert(5);
  insert(6);
  print();
  return 0;
}

