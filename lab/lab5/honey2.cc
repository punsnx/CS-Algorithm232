#include <iostream>
#include <vector>
using namespace std;


int findMax(int i1,int i2){
    return (i1 > i2 ? i1 : i2);
}
int findMin(int i1,int i2){
    return (i1 < i2 ? i1 : i2);
}

int kadane1D(vector<int>& arr, int maxSize) {
    int maxSum = arr[0];
    
    for(int i = 0; i < arr.size(); i++) {
        int sum = 0;
        for(int len = 1; len <= maxSize && i + len <= arr.size(); len++) {
            sum += arr[i + len - 1];
            if(sum > maxSum) {
                maxSum = sum;
            }
        }
    }
    return maxSum;
}

int main() {
    int C, R, mana, cost, area;
    cin >> C >> R;
    cin >> mana >> cost;
    
    area = mana/cost;
    area = (area > R*C ? R*C : area);
    
    vector<vector<int> > land(R, vector<int>(C));
    for(int r = 0; r < R; ++r) {
        for(int c = 0; c < C; ++c) {
            cin >> land[r][c];
        }
    }
    
    int maxSum = 0;
    
    for(int startCol = 0; startCol < C; startCol++) {
        for(int startRow = 0; startRow < R; startRow++) {
            for(int width = 1; width <= C - startCol && width * (R - startRow) <= area; width++) {
                vector<int> rowSums(R - startRow, 0);
                
                for(int col = startCol; col < startCol + width; col++) {
                    for(int row = startRow; row < R; row++) {
                        rowSums[row - startRow] += land[row][col];
                    }
                }
                
                int maxHeight = findMin(area/width, R - startRow);
                
                int sum = 0;
                for(int h = 1; h <= maxHeight; h++) {
                    int tempSum = 0;
                    for(int i = 0; i < h; i++) {
                        tempSum += rowSums[i];
                    }
                    sum = findMax(sum, tempSum);
                }
                maxSum = findMax(maxSum, sum);
            }
        }
    }
    
    cout << maxSum << endl;
    return 0;
}