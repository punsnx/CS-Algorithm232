//pass
#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

int min(int a, int b) {
    return (a < b) ? a : b;
}

int maxFlow(vector<vector<int> >& graph, int source, int sink, int V) {
    vector<vector<int> > residualGraph = graph;
    vector<int> parent(V, -1);
    
    int maxFlow = 0;
    
    while (true) {
        queue<int> q;
        for (int i = 0; i < V; i++) {
            parent[i] = -1;
        }
        parent[source] = -2; 
        q.push(source);
        
        while (!q.empty() && parent[sink] == -1) {
            int u = q.front();
            q.pop();
            
            for (int v = 0; v < V; v++) {
                if (residualGraph[u][v] > 0 && parent[v] == -1) {
                    parent[v] = u;
                    q.push(v);
                }
            }
        }
        
        if (parent[sink] == -1) {
            break;
        }

        int pathFlow = INT_MAX;
        for (int v = sink; v != source; v = parent[v]) {
            int u = parent[v];
            pathFlow = min(pathFlow, residualGraph[u][v]);
        }
        
        for (int v = sink; v != source; v = parent[v]) {
            int u = parent[v];
            residualGraph[u][v] -= pathFlow;
            residualGraph[v][u] += pathFlow; 
        }
        
        maxFlow += pathFlow;
    }
    
    return maxFlow;
}

int main() {
    int V, E;
    cin >> V >> E;
    
    int source, sink;
    cin >> source >> sink;
    
    
    vector<vector<int> > graph(V, vector<int>(V, 0));
    
    
    for (int i = 0; i < E; i++) {
        int u, v, capacity;
        cin >> u >> v >> capacity;
        graph[u][v] = capacity;
    }
    
    
    cout << maxFlow(graph, source, sink, V) << endl;
    
    return 0;
}