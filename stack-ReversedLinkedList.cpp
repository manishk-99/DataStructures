#include <stdio.h>
#include <stdlib.h>
#include <stack>
#include <string.h>
using namespace std;
struct Node {
  int data;
  struct Node* next;
};
struct Node* head2;
void insert(int x) {
  struct Node* temp = (struct Node*) malloc(sizeof(struct Node));
  temp->data = x;
  temp->next = head2;
  head2 = temp;
}
void Reverse() {
  stack<struct Node*>s;
  struct Node* temp = head2;
  while(temp != NULL) {
    s.push(temp);
    temp = temp->next;
  }
  struct Node* temp2 = s.top();
  head2 = temp2;
  s.pop();
  while(!s.empty()) {
    temp2->next = s.top();
    s.pop();
    temp2 = temp2->next;
  }
  temp2->next = NULL;
}
void print() {
  struct Node* temp3 = head2;
  while(temp3!= NULL) {
    printf("%d ", temp3->data - '0');
    temp3 = temp3->next;
  }
  printf("\n");
}
int main(void) {
  head2 = NULL;
  char c[20];
  printf("Enter any LinkedList: ");
  scanf("%s",c);
  for(int i=0;i<strlen(c);i++) {
    insert(c[i]);
  }
  printf("The provided LinkedList is: ");
  print();
  Reverse();
  printf("The Reversed LinkedList is: ");
  print();
  return 0;
}