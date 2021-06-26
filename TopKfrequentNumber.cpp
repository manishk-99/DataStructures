#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
    int a[11] = {5,8,8,7,7,4,4,3,2,6,8};
    int k = 3;
    unordered_map<int, int>m;
    for(int i=0;i<11;i++) {
        m[a[i]]++;
    }
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>min_h;
    for(auto it = m.begin(); it!= m.end();it++) {
        min_h.push({it->second, it->first});
        if(min_h.size()>k) {
            min_h.pop();
        }
    }
    while(min_h.size()>0) {
        cout<<min_h.top().second<<endl;
        min_h.pop();
    }
}