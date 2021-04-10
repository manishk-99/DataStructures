#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node* prev;
  struct Node* next;
};

struct Node* head;

struct Node* getNewNode(int x) {
  struct Node* newNode = (struct Node*)malloc(sizeof(struct Node*));
  newNode->data = x;
  newNode->prev = NULL;
  newNode->next = NULL;
  return newNode;
}

void InsertAtHead(int x) {
  struct Node* temp = getNewNode(x);
  if(head == NULL) {
    head = temp;
    return;
  }
  struct Node* temp2 = head;
  temp2->prev = temp;
  temp->next = head;
  head = temp;
}

void print () {
  struct Node* temp = head;
  while(temp!= NULL) {
    printf("%d ", temp->data);
    temp = temp->next;
  }
}

void reversePrint () {
  struct Node* temp = head;
  if(temp == NULL) {
    return;
  }
  while(temp->next!= NULL) {
    temp = temp->next;
  }
  while(temp!=NULL) {
    printf("%d ", temp->data);
    temp = temp->prev;
  }
}
int main(void) {
  head = NULL;
  InsertAtHead(2);
  InsertAtHead(3);
  InsertAtHead(4);
  InsertAtHead(5);
  InsertAtHead(6);
  print();
  printf("\n");
  reversePrint();
  return 0;
}