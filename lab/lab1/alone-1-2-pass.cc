//correct tier1,2
#include <iostream>
using namespace std;

unsigned long inversionCount(int *arr,int n){
    unsigned long invCount = 0;

    for(int i = 0;i<n;i++){
        for(int j = i+1;j<n;j++){
            if (arr[i] < arr[j]){
                invCount++;
            }
        }
    }
    return invCount;
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