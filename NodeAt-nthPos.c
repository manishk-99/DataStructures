#include <stdio.h>
#include <stdlib.h>
struct Node {
  int data;
  struct Node* next;
};   
struct Node* head;
void insert(int data, int n) {
  struct Node* temp1 = (struct Node*)malloc(sizeof(struct Node));
  temp1->data = data;
  temp1->next = NULL;
  if(n==1) {
    temp1->next = head;
    head = temp1;
    return; 
  }
  struct Node* temp2 = head;
  for(int i=0;i<n-2;i++)
  {
    temp2 = temp2->next;
  }
  temp1->next = temp2->next;
  temp2->next = temp1;
}
void print() {
  struct Node* temp3 = head;
  while(temp3!=NULL)
  {
    printf(" %d", temp3->data);
    temp3= temp3->next;
  }
}
int main(void) {
  head = NULL;
  insert(2,1);
  insert(3,2);
  insert(4,1);
  insert(5,2);
  insert(6,5);
  print();

}