#include <iostream>
#include <vector>
#include <queue>
#include <limits>
using namespace std;

typedef struct  _Node
{
    bool include;
    int row;
    short w;
    int pi;
}Node;

struct CompareNode {
    bool operator()(Node *n1, Node *n2){
        return n1->pi > n2->pi; //decending order
    }
};



void dijkstra(vector<vector<Node> > &node,int nr,int mc,int sr,int sc){
    priority_queue<Node*,vector<Node*>,CompareNode> pq;
    node[sr][sc].pi = 0;
    for(int r = 0;r<nr;++r){
        for(int c = 0;c<mc;++c){
            node[r][c].include = false;
            pq.push(&node[r][c]);
        }
    }


    while(!pq.empty()){
        Node *u = pq.top();
        pq.pop();
        u->include = true;

        for(int r = 0;r<nr;++r){
            for(int c = 0;c<mc;++c){
                if(!node[r][c].include && node[u->row][c].w 
                && u->pi != INT_MAX && u->pi + node[u->row][c].w < node[u->row][c].pi){
                    node[u->row][c].pi = u->pi + node[u->row][c].w;
                }
            }
        }

    }
    
    // int i = 0;
    // while(!pq.empty()){
    //     cout << pq.top()->w << " ";
    //     pq.pop();
    //     if(++i % mc == 0)cout << endl;
    // }
}

void find_path(int nr,int mc){
    vector<vector<Node> > node(nr,vector<Node>(mc));
    for(int r = 0;r<nr;++r){
        for(int c = 0;c<mc;++c){
            node[r][c].pi = INT_MAX;
            node[r][c].row = r;
            cin >> node[r][c].w;
        }
    }
    cout << nr << endl;
    cout << mc << endl;
    for(int r = 0;r<nr;++r){
        for(int c = 0;c<mc;++c){
            cout << node[r][c].w << " ";
        }
        cout << endl;
    }
    dijkstra(node,nr,mc,0,0);
    cout << endl;
    for(int r = 0;r<nr;++r){
        for(int c = 0;c<mc;++c){
            cout << node[r][c].pi << " ";
        }
        cout << endl;
    }
    

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