#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

void merge(vector<int>& arr, int left, int mid, int right, bool ascending) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    
    vector<int> L(n1), R(n2);
    
    for(int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for(int i = 0; i < n2; i++)
        R[i] = arr[mid + 1 + i];
        
    int i = 0, j = 0, k = left;
    
    while(i < n1 && j < n2) {
        if(ascending ? (L[i] <= R[j]) : (L[i] >= R[j])) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    
    while(i < n1) arr[k++] = L[i++];
    
    while(j < n2) arr[k++] = R[j++];
}

void mergeSort(vector<int>& arr, int left, int right, bool ascending) {
    if(left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid, ascending);
        mergeSort(arr, mid + 1, right, ascending);
        merge(arr, left, mid, right, ascending);
    }
}

int main() {
    string input;
    vector<int> X, C;
    
    getline(cin, input);
    istringstream iss(input);
    string num;
    while(getline(iss, num, ' ')) {
        X.push_back(stoi(num));
    }
    
    getline(cin, input);
    iss.clear();
    iss.str(input);
    while(getline(iss, num, ' ')) {
        C.push_back(stoi(num));
    }
    
    mergeSort(X, 0, X.size() - 1, true);
    mergeSort(C, 0, C.size() - 1, true);
    
    int satisfied = 0;
    int cookieIndex = 0;
    
    for(int i = 0; i < X.size() && cookieIndex < C.size(); i++) {
        while(cookieIndex < C.size() && C[cookieIndex] < X[i]) {
            cookieIndex++;
        }
        if(cookieIndex < C.size()) {
            satisfied++;
            cookieIndex++;
        }
    }
    
    cout << satisfied << endl;
    return 0;
}