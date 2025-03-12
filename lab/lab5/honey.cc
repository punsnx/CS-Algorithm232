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
    int sum = 0;

    for(int r = 0;r<R;r++){
        for(int c = 0;c<C;c++){

            for(int a = 1; a <= R-r;a++){
                for(int b = 1; b <= C-c;b++){
                    if(a*b <= area){
                        long temp = 0;
                        for(int i = r;i<r+a;i++){
                            for(int j = c;j<c+b;j++){
                                temp += land.at(i).at(j);
                            }
                        }

                        
                        if(temp > sum) sum = temp;
                    }
                }
            }
        }
    }

    cout << sum << endl;






    return 0;
}