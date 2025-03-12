//pass tier 1-2-3
#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1e6;

int solve(int n, int k) {
    //try to solve with stars and bars problem C(n+k-1, k-1)
    int N = n + k - 1;  //stars + bars
    int R = k - 1;      //bars
    
    vector<vector<int> > C(N + 1, vector<int>(R+1, 0));
    
    //C(n,0) = 1
    for(int i = 0; i <= N; i++) {
        C[i][0] = 1;
    }
    
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= R; j++) {
            C[i][j] = (C[i-1][j] + C[i-1][j-1]) % MOD;
        }
    }

    // for(vector<int> &r : C){
    //     for(int &c : r){
    //         cout << c << " ";
    //     }
    //     cout << endl;
    // }
    
    return C[N][R];
}

int main() {
    int n, k;
    
    while(true) {
        cin >> n >> k;
        if(n == 0 && k == 0) break;
        
        cout << solve(n, k) << "\n";
    }
    
    return 0;
}