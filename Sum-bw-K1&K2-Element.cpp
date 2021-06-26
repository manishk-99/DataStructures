#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int smallest(int a[],int x) {
    priority_queue<int>max_h;
    for(int i=0;i<6;i++) {
        max_h.push(a[i]);
        if(max_h.size()>x) {
            max_h.pop();
        }
    }
    return max_h.top();
}

int largest(int a[],int x) {
    priority_queue<int,vector<int>,greater<int>>min_h;
    for(int i=0;i<6;i++) {
        min_h.push(a[i]);
        if(min_h.size()>x) {
            min_h.pop();
        }
    }
    return min_h.top();
}

int main() {
    int a[6] = {1,3,5,11,12,15};
    int k1=3,k2=6;
    int first = largest(a,k1);
    int second = smallest(a,k2);
    // cout<<first<<" "<<second<<endl;
    int sum=0;
    for(int i=0;i<6;i++) {
        if(a[i]>first && a[i]<second) {
            sum+=a[i];
        }
    }
    cout<<sum<<endl;
}