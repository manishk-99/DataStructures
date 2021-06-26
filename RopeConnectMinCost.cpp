#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
    int a[5] = {1,2,3,4,5};
    priority_queue<int,vector<int>, greater<int>>min_h;
    for(int i=0;i<5;i++) {
        min_h.push(a[i]);
    }
    int totsum=0,tempsum=0;
    // int cost = 0;
    while(min_h.size()!=1) {
        // int first = min_h.top();
        // min_h.pop();
        // int second = min_h.top();
        // min_h.pop();
        // cost+= first+second;
        // min_h.push(first+second);
        for(int i=0;i<2;i++) {
            tempsum+= min_h.top();
            min_h.pop();
        }
        min_h.push(tempsum);
        totsum+=tempsum;
        tempsum = 0;
    }
    cout<<totsum<<endl;
    // cout<<cost<<endl;
}