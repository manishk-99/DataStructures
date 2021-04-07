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
void delete (int n) {
  struct Node* temp3 = head;
  if(n==1) {
    head = temp3->next;
    free(temp3);
    return;
  }
  for(int i=0;i<n-2;i++)
  {
    temp3 = temp3->next;
  }
  struct Node* temp4 = temp3->next;
  temp3->next = temp4->next;
  free(temp4);
}
void print() {
  struct Node* temp = head;
  while(temp!= NULL) {
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
  delete(3);
  print();
  delete(1);
  print();
  delete(3);
  print();
  delete(1);
  print();
  delete(1);
  print();
  return 0;
}

