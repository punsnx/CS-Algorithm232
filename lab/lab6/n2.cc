// pass iter 1
#include <iostream>
#include <vector>
using namespace std;

int r, c, Q, R, B;

bool queenWalk(vector<vector<bool> > &board, int si, int sj) {
    // Check column
    for (int i = 0; i < r; ++i)
        if (i != si && board[i][sj]) return false;
    // Check row
    for (int j = 0; j < c; ++j)
        if (j != sj && board[si][j]) return false;
    for (int i = si - 1, j = sj - 1; i >= 0 && j >= 0; --i, --j)
        if (board[i][j]) return false;
    // Check diagonal bottom-right (\)
    for (int i = si + 1, j = sj + 1; i < r && j < c; ++i, ++j)
        if (board[i][j]) return false;
    // Check diagonal top-right (/)
    for (int i = si - 1, j = sj + 1; i >= 0 && j < c; --i, ++j)
        if (board[i][j]) return false;
    // Check diagonal bottom-left (/)
    for (int i = si + 1, j = sj - 1; i < r && j >= 0; ++i, --j)
        if (board[i][j]) return false;

    return true;
}

int calculate(vector<vector<bool> > &board, int q, int start) {
    if (q == Q) return 1; 

    int ways = 0;
    for (int index = start; index < r * c; ++index) {
        int i = index / c, j = index % c;

        if (!board[i][j] && queenWalk(board, i, j)) {
            board[i][j] = 1;
            ways += calculate(board, q + 1, index + 1); 
            board[i][j] = 0;
        }
    }
    return ways;
}

int main() {
    cin >> r >> c;
    cin >> Q >> R >> B;

    vector<vector<bool> > board(r, vector<bool>(c, 0));

    cout << calculate(board, 0, 0) << endl;
    return 0;
}