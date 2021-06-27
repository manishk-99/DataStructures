#include <iostream>
#include<bits/stdc++.h>
using namespace std;

vector<int> nextsmallerright(int a[], int size) {
    vector<int>v1;
    stack<pair<int,int>>s1;
    int pseudoIndex = size;
    for(int i=size-1;i>=0;i--) {
        if(s1.size() == 0) {
            v1.push_back(pseudoIndex);
        }
        else if(s1.size()>0 && s1.top().first<a[i]) {
            v1.push_back(s1.top().second);
        } else if(s1.size()>0 && s1.top().first>=a[i]) {
            while(s1.size()>0 && s1.top().first>=a[i]) {
                s1.pop();
            }
            if(s1.size()==0) {
                v1.push_back(pseudoIndex);
            } else {
                v1.push_back(s1.top().second);
            }
        }
        s1.push({a[i],i});
    }
    reverse(v1.begin(),v1.end());
    return v1;
}

vector<int> nextsmallerleft(int a[], int size) {
    vector<int>v1;
    stack<pair<int,int>>s1;
    int pseudoIndex = -1;
    for(int i=0;i<size;i++) {
        if(s1.size() == 0) {
            v1.push_back(pseudoIndex);
        }
        else if(s1.size()>0 && s1.top().first<a[i]) {
            v1.push_back(s1.top().second);
        } else if(s1.size()>0 && s1.top().first>=a[i]) {
            while(s1.size()>0 && s1.top().first>=a[i]) {
                s1.pop();
            }
            if(s1.size()==0) {
                v1.push_back(pseudoIndex);
            } else {
                v1.push_back(s1.top().second);
            }
        }
        s1.push({a[i],i});
    }
    return v1;
}

int main() {
    int n = 7;
    int a[n] = {6,2,5,4,5,1,6};
    vector<int>v2 = nextsmallerright(a,n);
    vector<int>v3 = nextsmallerleft(a,n);
    
    // for(int i=0;i<n;i++) {
    //     cout<<v2[i]<<" "<<v3[i]<<endl;
    // }
    int b[n];
    for(int i =0;i<n;i++) {
        b[i] = v2[i]-v3[i]-1;
    }
    int ans = INT_MIN;
    for(int i=0;i<n;i++) {
        // cout<<b[i]<<endl;
        ans = max(a[i]*b[i],ans);
    }
    cout<<ans<<endl;
}