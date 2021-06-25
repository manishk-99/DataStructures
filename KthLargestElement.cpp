#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
    int a[6] = {7, 10, 4, 3, 20, 15};
    int k = 3;
    priority_queue<int, vector<int>, greater<int>>min_h;
    for(int i=0;i<6;i++) {
        min_h.push(a[i]);
        if(min_h.size()>k) {
            min_h.pop();
        }
    }
    cout<<min_h.top()<<endl;
}