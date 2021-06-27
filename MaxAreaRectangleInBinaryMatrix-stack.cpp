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

int MAH(int a[], int size) {
    vector<int>v2 = nextsmallerright(a,size);
    vector<int>v3 = nextsmallerleft(a,size);
    int b[size];
    for(int i =0;i<size;i++) {
        b[i] = v2[i]-v3[i]-1;
    }
    int ans = INT_MIN;
    for(int i=0;i<size;i++) {
        ans = max(a[i]*b[i],ans);
    }
    return ans;
}

int main() {
    int n=4,m=4;
    int a[n][m] = {{0,1,1,0},{1,1,1,1},{1,1,1,1},{1,1,0,0}};
    int temp[m];
    for(int j=0;j<m;j++) {
        temp[j] = a[0][j];
    }
    int maxm = MAH(temp,m);
    for(int i=1;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(a[i][j] == 0) {
                temp[j] = 0;
            } else {
                temp[j] = temp[j]+a[i][j];
            }
        }
        maxm = max(maxm, MAH(temp,m));
    }
    cout<<maxm<<endl;
    
}