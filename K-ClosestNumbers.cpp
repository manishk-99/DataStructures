#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
    int a[5] = {5, 6, 7, 8, 9};
    int k = 3;
    int x = 7;
    priority_queue<pair<int,int>>max_h;
    for(int i=0;i<5;i++) {
        max_h.push({abs(a[i]-x), a[i]});
        if(max_h.size()>k) {
            max_h.pop();
        }
    }
    while(max_h.size()>0) {
        cout<<max_h.top().second<<endl;
        max_h.pop();
    }
}