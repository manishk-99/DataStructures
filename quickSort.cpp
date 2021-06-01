#include <bits/stdc++.h>
using namespace std;

int partition(int A[], int start, int end)  {
    int pivot = A[end];
    int pindex = start;
    for(int i=start;i<end;i++) {
        if(A[i]<=pivot) {
            swap(A[i],A[pindex]);
            pindex++;
        }
    }
    swap(A[pindex],A[end]);
    return pindex;
}


void quickSort(int A[], int start, int end) {
    if(start<end) {
        int pindex = partition(A, start, end);
        quickSort(A, start, pindex-1);
        quickSort(A, pindex+1, end);
    }
}


int main() {
    int n = 8;
    int A[n]={7, 6, 5, 4, 3, 2, 1, 0};
    quickSort(A, 0, n-1);
    for(int i=0;i<n;i++)  {
        cout<<A[i]<<endl;
    }
}