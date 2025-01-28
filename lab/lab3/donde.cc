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
        // cout << X[i] << " = ";
        int left = 0,right = C.size()-1,pos = -1;
        while(left<=right){
            int mid = (left+right)/2;
            if(C[mid]>=X[i]){
                pos = mid;
                right = mid - 1;
            }else{
                left = mid + 1;
            }
        }
        if (pos != -1) {
            satisfied++;
            // cout << C[pos] << " ";
            C.erase(C.begin() + pos);
        }
        // cout << endl;
    }
    for(int i = 0;i<X.size();++i){
        // cout << X[i] << " = ";
        int j=0;
        while(j<C.size() && C[j] < X[i])++j;
        if(j<C.size()){
            satisfied++;
            // cout << C[j] << " ";
            C.erase(C.begin() + j);
        }
        // cout << endl;
    }
    cout << satisfied << endl;
    






    return 0;
}