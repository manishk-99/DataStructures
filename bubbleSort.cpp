#include<bits/stdc++.h>
using namespace std;

void bubbleSort(int A[], int N) {
    for(int k=0;k<N;k++) {
        int flag = 0;
        for(int i=0;i<N;i++) {
            if(A[i]>A[i+1]) {
                swap(A[i],A[i+1]);
                flag = 1;
            }
        }
        if(flag == 0) {
            break;
        }
    }
}

int main() {
    int A[6] = {2,7,4,1,5,3};
    bubbleSort(A,6);
    for(int i=0;i<6;i++) {
        cout<<A[i]<<endl;
    }
}