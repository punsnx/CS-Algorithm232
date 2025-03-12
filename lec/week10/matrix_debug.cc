#include <iostream>
#include <vector>
using namespace std;


int findMin(int a,int b){
    return a < b ? a : b;
}

void matrixChain(int *p,int &n){
    vector<vector<int> > m(n,vector<int>(n,0));
    
    for(int j = 1;j<=n;++j){
        for(int i = j-1;i>0;--i){


            int min = INT_MAX;
            for(int k = i;k<j;++k){
                int temp = m[i-1][k-1] + m[k-1+1][j-1] + (p[i-1]*p[k]*p[j]);
                // cout << m[i-1][k-1] << " + " << m[k-1+1][j-1] << " + " << (p[i-1]*p[k]*p[j]) << " = " << temp << endl;
                min = findMin(min,temp);
            }
            m[i-1][j-1] = min;
            // cout << m[i-1][j-1] << " ";
            for(int a = 0;a<n;++a){
                for(int b = 0;b<n;++b){
                    cout << m[a][b] << " ";
                }
                cout << endl;
            }
            cout << "--------" << endl;

        }
        // cout << endl;
    }

    cout << "Minium number of multiplication is : " << m[0][n-1] << endl;



}
int main(){
    int n = 4;
    int p[] = {5, 4, 6, 2, 7};

    matrixChain(p,n);
}