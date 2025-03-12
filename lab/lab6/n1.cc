#include <iostream>
#include <vector>
using namespace std;

int r, c, Q;

bool queenWalk(vector<vector<bool> > &board, int si, int sj) {
    // up
    for (int i = si - 1; i >= 0; --i)
        if (board[i][sj]) return 0;
    // down
    for (int i = si + 1; i < r; ++i)
        if (board[i][sj]) return 0;
    // right
    for (int j = sj + 1; j < c; ++j)
        if (board[si][j]) return 0;
    // left
    for (int j = sj - 1; j >= 0; --j)
        if (board[si][j]) return 0;

    // diagonal top-left
    for (int i = si - 1, j = sj - 1; i >= 0 && j >= 0; --i, --j)
        if (board[i][j]) return 0;
    // diagonal bottom-right
    for (int i = si + 1, j = sj + 1; i < r && j < c; ++i, ++j)
        if (board[i][j]) return 0;
    // diagonal top-right
    for (int i = si - 1, j = sj + 1; i >= 0 && j < c; --i, ++j)
        if (board[i][j]) return 0;
    // diagonal bottom-left
    for (int i = si + 1, j = sj - 1; i < r && j >= 0; ++i, --j)
        if (board[i][j]) return 0;

    return 1;
}

int calculate(vector<vector<bool> > &board, int q, int row) {
    if (q == Q) return 1; // All queens placed successfully
    if (row >= r) return 0; // No more rows left

    int ways = 0;
    for (int j = 0; j < c; ++j) {
        if (!board[row][j] && queenWalk(board, row, j)) {
            board[row][j] = 1;
            ways += calculate(board, q + 1, row + 1);
            board[row][j] = 0;
        }
    }
    return ways;
}

int main() {
    int R, B; // Unused for n-Queens
    cin >> r >> c;
    cin >> Q >> R >> B;

    vector<vector<bool> > board(r, vector<bool>(c, 0));

    cout << calculate(board, 0, 0) << endl;
    return 0;
}