#include<stdio.h>
#include<stdlib.h>
struct Node {
  int data;
  struct Node* next;
};
struct Node* head;
void insert (int data) {
  struct Node* temp = (struct Node*)malloc(sizeof(struct Node*));
  temp->data = data;
  temp->next =  NULL;
  if(head == NULL)
  {
    head = temp;
    return;
  }
  struct Node* temp2 = head;
  while(temp2->next!=NULL) {
    temp2 = temp2->next;
  }
  temp2->next = temp;
}
void Reverse () {
  struct Node* current,*next,*prev;
  current = head;
  prev = NULL;
  while(current != NULL) {
    next = current->next;
    current->next = prev;
    prev = current;
    current = next;
  }
  head = prev;
}
void print () {
  struct Node* temp = head;
  while(temp!=NULL) {
    printf("%d ", temp->data);
    temp =  temp->next;
  }
  printf("\n");
}

int main(void) {
  head = NULL;
   insert(2);
  insert(3);
  insert(4);
  insert(5);
  insert(6);
  print();
  Reverse();
  print();
  
  return 0;
}