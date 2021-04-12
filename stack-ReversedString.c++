#include <iostream>
#include <string.h>
#include <stack>
using namespace std;
void Reverse(char s[], int n) {
  stack <char> s1;
  for(int i=0;i<n;i++) {
    s1.push(s[i]);
  }
  for(int i=0;i<n;i++)
  {
    s[i] = s1.top();
    s1.pop(); 
  }
}
int main() {
  char s[51];
  cout<<"enter any string: ";
  cin>>s;
  Reverse(s, strlen(s));
  cout<<"Reversed String is : ";
  cout<<s<<endl;
}