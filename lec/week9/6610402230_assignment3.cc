#include <iostream>
using namespace std;

void SSP(int *arr,int n,int sum){
    bool t[n][sum+1];
    cout << "j      ";
    for(int j = 0;j<sum+1;j++){
        cout << j << " ";
    }
    cout << endl;
    for(int i = 0;i<n;i++){
        cout << "a" << i << " = " << arr[i] << " ";
        for(int j = 0;j<sum+1;j++){
            if(i == 0){
                if(j == 0 || arr[i] == j)t[i][j] = true;
                else t[i][j] = false;
            }else{
                if(arr[i] == j || t[i-1][j] || t[i-1][j - arr[i]])t[i][j] = true;
                else t[i][j] = false;
            }
            cout << t[i][j] << " ";
        }
        cout << endl;
    }


}

int main(){
    int arr[] = {2,3,5,6};
    SSP(arr,4,16);

    return 0;
}