#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef struct _Edge{
    int e;
    int w;
}Edge;

vector<vector<Edge> > adjList;

int checkSource(int i){
    if(!adjList[i].empty()){
        for (int j = 0; j < adjList.size(); ++j) {
            if (j == i) continue;
            for (Edge &e : adjList[j]) {
                if (e.e == i) return 0; // Incoming edge found
            }
        }
        return 1; // No incoming edge
    }
    return 0;

}

bool checkSink(int i){
    if(adjList[i].empty()){   
        //include independent node
        return 1;
    }
    return 0;

}
bool isGraphConnected(int source) {
    vector<bool> visited(adjList.size(), 0);
    queue<int> q;
    
    q.push(source);
    visited[source] = 1;
    
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        
        for (Edge &e : adjList[u]) {
            if (!visited[e.e]) {
                visited[e.e] = 1;
                q.push(e.e);
            }
        }
    }

    //All nodes visited???
    for (int i = 0; i < adjList.size(); ++i) {
        if (!visited[i]) {
            return 0;
        }
    }
    return 1;
}

bool isNF(){
    int s = -1,scount = 0;
    int t = -1,tcount = 0;
    for(int i = 0;i < adjList.size();++i){
        if(checkSource(i)){
            s = i;
            ++scount;
        }
        if(checkSink(i)){
            t = i;
            ++tcount;
        }
    }
    if( scount > 1 || tcount > 1)return 0;
    if(!isGraphConnected(s))return 0;
    





    return 1;
}

void printList(){
    for(int i = 0;i<adjList.size();++i){
        vector<Edge> &n = adjList[i];
        cout << i << ": ";
        for(Edge &e : n){
               cout << "-> " << e.e << "(" << e.w << ")"; 
        }
        cout << endl;
    }


}

int main(){
    short V,E;
    short u,v,c;

    cin >> V >> E;
    
    adjList = vector<vector<Edge> >(V,vector<Edge>(0));
    for(int i = 0;i<E;++i){
        cin >> u >> v >> c;
        //Check self-loop
        if (u == v) {
            cout << "FALSE" << endl;
            return 0;
        }
        //Check Capacity
        if(c < 0){
            cout << "FALSE" << endl;
            return 0;
        }
        Edge t = {v,c};
        adjList[u].push_back(t);

    }
    // printList();
    cout << (isNF() ? "TRUE" : "FALSE") << endl;


    return 0;
}