#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int> > adjList;
vector<int> inDegree;  
vector<bool> visited;  

int source = -1, sink = -1;

bool isGraphConnected(int source) {
    queue<int> q;
    q.push(source);
    visited[source] = true;
    
    int visitedCount = 0;
    
    while (!q.empty()) {
        int u = q.front();
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

bool isNF(int V) {
    int sourceCount = 0, sinkCount = 0;

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

    visited.assign(V, false);
    if (!isGraphConnected(source)) return false;

    return true;
}

int main() {
    int V,E;
    int u,v,c;
    cin >> V >> E;

    adjList.assign(V, vector<int>());
    inDegree.assign(V, 0);
    visited.assign(V, false);

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

    cout << (isNF(V) ? "TRUE" : "FALSE") << endl;
    return 0;
}