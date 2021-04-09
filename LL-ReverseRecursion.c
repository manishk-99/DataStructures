#include <stdio.h>
#include <stdlib.h>
struct Node {
  int data;
  struct Node* next;
};
struct Node* head;
void print (struct Node* head) {
  if(head == NULL) {
    return;
  }
  printf("%d ", head->data);
  print(head->next);
}
struct Node* insert(struct Node* head, int data) {
  struct Node* temp = (struct Node*)malloc(sizeof(struct Node*));
  temp->data = data;
  temp->next = NULL;
  if(head == NULL) {
    head = temp;
  }
  else {
    struct Node* temp1 = head;
    while(temp1->next !=NULL) {
      temp1= temp1->next;
    }
    temp1->next = temp;
  }
  return head;
}
void Reverse (struct Node*x) {
  if(x->next == NULL) {
    head =x;
    return;
  }
  Reverse(x->next);
  struct Node* temp =x->next;
  temp->next =x;
  x->next = NULL;
}
int main(void) {
  head = NULL;
  struct Node* p = NULL;
  p = insert(p,2);
  p = insert(p,3);
  p = insert(p,4);
  p = insert(p,5);
  p = insert(p,6);
  p = insert(p,7);
  print(p);
  printf("\n");
  //  print(p);
  Reverse(p);
  print(head);
  return 0;
}