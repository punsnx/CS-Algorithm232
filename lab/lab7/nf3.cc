#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool isReachableFromSource(short V, short source, const vector<vector<short> > &adjList) {
    vector<bool> visited(V, false);
    queue<short> q;
    q.push(source);
    visited[source] = true;
    
    while (!q.empty()) {
        short u = q.front();
        q.pop();
        
        for (short v : adjList[u]) {
            if (!visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }
    
    // Check if all vertices are reachable from source
    for (short i = 0; i < V; i++) {
        if (!visited[i]) return false;
    }
    return true;
}

bool canReachSink(short V, short sink, const vector<vector<short> > &revAdjList) {
    vector<bool> visited(V, false);
    queue<short> q;
    q.push(sink);
    visited[sink] = true;
    
    while (!q.empty()) {
        short u = q.front();
        q.pop();
        
        for (short v : revAdjList[u]) {
            if (!visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }
    
    // Check if sink is reachable from all vertices
    for (short i = 0; i < V; i++) {
        if (!visited[i]) return false;
    }
    return true;
}

bool isValidNetworkFlow(short V, const vector<vector<short> > &adjList, const vector<vector<short> > &revAdjList, 
                       const vector<short> &inDegree, const vector<short> &outDegree) {
    // Find source and sink
    short source = -1, sink = -1;
    short sourceCount = 0, sinkCount = 0;
    
    for (short i = 0; i < V; i++) {
        if (inDegree[i] == 0 && outDegree[i] > 0) {
            source = i;
            sourceCount++;
        }
        if (outDegree[i] == 0 && inDegree[i] > 0) {
            sink = i;
            sinkCount++;
        }
    }
    
    // Must have exactly one source and one sink
    if (sourceCount != 1 || sinkCount != 1) return false;
    
    // All nodes must be reachable from source
    if (!isReachableFromSource(V, source, adjList)) return false;
    
    // All nodes must be able to reach sink
    if (!canReachSink(V, sink, revAdjList)) return false;
    
    return true;
}

int main() {
    short V;
    int E;
    cin >> V >> E;
    
    vector<vector<short> > adjList(V);
    vector<vector<short> > revAdjList(V);
    vector<short> inDegree(V, 0);
    vector<short> outDegree(V, 0);
    
    short u, v;
    int c;
    
    for (int i = 0; i < E; i++) {
        cin >> u >> v >> c;
        
        // Check for self-loops and non-positive capacities
        if (u == v || c <= 0) {
            cout << "FALSE" << endl;
            return 0;
        }
        
        adjList[u].push_back(v);
        revAdjList[v].push_back(u);
        inDegree[v]++;
        outDegree[u]++;
    }
    
    cout << (isValidNetworkFlow(V, adjList, revAdjList, inDegree, outDegree) ? "TRUE" : "FALSE") << endl;
    return 0;
}