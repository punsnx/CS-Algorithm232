#include <iostream>
#include <vector>
using namespace std;

int main(){
    int C,R,mana,cost,area;
    cin >> C >> R;
    cin >> mana >> cost;

    area = mana/cost;
    area = (area > R*C ? R*C : area);

    vector<vector<int> > land(R,vector<int>(C));
    for(int r = 0;r<R;++r){
        for(int c = 0;c<C;++c){
            cin >> land[r][c];
        }
    }

    vector<vector<long> > prefixSum(R+1,vector<long>(C+1,0));
    for(int r = 1;r<=R;++r){
        for(int c = 1;c<=C;++c){
            prefixSum[r][c] = land[r-1][c-1] + 
                             prefixSum[r-1][c] + 
                             prefixSum[r][c-1] - 
                             prefixSum[r-1][c-1];
        }
    }

    int maxSum = 0;
    for(int r = 0;r<R;++r){
        for(int c = 0;c<C;++c){
            for(int a = 1; r+a <= R;++a){
                for(int b = 1; c+b <= C;++b){
                    if(a*b <= area){
                        long rectSum = prefixSum[r+a][c+b] - 
                                     prefixSum[r][c+b] - 
                                     prefixSum[r+a][c] + 
                                     prefixSum[r][c];
                        
                        if(rectSum > maxSum) maxSum = rectSum;
                    }
                }
            }
        }
    }

    cout << maxSum << endl;
    return 0;
}