#include <iostream>
#include <vector>
#include <queue>
using namespace std;



bool isGraphConnected(int V,short source,vector<vector<short> > &adjList) {
    vector<bool> visited(V,0);  
    queue<short> q;
    q.push(source);
    visited[source] = true;
    
    short visitedCount = 0;
    
    while (!q.empty()) {
        short u = q.front();
        q.pop();
        visitedCount++;
        
        for (int v : adjList[u]) {
            if (!visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }

    return (visitedCount == adjList.size());
}

bool isNF(short V,vector<vector<short> > &adjList,vector<short> &inDegree) {
    short source = -1, sink = -1;
    short sourceCount = 0, sinkCount = 0;

    for (int i = 0; i < V; ++i) {
        if (inDegree[i] == 0 && !adjList[i].empty()) { 
            source = i;
            sourceCount++;
        }
        if (adjList[i].empty()) { 
            sink = i;
            sinkCount++;
        }
    }

    if (sourceCount != 1 || sinkCount != 1) return false;

    if (!isGraphConnected(V,source,adjList)) return false;

    return true;
}

int main() {
    int V,E;
    int u,v,c;
    cin >> V >> E;
    vector<vector<short> > adjList(V,vector<short>());
    vector<short> inDegree(V,0);  

    for (int i = 0; i < E; ++i) {
        cin >> u >> v >> c;
        
        // Self-loop check
        if (u == v || c < 0) {
            cout << "FALSE" << endl;
            return 0;
        }
        
        adjList[u].push_back(v);
        inDegree[v]++;
    }

    cout << (isNF(V,adjList,inDegree) ? "TRUE" : "FALSE") << endl;
    return 0;
}