#include <iostream>
#include <vector>
#include <climits>
using namespace std;

typedef struct  _Node
{
    bool visited;
    int dist;
    short w;
}Node;

typedef struct _Coordinate{
    int r;
    int c;
}Coordinate;

Coordinate minDistance(vector<vector<Node> > &node,int nr,int mc){
    int min = INT_MAX;
    Coordinate minNode;
    minNode.r = -1;
    minNode.c = -1;
    for(int r = 0;r < nr; ++r){
        for(int c = 0;c < mc; ++c){
            Node *cur = &node[r][c];
            if(!cur->visited && cur->dist < min){
                min = cur->dist;
                minNode.r = r;
                minNode.c = c;
            }
        }
    }
    return minNode;
}


void dijkstra(vector<vector<Node> > &node, int nr, int mc, int sr, int sc) {
    node[sr][sc].dist = 0;

   Coordinate uC;
    while ((uC = minDistance(node, nr, mc)).r != -1 && uC.c != -1) {
        int ur = uC.r, uc = uC.c;
        Node *u = &node[ur][uc];
        u->visited = true;

        //top, right, bottom, left
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};
        for (int i = 0; i < 4; ++i) {
            int _r = ur + dr[i];
            int _c = uc + dc[i];
            //Check bounds
            if (_r >= 0 && _r < nr && _c >= 0 && _c < mc) {
                Node *cur = &node[_r][_c];
                if (!cur->visited && cur->w &&u->dist != INT_MAX && u->dist + cur->w < cur->dist) {
                    cur->dist = u->dist + cur->w;
                }
            }
        }
    }
}

void find_path(int nr,int mc){
    vector<vector<Node> > node(nr,vector<Node>(mc));
    for(int r = 0;r<nr;++r){
        for(int c = 0;c<mc;++c){
            node[r][c].visited = false;
            node[r][c].dist = INT_MAX;
            cin >> node[r][c].w;
        }
    }
    // cout << nr << endl;
    // cout << mc << endl;
    // for(int r = 0;r<nr;++r){
    //     for(int c = 0;c<mc;++c){
    //         cout << node[r][c].w << " ";
    //     }
    //     cout << endl;
    // }
    // cout << endl;
    dijkstra(node,nr,mc,0,0);
    // for(int r = 0;r<nr;++r){
    //     for(int c = 0;c<mc;++c){
    //         cout << node[r][c].dist << " ";
    //     }
    //     cout << endl;
    // }
    cout << node[nr-1][mc-1].dist << endl;
    

}



int main(){
    int nr,nrow,mcol;
    cin >> nr;
    for(int i =0;i<nr;i++){
        cin >> nrow;    
        cin >> mcol;
        find_path(nrow,mcol);
    }

    return 0;
}