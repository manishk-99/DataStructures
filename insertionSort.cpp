#include<bits/stdc++.h>
using namespace std;

void insertionSort(int A[], int N) {
    for(int i=1;i<N;i++) {
        int value = A[i];
        int hole =  i;
        while(hole>0 && A[hole-1] > value) {
            A[hole] = A[hole-1];
            hole--;
        }
        A[hole] = value;
    }
}

int main() {
    int N = 6;
    int A[N] = {7,2,4,1,5,3};
    insertionSort(A,N);
    for(int i=0;i<6;i++) {
        cout<<A[i]<<endl;
    }
}