#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
    int n = 12;
    int a[n] = {0,1,0,2,1,0,1,3,2,1,2,1};
    int maxL[n],maxR[n];
    maxL[0] = a[0];
    // cout<<maxL[0]<<endl;
    maxR[n-1] = a[n-1];
    // cout<<maxR[n-1]<<endl;
    for(int i=1;i<n;i++) {
        maxL[i] = max(maxL[i-1],a[i]);
        // cout<<maxL[i]<<endl;
    }
    for(int j=n-2;j>=0;j--) {
        maxR[j] = max(maxR[j+1],a[j]);
        // cout<<maxR[j]<<endl;
    }
    int water[n],sum=0;
    for(int i=0;i<n;i++) {
        water[i] = min(maxL[i],maxR[i])-a[i];
        // cout<<water[i]<<endl;
        sum+=water[i];
    }
    cout<<sum<<endl;
}

//OUTPUT
// 6