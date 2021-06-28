#include <iostream>
#include<bits/stdc++.h>
using namespace std;

stack<int>s,ss;


void push(int a) {
    s.push(a);
    if(ss.size()==0 || ss.top()>=a) {
        ss.push(a);
    }
    return;
}

int pop() {
    if(s.size()==0) {
        return -1;
    }
    int ans = s.top();
    s.pop();
    if(ans == ss.top()) {
        ss.pop();
    } 
    return ans;
}

int getMin() {
    if(ss.size()==0) {
        return -1;
    } 
    return ss.top();
}

int main() {
    push(18);
    push(19);
    push(29);
    push(15);
    cout<<getMin()<<endl;
    cout<<pop()<<endl;
    cout<<getMin()<<endl;
    
}
