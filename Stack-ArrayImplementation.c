#include <stdio.h>
#include <stdlib.h>
#define ull unsigned long long
#define MAX 101
ull A[MAX];
ull top = -1;
void Push(int x) {
  if(top == MAX-1) {
    printf("Error: Overflow");
    return;
  }
  top++;
  A[top]=x;
}

void pop() {
  if(top == -1) {
    printf("Stack is empty");
    return;
  }
  top--;
}

void Top() {
  printf("Top is: %llu ",A[top]);
  printf("\n");
}
int isEmpty() {
  if(top == -1) {
    return 0;
  }
  return 1;
}

void print() {
  for(ull i=0;i<=top;i++)
  {
    printf("%llu ",A[i]);
  }
  printf("\n");
}
int main(void) {
  Push(2);
  Push(3);
  Push(4);
  Push(5);
  Push(6);
  Push(7);
  print();
  pop();
  print();
  Top();
  int x = isEmpty();
  if(x==0) {
    printf("Yes it is empty");
  }
  printf("No it is NotEmpty");
  return 0;
}