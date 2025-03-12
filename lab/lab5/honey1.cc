#include <iostream>
#include <vector>
#include <climits>
using namespace std;


int findMax(int i1,int i2){
    return (i1 > i2 ? i1 : i2);
}

int kadane1D(vector<int>& arr, int maxSize) {
    int currSum = 0;
    int maxSum = arr[0];
    int count = 0;
    int tempCount = 0;
    
    for(int i = 0; i < arr.size(); i++) {
        currSum += arr[i];
        tempCount++;
        
        if(currSum > maxSum && tempCount <= maxSize) {
            maxSum = currSum;
            count = tempCount;
        }
        
        if(currSum < 0) {
            currSum = 0;
            tempCount = 0;
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
        vector<int> rowSums(R, 0);  
        
        for(int endCol = startCol; endCol < C; endCol++) {
            int rectWidth = endCol - startCol + 1;
            
            if(rectWidth > area) break;
            
            for(int row = 0; row < R; row++) {
                rowSums[row] += land[row][endCol];
            }
            
            int maxPossibleHeight = area/rectWidth;
            maxPossibleHeight = (maxPossibleHeight > R ? R : maxPossibleHeight);
            
            int currentStripMax = kadane1D(rowSums, maxPossibleHeight);
            maxSum = findMax(maxSum, currentStripMax);
        }
    }
    
    cout << maxSum << endl;
    return 0;
}