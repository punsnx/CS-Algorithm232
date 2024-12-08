//correct tier3
#include <iostream>
using namespace std;
long countMerge(int *arr,int l,int m,int r){
    int n1 = m - l + 1; 
    int n2 = r - m;

    int left[n1],right[n2];
    for(int i = 0;i<n1;i++){
        left[i] = arr[l+i];
    }
    for(int j = 0;j<n2;j++){
        right[j] = arr[m+1+j];
    }

    long res = 0;
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {

        if (left[i] > right[j]) 
            arr[k++] = left[i++];
    
        else {
            arr[k++] = right[j++];
            res += (n1 - i);
        }
    }

    while (i < n1)
        arr[k++] = left[i++];
    while (j < n2)
        arr[k++] = right[j++];

    return res;
}


long countInv(int *arr,int l, int r){
    long res = 0;
    if(l<r){
        int m = (r+l)/2;

        res += countInv(arr,l,m);
        res += countInv(arr,m+1,r);

        res += countMerge(arr,l,m,r);

    }
    return res;
}

long inversionCount(int *arr,int n){
    return countInv(arr,0,n-1);
}

int main(){
    int n;
    while(cin >> n){
        int heightList[n];
        for(int i = 0;i<n;i++){
            cin >> heightList[i];
        }

        cout << inversionCount(heightList,n) << endl;

    }


    return 0;
}