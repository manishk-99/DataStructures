#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
    int a[7] = {1,1,1,3,2,2,4};
    unordered_map<int,int>m;
    for(int i=0;i<7;i++) {
        m[a[i]]++;
    }
    priority_queue<pair<int,int>>max_h;
    for(auto it=m.begin();it!=m.end();it++) {
        max_h.push({it->second,it->first});
    }
    while(max_h.size()>0) {
        int x = max_h.top().first;
        int y = max_h.top().second;
        for(int i=0;i<x;i++) {
            cout<<y<<endl;
        }
        max_h.pop();
    }
}