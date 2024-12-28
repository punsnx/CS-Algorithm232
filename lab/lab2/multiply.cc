// PASS Tier 1-2-3-4
#include <iostream>
#include <string>
using namespace std;


int main(){

    short t;
    cin >> t;
    for(int i = 0;i<t;++i){
        string n1,n2;
        cin >> n1 >> n2;
        // cout << n1 << " " << n2 << endl;
        short product[n1.size() + n2.size()];
        std::fill(product, product + n1.size() + n2.size(), 0);

        for(int i = n1.size()-1; i >= 0;--i){
            for(int j = n2.size()-1; j >= 0;--j){
                int _i = (n1.size()-1 - i);
                int _j =  (n2.size()-1 - j);
                product[_i + _j] += (n1[i] - '0') * (n2[j] - '0');
                if(product[_i + _j] >= 10){
                    product[_i + _j + 1] += product[_i + _j] / 10;
                    product[_i + _j] %= 10;
                }
            }
        }

        short start = n1.size() + n2.size() -1;
        while(start >= 0 && product[start] == 0){
            --start;
        }
        if(start < 0)cout << "0";
        else{
            for(int i = start;i>=0;--i){
                cout << product[i];
            }
        }
        cout << endl;



    }




    return 0;
}