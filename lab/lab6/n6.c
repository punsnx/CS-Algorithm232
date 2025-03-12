// pass tier 2
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int row, col, Q, R, B;

typedef struct {
    int r, c, type; 
} Piece;

Piece placed[100]; 
int placedCount = 0;

int safe(int r, int c, int piece) {
    for (int i = 0; i < placedCount; i++) {
        int pr = placed[i].r, pc = placed[i].c, p = placed[i].type;
        if ((r == pr || c == pc) && (piece == 1 || piece == 2 || p == 1 || p == 2))
            return 0;
        if (abs(r - pr) == abs(c - pc) && (piece == 1 || piece == 3 || p == 1 || p == 3))
            return 0;
    }
    return 1;
}

long cal(int index, int q, int r, int b) {
    if(q == Q && r == R && b == B)
        return 1;
    if(index >= row * col)
        return 0;
    
    int remaining = row * col - index;
    int needed = (Q - q) + (R - r) + (B - b);
    if(remaining < needed)
        return 0;

    long ways = 0;
    int i = index / col, j = index % col;
    
    ways += cal(index + 1, q, r, b);
    
    if(q < Q && safe(i, j, 1)) {
        placed[placedCount].r = i;
        placed[placedCount].c = j;
        placed[placedCount].type = 1;
        placedCount++;
        ways += cal(index + 1, q + 1, r, b);
        placedCount--; 
        }
    if(r < R && safe(i, j, 2)) {
        placed[placedCount].r = i;
        placed[placedCount].c = j;
        placed[placedCount].type = 2;
        placedCount++;
        ways += cal(index + 1, q, r + 1, b);
        placedCount--;  
    }
    if(b < B && safe(i, j, 3)) {
        placed[placedCount].r = i;
        placed[placedCount].c = j;
        placed[placedCount].type = 3;
        placedCount++;
        ways += cal(index + 1, q, r, b + 1);
        placedCount--;  
    }
    
    return ways;
}

int main() {
    scanf("%d %d", &row, &col);
    scanf("%d %d %d", &Q, &R, &B);
    
    long sum = cal(0, 0, 0, 0);
    printf("%ld\n", sum);
    
    return 0;
}