//pass tier-1-2
#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
using namespace std;

double gcd(double a, double b){
    if (a < 1e-10){//floating point zero not truely zero
        return b;
    }
    // return gcd(fmod(b,a), a);
    return gcd(b - floor(b / a) * a, a);
}

double lcm(double a, double b){
    return a / gcd(a, b) * b;
}

double multiGcdDC(vector<double> &arr,int left,int right){
    if(right == left)return arr[left];
    if(right - left == 1)return gcd(arr[left],arr[right]);
    
    int mid = (left + right)/2;
    double leftGcd = multiGcdDC(arr,left,mid);
    double rightGcd = multiGcdDC(arr,mid+1,right);

    return gcd(leftGcd,rightGcd);
}
double multiLcmDC(vector<double> &arr,int left,int right){
    if(right == left)return arr[left];
    if(right - left == 1)return lcm(arr[left],arr[right]);
    
    int mid = (left + right)/2;
    double leftLcm = multiLcmDC(arr,left,mid);
    double rightLcm = multiLcmDC(arr,mid+1,right);

    return lcm(leftLcm,rightLcm);
}

int main(){

    vector<double> arr;
    double tmp;
    while(cin >> tmp){
        arr.push_back(tmp);
    }

    cout << "(" << fixed << setprecision(4) << multiGcdDC(arr,0,arr.size()-1) <<", "
        << fixed << setprecision(4) << multiLcmDC(arr,0,arr.size()-1) << ")" << endl;


    return 0;
}