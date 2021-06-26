#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
    int n=4,k=2;
    int a[n][2] = {{1,3},{-2,2},{5,8},{0,1}};
    priority_queue<pair<int,pair<int,int>>>max_h;
    for(int i=0;i<n;i++) {
        max_h.push({a[i][0]*a[i][0] + a[i][1]*a[i][1],{a[i][0],a[i][1]}});
        if(max_h.size()>k) {
            max_h.pop();
        }
    }
    while(max_h.size()>0) {
        pair<int,int>p = max_h.top().second;
        cout<<p.first<<" "<<p.second<<endl;
        max_h.pop();
    }
}