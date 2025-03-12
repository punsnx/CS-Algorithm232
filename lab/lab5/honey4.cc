// pass tier 1-2
#include <iostream>
#include <vector>

using namespace std;


int findMax(int i1,int i2){
    return (i1 > i2 ? i1 : i2);
}
int findMin(int i1,int i2){
    return (i1 < i2 ? i1 : i2);
}


int main() {
    int C, R, mana, cost, area;
    cin >> C >> R;
    cin >> mana >> cost;

    area = mana / cost;
    area = findMin(area, R * C);

    vector<vector<int> > land(R, vector<int>(C));
    vector<vector<int> > prefix(R + 1, vector<int>(C + 1, 0));

    for (int r = 0; r < R; ++r) {
        for (int c = 0; c < C; ++c) {
            cin >> land[r][c];
            prefix[r + 1][c + 1] = land[r][c] + prefix[r][c + 1] + prefix[r + 1][c] - prefix[r][c];
        }
    }

    int maxSum = 0;

    for (int r1 = 0; r1 < R; ++r1) {
        for (int c1 = 0; c1 < C; ++c1) {
            for (int r2 = r1; r2 < R; ++r2) {
                for (int c2 = c1; c2 < C; ++c2) {
                    int rectArea = (r2 - r1 + 1) * (c2 - c1 + 1);
                    if (rectArea > area) break; 

                    int currentSum = prefix[r2 + 1][c2 + 1] - prefix[r1][c2 + 1] - prefix[r2 + 1][c1] + prefix[r1][c1];
                    maxSum = findMax(maxSum, currentSum);
                }
            }
        }
    }

    cout << maxSum << endl;

    return 0;
}