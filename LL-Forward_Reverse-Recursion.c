#include <stdio.h>
#include <stdlib.h>
struct Node {
  int data;
  struct Node* next;
};

void print(struct Node* head) {
  if(head==NULL) {
    return;
  }
  printf("%d ", head->data);
  print(head->next);
}
void reversePrint (struct Node* head) {
  if(head == NULL) {
    return;
  }
  reversePrint(head->next);
  printf("%d ", head->data);
}

struct Node* insert(struct Node* head, int data) {
struct Node* temp = (struct Node*)malloc(sizeof(struct Node*));
temp->data = data;
temp->next = NULL;
if(head == NULL) {
  head = temp;
} else {
  struct Node* temp2 = head;
  while(temp2->next != NULL) {
    temp2 = temp2->next;
  }
  temp2->next = temp;
}
  return head;
}
int main(void) {
  struct Node* head = NULL;
  head = insert(head, 2);
  head = insert(head, 3);
  head = insert(head, 4);
  head = insert(head, 5);
  head = insert(head, 6);
  print(head);
  printf("\n");
  reversePrint(head);
  return 0;
}