#include <iostream>
#include <stack>
using namespace std;

void LiS(int *arr,int n){//longest increasing subsequence
    if(n <= 0)return;

    int length[n];
    int sIdx[n];

    sIdx[0] = -1;
    for(int i = 0;i<n;++i)
        length[i]=1;
    
    int globalMax = 1;
    int maxIndex = 0;
    for(int i = 1;i<n;++i){
        int tmp = length[i];
        int maxLength = tmp;
        for(int j = 0;j<i;++j){
            if(arr[j] < arr[i] && length[j] + tmp > maxLength){
                maxLength = length[j] + tmp;
                sIdx[i] = j;
            }
        }
        length[i] = maxLength;
        if(maxLength > globalMax){
            globalMax = maxLength;
            maxIndex = i;
        }
    }

    if(globalMax == 1)cout << arr[n-1];
    else{
        int i = maxIndex;
        stack<int> s;
        while(i>=0){
            s.push(arr[i]);
            i = sIdx[i];
        }
        while(!s.empty()){
            cout << s.top() << " ";
            s.pop();
        }
        cout << endl;

    }



}


int main(){
    int arr[12] = {0,4,12,2,10,6,9,13,3,11,7,15};
    LiS(arr,12);

    return 0;
}