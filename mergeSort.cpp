#include <bits/stdc++.h>
using namespace std;


void merge(int A[], int L[], int l1, int R[], int r1) {
    int i=0,j=0,k=0;
    while(i<l1 && j<r1) {
        if(L[i]<=R[j]) {
            A[k]=L[i];
            i++;
        } else {
            A[k] = R[j];
            j++;
        }
        k++;
    }
    while(i<l1) {
        A[k] = L[i];
        k++;
        i++;
    }
    while(j<r1) {
        A[k] = R[j];
        k++;
        j++;
    }
}

void mergeSort(int A[], int n) {
    if(n<2) {
        return;
    }
    int mid = n/2;
    int L[mid],R[n-mid];
    for(int i=0;i<mid;i++) {
        L[i] = A[i];
    }
    for(int i=mid;i<n;i++) {
        R[i-mid] = A[i];
    }
    mergeSort(L, mid);
    mergeSort(R, n-mid);
    merge(A,L,mid,R,n-mid);
}

int main() {
    int n = 6;
    int A[6] = {12, 11, 13, 5, 6, 7};
    mergeSort(A, n);
    for(int i=0;i<n;i++) {
        cout<<A[i]<<endl;
    }
}