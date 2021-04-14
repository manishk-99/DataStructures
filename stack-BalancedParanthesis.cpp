#include <stdio.h>
#include <stdlib.h>
#include <stack>
#include <string.h>
#include <iostream>
using namespace std;
bool Pair (char openingBracket, char closingBracket) {
  if(openingBracket == '(' && closingBracket == ')') return true;
	else if(openingBracket == '{' && closingBracket == '}') return true;
	else if(openingBracket == '[' && closingBracket == ']') return true;
	return false;
}
bool BalancedParanthesis(string s) {
  stack<char>s1;
 for(int i=0;i<s.length();i++) {
   if(s[i] == '{' || s[i] == '(' || s[i] == '[') {
     s1.push(s[i]);
   }
   else if (s[i] == '}' || s[i] == ')' || s[i] == ']') {
     if(s1.empty() || !Pair(s1.top(),s[i])) {
       return false;
     } else {
       s1.pop();
     }
   }
 }
 return s1.empty() ? true : false;
}

int main(void) {
  string s;
  cout<<"pass the parenthesis expression: "<<endl;
  cin>>s;
  if(BalancedParanthesis(s)) {
    cout<<"Balanced"<<endl;
  } else {
    cout<<"Unbalanced"<<endl;
  }
  return 0;
}