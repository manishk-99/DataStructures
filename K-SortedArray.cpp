#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
    int a[7] = {6, 5, 3, 2, 8, 10, 9};
    int k = 3;
    priority_queue<int, vector<int>, greater<int>>min_h;
    for(int i=0;i<7;i++) {
        min_h.push(a[i]);
        if(min_h.size()>k) {
            cout<<min_h.top()<<endl;
            min_h.pop();
        }
    }
    while(min_h.size()!=0) {
        cout<<min_h.top()<<endl;
        min_h.pop();
    }
}