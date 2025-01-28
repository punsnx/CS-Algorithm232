#include <iostream>
using namespace std;



int count_negative(int A[],int l,int r){
    if(l < r){
        int m = (l+r)/2;
        int lc = count_negative(A,l,m);
        int rc = count_negative(A,m+1,r);
        return lc + rc;
    }
    return A[l] < 0;
}


int count_one(int A[],int l,int r){
    if(l>r)return 0;
    if(l==r)return A[l];
    int m = (l+r)/2;
    if(A[m] == 1){
        return (r-m+1) + count_one(A,l,m-1);
    }else{
        return count_one(A,m+1,r);
    }
}


int count_larger_equal(int A[],int x,int l,int r){
    if(l>r)return 0;
    if(l==r)return (x <= A[l]);
    int m = (l+r)/2;
    if(x <= A[m]){
        return (r-m+1) + count_larger_equal(A,x,l,m-1);
    }else{
        return count_larger_equal(A,x,m+1,r);
    }
}

int find_k_smallest(int A[],int n,int k){
    for(int i = 0;i<n;++i){
        int x = A[i];
        int c = count_larger_equal(A,x,0,n-1);
        if(c==k)return A[i];
    }
    return -1;
}

int main() {
    int arr[4] = {2,-5,-3,-1};
    int a[8] = {0,0,1,1,1,1,1,1};
    int b[10] = {1,2,3,4,5,6,7,8,9,10};
    cout << count_negative(arr,0,3) << endl;
    cout << count_one(a,0,7) << endl;
    cout << find_k_smallest(b,10,1) << endl;
    return 0;
}