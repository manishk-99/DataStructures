#include <stdlib.h>
#include <stdio.h>
struct Node {
  int data;
  struct Node* next;
};
struct Node* head;
void insert(x) {
  struct Node* temp = (struct Node*) malloc(sizeof(struct Node));
  temp->data = x;
  temp->next = head;
  head = temp;
}
void print () {
  struct Node* temp2 = head;
  printf("List is:");
  while(temp2!= NULL){
    printf(" %d", temp2->data);
    temp2 = temp2->next;
  }
  printf("\n");
}
int main(void) {
  head = NULL;
  int n,x;
  printf("How many numbers?\n");
  scanf("%d" ,&n);
  for(int i=0;i<n;i++)
  {
    printf("Enter any number: \n");
    scanf("%d",&x);
    insert(x);
    print();
  }
}