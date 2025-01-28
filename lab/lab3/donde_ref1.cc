#include <iostream>
#include <vector>
#include <sstream>
#include <string>
using namespace std;


void merge(vector<int> &arr,int left,int mid,int right){
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> L(n1);
    vector<int> R(n2);
    for(int i = 0;i<n1;++i){
        L[i] = arr[left + i];
    }
    for(int i = 0;i<n2;++i){
        R[i] = arr[mid + i + 1];
    }

    int i = 0,j = 0,k = left;
    while(i < n1 && j < n2){
        if(L[i] <= R[j]) arr[k] = L[i++];
        else arr[k] = R[j++];
        ++k;
    }
    //There is case that one array exist the limit but remain another one
    while(i < n1) arr[k++] = L[i++];
    while(j < n2) arr[k++] = R[j++];


}

void mergeSort(vector<int> &arr,int left,int right){
    if(left < right){
        int mid = (left + right)/2;
        mergeSort(arr,left,mid);
        mergeSort(arr,mid+1,right);
        merge(arr,left,mid,right);
    }
}

void eatCookie(vector<int> &X,int start){
    for(int i = start;i<X.size();++i){
        cout << X[i] << " ";
        eatCookie(X,i+1);
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
    mergeSort(C,0,C.size()-1);
    for(int & c : C){
        cout << c << " ";
    }
    cout << endl;

    // for(int i = 0;i < X.size();++i){
    //     cout << X[i] << " ";
    //     for(int j = i+1; j%X.size() != i;++j){
    //         cout << X[j%X.size()] << " ";
    //     }
    //     cout << endl;
    // }

    for(int i = 0;i<X.size();++i){
        cout << X[i] << " ";
        eatCookie(X,i+1);
        cout << endl;
    }
    






    return 0;
}