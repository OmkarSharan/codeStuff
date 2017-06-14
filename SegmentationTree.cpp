#include <bits/stdc++.h>
using namespace std;

void update(int segTree[],int low,int high, int i, int diff, int pos){
    if(i < low || i > high) return;
    segTree[pos]=segTree[pos]+diff;
    if(low != high){
        int mid = (low+high)/2;
        update(segTree, low, mid, i, diff, 2*pos+1);
        update(segTree, mid+1, high, i, diff, 2*pos+2);
    }
}

int rangeSum(int segTree[], int qs, int qe, int low, int high, int pos){
    if(qs <= low && qe >= high) return segTree[pos];
    if(qs > high || qe < low) return 0;
    int mid = (low+high)/2;
    return rangeSum(segTree, qs, qe, mid+1, high, 2*pos+2)+
            rangeSum(segTree, qs, qe, low, mid, 2*pos+1);
}

void cunstructSTree(int arr[], int segTree[], int left, int right, int pos){
    if(left == right){
        segTree[pos]=arr[left];
        return;
    }
    int mid = (left + right)/2;
    cunstructSTree(arr, segTree, left, mid, 2*pos+1);
    cunstructSTree(arr, segTree, mid+1, right, 2*pos+2);
    segTree[pos]=(segTree[2*pos+1]+segTree[2*pos+2]);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int arr[]={1, 3, 5, 7, 9, 11};
    int n=sizeof(arr)/sizeof(arr[0]);
    int segSize = 2*pow(2,(int)ceil(log2(n)))-1;
    int segTree[segSize];
    cunstructSTree(arr, segTree, 0, n-1, 0);
    cout<<rangeSum(segTree,1,4,0,n-1,0);
    int i=1;
    int diff = 10-arr[i];
    update(segTree, 0, n-1, i, diff, 0);
    cout<<rangeSum(segTree,1,4,0,n-1,0);
    return 0;
}
