//6610402230 ศิริสุข ทานธรรม
#include <iostream>
using namespace std;


int findMax(int m1,int m2){
    if(m1 > m2)return m1;
    return m2;
}

void MSS(int *arr,int *sum,int n){//for maximum sub-sequence
    if(n==0){
        sum[n] = arr[n];
    }else{
        MSS(arr,sum,n-1);
        int m1 = sum[n-1] + arr[n];
        int m2 = arr[n];
        sum[n] = findMax(m1,m2);
    }

}


int main(){
    int x[8] = {-2,-3,4,-1,-2,1,5,-3};
    int sum[8];
    int n = 8;
    MSS(x,sum,n-1);
    for(int i = 0; i<n;i++){
        cout << sum[i] << " ";
    }
    cout << endl;



    return 0;
}