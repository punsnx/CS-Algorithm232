#include <iostream>
#include <vector>
#include <sstream>
#include <string>
using namespace std;


void merge(vector<int> &arr,int left,int mid,int right,bool ascending){
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
        if(ascending ? (L[i] <= R[j]):(L[i] >= R[j])) arr[k] = L[i++];
        else arr[k] = R[j++];
        ++k;
    }
    //There is case that one array exist the limit but remain another one
    while(i < n1) arr[k++] = L[i++];
    while(j < n2) arr[k++] = R[j++];


}

void mergeSort(vector<int> &arr,int left,int right,bool ascending){
    if(left < right){
        int mid = (left + right)/2;
        mergeSort(arr,left,mid,ascending);
        mergeSort(arr,mid+1,right,ascending);
        merge(arr,left,mid,right,ascending);
    }
}

int binarySearchDC(vector<int> &arr,int query,int &max,int left,int right){
    if(left < right){
        int mid = (left + right)/2;
        if(arr[mid] >= query && mid > max)max = mid;
        binarySearchDC(arr,query,max,left,mid-1);
        binarySearchDC(arr,query,max,mid+1,right);
    }else{
        if(arr[left] >= query && left > max){
            max = left;
        }else {
            return max;
        }
    }

}

void eatCookie(vector<int> &X,int start,vector<int> CR,int maxEatRef){
    for(int i = start;i%X.size() != i ;++i){
        vector<int> C = CR;
        int maxEat = maxEatRef;
        int max = -1;
        binarySearchDC(C,X[i],max,0,C.size()-1);
        // cout << X[i] << " = ";
        if(max != -1){
            // cout << C[max] << ", ";
            C.erase(C.begin() + max);
            max += 1;
        }
        eatCookie(X,i+1,C,maxEat);

    }
    // cout << endl;

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
    for(int & x : X){
        cout << x << " ";
    }
    cout << endl;
    for(int & c : C){
        cout << c << " ";
    }
    cout << endl;
    int satisfied = 0;
    for(int i = 0;i<X.size();++i){
        cout << X[i] << " = ";
        int max = -1;
        binarySearchDC(C,X[i],max,0,C.size()-1);
        if(max != -1){
            satisfied++;
            cout << C[max] << " ";
            C.erase(C.begin() + max);
        }
        cout << endl;
    }
    cout << satisfied << endl;

    // eatCookie(X,0,C);
    






    return 0;
}