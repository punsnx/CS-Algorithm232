#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
#define EPSILON 1e-6

double func(short &n,short cf[],double irr){
    double sum = 0;
    for(short i = 0;i<=n;i++){
        sum += cf[i]/pow((1+irr),i);
    }
    return sum;
    
}


int main(){
    short n;
    while(cin >> n && n != 0){
        short cf[n+1];
        for(short i = 0;i<=n;i++){
            cin >> cf[i];
        }

        double a = -1 + EPSILON;
        double b = 1;
        double c = a;
        //with Bisection method and Intermediate Value Theorem
        while((b-a) >= EPSILON){
            c = (a+b)/2;
            if(func(n,cf,c) < EPSILON)break;
            else if (func(n,cf,a) * func(n,cf,c) < 0){
                b = c;
            }else{
                a = c;
            }

        }
        cout << fixed << setprecision(2) << c << endl;
        cout << func(n,cf,c) << endl;
    }
    



    return 0;
}