#include <iostream>
#include<bits/stdc++.h>
using namespace std;

stack<int>s;
int MinElement = 0;

void push(int a) {
    if(s.size()==0) {
        s.push(a);
        MinElement = a;
    }
    else{
        if(a >=MinElement) {
            s.push(a);
        } else if(a<MinElement) {
            s.push(2*a-MinElement);
            MinElement = a;
        }
    }
}

void pop() {
    if(s.size()==0) {
        cout<<"StackIsEmpty"<<endl;
    }
    else {
        if(s.top()>=MinElement) {
            s.pop();
        } else if(s.top()<MinElement) {
            MinElement = 2*MinElement-s.top();
            s.pop();
        }
    }
}

int top() {
    if(s.size()==0) {
        return -1;
    } else {
        if(s.top()>=MinElement) {
            return s.top();
        } else if(s.top()<MinElement) {
            return MinElement;
        }
    }
    return 0;
}

int getMin() {
    if(s.size()==0) {
        return -1;
    } 
    return MinElement;
}

int main() {
    push(5);
    cout<<getMin()<<endl;
    cout<<top()<<endl;
    cout<<endl;
    push(19);
    cout<<getMin()<<endl;
    cout<<top()<<endl;
    cout<<endl;
    push(29);
    cout<<getMin()<<endl;
    cout<<top()<<endl;
    cout<<endl;
    push(15);
    cout<<getMin()<<endl;
    cout<<top()<<endl;
    cout<<endl;
    pop();
    cout<<getMin()<<endl;
    cout<<top()<<endl;
    cout<<endl;
    push(3);
    cout<<getMin()<<endl;
    cout<<top()<<endl;
    cout<<endl;
}

//OUTPUT
// 5
// 5

// 5
// 19

// 5
// 29

// 5
// 15

// 5
// 29

// 3
// 3


