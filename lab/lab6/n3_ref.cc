#include <iostream>
#include <vector>
using namespace std;

int r, c, Q, R, B;

// Function to check if a position is safe for a given piece
bool pieceWalk(vector<vector<bool>> &board, int si, int sj, char piece) {
    if (piece == 'Q' || piece == 'R') {
        // Check column
        for (int i = 0; i < r; ++i)
            if (i != si && board[i][sj]) return false;
        // Check row
        for (int j = 0; j < c; ++j)
            if (j != sj && board[si][j]) return false;
    }
    if (piece == 'Q' || piece == 'B') {
        // Check diagonal top-left (\)
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
    }
    return true;
}

// Recursive function to place pieces
int calculate(vector<vector<bool>> &board, int q, int rCount, int b, int start) {
    if (q == Q && rCount == R && b == B) return 1;  // Base case: All pieces placed

    int ways = 0;
    for (int index = start; index < r * c; ++index) {
        int i = index / c, j = index % c;

        // Try placing Queen first
        if (q < Q && !board[i][j] && pieceWalk(board, i, j, 'Q')) {
            board[i][j] = 1;
            ways += calculate(board, q + 1, rCount, b, index + 1);
            board[i][j] = 0;
        }

        // Try placing Rook next
        if (rCount < R && !board[i][j] && pieceWalk(board, i, j, 'R')) {
            board[i][j] = 1;
            ways += calculate(board, q, rCount + 1, b, index + 1);
            board[i][j] = 0;
        }

        // Try placing Bishop next
        if (b < B && !board[i][j] && pieceWalk(board, i, j, 'B')) {
            board[i][j] = 1;
            ways += calculate(board, q, rCount, b + 1, index + 1);
            board[i][j] = 0;
        }
    }
    return ways;
}

int main() {
    cin >> r >> c;
    cin >> Q >> R >> B;

    vector<vector<bool>> board(r, vector<bool>(c, 0));

    cout << calculate(board, 0, 0, 0, 0) << endl;
    return 0;
}