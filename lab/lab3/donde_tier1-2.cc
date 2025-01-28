// PASS Tier1-2
#include <iostream>
#include <vector>
#include <sstream>
#include <string>
using namespace std;


void merge(vector<int> &arr,int left,int mid,int right,bool ascending){
    vector<int> temp(right-left+1);
    int i = left,j = mid+1,k = 0;

    while(i <= mid && j <= right){
        if(ascending ? (arr[i] <= arr[j]):(arr[i] >= arr[j])) temp[k] = arr[i++];
        else temp[k] = arr[j++];
        ++k;
    }
    //There is case that one array exist the limit but remain another one
    while(i <= mid) temp[k++] = arr[i++];
    while(j <= right) temp[k++] = arr[j++];

    for(k = 0; k < temp.size(); ++k) {
        arr[left + k] = temp[k];
    }


}

void mergeSort(vector<int> &arr,int left,int right,bool ascending){
    if(left < right){
        int mid = (left + right)/2;
        mergeSort(arr,left,mid,ascending);
        mergeSort(arr,mid+1,right,ascending);
        merge(arr,left,mid,right,ascending);
    }
}

void binarySearchDC(vector<int> &arr,int query,int &max,int left,int right){
    if(left < right){
        int mid = (left + right)/2;
        if(arr[mid] >= query && mid > max)max = mid;
        binarySearchDC(arr,query,max,left,mid-1);
        binarySearchDC(arr,query,max,mid+1,right);
    }else{
        if(arr.size() && arr[left] >= query && left > max){
            max = left;
        }
    }

}

int main(){
    string input;
    //input X size each person for solve
    vector<int> X;
    getline(cin,input);
    istringstream inputStream(input);
    while(getline(inputStream,input,' ')){
        int tmp = stoi(input);
        X.push_back(tmp);
    }

    //C multi-set of CookieSize
    vector<int> C;
    getline(cin,input);
    inputStream.clear();
    inputStream.str(input);
    while(getline(inputStream,input,' ')){
        int tmp = stoi(input);
        C.push_back(tmp);
    }
    mergeSort(C,0,C.size()-1,true);
    mergeSort(X,0,X.size()-1,false);
    int satisfied = 0;
    for(int i = 0;i<X.size();++i){
        int max = -1;
        // cout << X[i] << " = ";
        binarySearchDC(C,X[i],max,0,C.size()-1);
        if(max != -1){
            satisfied++;
            // cout << C[max] << " ";
            C.erase(C.begin() + max);
        }
        // cout << endl;
    }
    cout << satisfied << endl;
    






    return 0;
}