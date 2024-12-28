#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
using namespace std;

double gcd(double a, double b){
    if (a < 1e-10){//floating point zero not truely zero
        return b;
    }
    return gcd(fmod(b,a), a);
}

double lcm(double a, double b){
    return (a * b) / gcd(a, b);
}

double multipleGcd(vector<double> &arr){
    double res = arr[0];
    for(int i=1; i < arr.size();i++){
        res = gcd(arr[i],res);
    }
    return res;
}

double multipleLcm(vector<double> &arr){
    double res = arr[0];
    for(int i=1; i < arr.size() ;i++){
        res = lcm(arr[i],res);
    }
    return res;
}


int main(){

    vector<double> arr;
    double tmp;
    while(cin >> tmp){
        arr.push_back(tmp);
    }

    cout << "(" << fixed << setprecision(4) << multipleGcd(arr) <<", "
        << fixed << setprecision(4) << multipleLcm(arr) << ")" << endl;


    return 0;
}