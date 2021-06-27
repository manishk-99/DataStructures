#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
    int n = 7;
    int a[n] = {100,80,60,70,60,75,85};
    vector<int>v;
    stack<pair<int,int>>s;
    for(int i=0;i<n;i++) {
        if(s.size()==0) {
            v.push_back(-1);
        } else if(s.size()>0 && s.top().first>a[i]) {
            v.push_back(s.top().second);
        } else if(s.size()>0 && s.top().first<=a[i]) {
            while(s.size()>0 && s.top().first<=a[i]) {
                s.pop();
            }
            if(s.size()==0) {
                v.push_back(-1);
            } else {
                v.push_back(s.top().second);
            }
        }
        s.push({a[i],i});
    }
    for(int i=0;i<n;i++) {
        cout<<i-v[i]<<endl;
    }
}