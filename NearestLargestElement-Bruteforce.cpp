#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
    int n = 7;
    int a[n] = {1,3,0,0,1,2,4};
    vector<int>v;
    for(int i=0;i<n;i++) {
        if(i+1 == n) {
            cout<<-1<<endl;
            break;
        }
        for(int j=i+1;j<n;j++) {
            if(a[j]>a[i]) {
                v.push_back(a[j]);
            }
        }
        if(v.empty()) {
            v.push_back(-1);
        }
        cout<<v[0]<<endl;
        v.clear();
    }
}