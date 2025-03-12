#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int a,b,Q,R,B;
short **board;

int queenWalk(int sr,int sc){
    for(int i = 0;i<a;++i)
        if(board[i][sc])return 0;

    for(int j = 0;j<b;++j)
        if(board[sr][j])return 0;

    for (int i = -a; i < a; ++i) {
        int dr1 = sr + i, dc1 = sc + i; // Main diagonal (\)
        int dr2 = sr + i, dc2 = sc - i; // Anti-diagonal (/)

        if (dr1 >= 0 && dr1 < a && dc1 >= 0 && dc1 < b && board[dr1][dc1]) return 0;
        if (dr2 >= 0 && dr2 < a && dc2 >= 0 && dc2 < b && board[dr2][dc2]) return 0;
    }
    return 1;   
}
int rookWalk(int sr,int sc){
    for(int i = 0;i<a;++i)
        if(board[i][sc])return 0;

    for(int j = 0;j<b;++j)
        if(board[sr][j])return 0;

    return 1;   
}
int bishopWalk(int sr,int sc){
    for (int i = -a; i < a; ++i) {
        int dr1 = sr + i, dc1 = sc + i; // Main diagonal (\)
        int dr2 = sr + i, dc2 = sc - i; // Anti-diagonal (/)

        if (dr1 >= 0 && dr1 < a && dc1 >= 0 && dc1 < b && board[dr1][dc1]) return 0;
        if (dr2 >= 0 && dr2 < a && dc2 >= 0 && dc2 < b && board[dr2][dc2]) return 0;
    }
    return 1;   
}
long bishop(int start,int b){
    if(b == B)return 1;
    else{
        long ways = 0;
        for (int index = start; index < a * b; ++index) {
            int i = index / b, j = index % b; 
            if(!board[i][j] && bishopWalk(i,j)){
                    board[i][j] = 1;
                    ways += bishop(index+1,b+1);
                    board[i][j] = 0;
            }
        }
        return ways;

    }

}

long rook(int start,int r){
    if(r == R)return bishop(start,0);
    else{
        long ways = 0;
        for (int index = start; index < a * b; ++index) {
            int i = index / b, j = index % b; 
            if(!board[i][j] && rookWalk(i,j)){
                    board[i][j] = 1;
                    ways += rook(index+1,r+1);
                    board[i][j] = 0;
            }
        }
        return ways;

    }

}
long queen(int start,int q){
    if(q == Q){
        if(R)return rook(start,0);
        else return bishop(start,0);
    }
    else{
        long ways = 0;
        for (int index = start; index < a * b; ++index) {
            int i = index / b, j = index % b; 
            if(!board[i][j] && queenWalk(i,j)){
                    board[i][j] = 1;
                    ways += queen(index+1,q+1);
                    board[i][j] = 0;
            }
        }
        return ways;

    }

}


int main(){
    scanf("%d %d",&a,&b);
    scanf("%d %d %d",&Q,&R,&B);
    
    board = (short**)malloc(a * sizeof(short*));
    for(int i = 0;i<a;++i){
        board[i] = (short*)calloc(b,sizeof(short));
    }
    long sum = queen(0,0);
    printf("%ld\n",sum);

    
    








    return 0;
}