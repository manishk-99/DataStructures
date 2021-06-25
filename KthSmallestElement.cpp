#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
    int a[6]={7, 10, 4, 3, 20, 15};
    int k = 3;
    priority_queue<int>max_h;
    for(int i=0;i<6;i++) {
        max_h.push(a[i]);
        if(max_h.size()>k) {
            max_h.pop();
        }
    }
    cout<<max_h.top()<<endl;
}