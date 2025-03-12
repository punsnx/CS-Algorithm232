#include <iostream>
#include <vector>
using namespace std;

int r,c;
int Q,R,B;

bool queenWalk(vector<vector<bool> > board,int si,int sj){
    //up to down
    for(int i = 0;i < r;++i){
        if(i != si && board[i][sj])return 0;
    }
    //left to right
    for(int j = 0;j < c;++j){
        if(j != sj && board[si][j])return 0;
    }

    //othogonal
    int i = si-1, j = sj-1;
    while(i >= 0 && j >= 0){
        if(board[i--][j--])return 0;
    }

    i = si+1, j = sj+1;
    while(i < r && j < c){
        if(board[i++][j++])return 0;
    }
    //othogonal invert
    i = si-1, j = sj+1;
    while(i >= 0 && j < c){
        if(board[i--][j++])return 0;
    }

    i = si+1, j = sj-1;
    while(i < r && j >= 0){
        if(board[i++][j--])return 0;
    }

    return 1;
}


int calculate(vector<vector<bool> > board,int i, int q) {
    i = i % r;
    if(q == Q) return 1;//place successfully
       
    int ways = 0; 
    for(int j = 0;j < c;++j){
        if(!board[i][j]){
            if(queenWalk(board,i,j)){
                board[i][j] = 1;
                ways += calculate(board,i+1,q+1);
                board[i][j] = 0;
            }
        }
    }
    return ways; 

}

int main(){

    cin >> r >> c;
    cin >> Q >> R >> B;

    vector<vector<bool> > board(r,vector<bool>(c,0));

    int sum = 0;
    for(int i = 0; i < r;++i){
        sum += calculate(board,i,0);
    }
    cout << sum  << endl;

    

    
    return 0;
}