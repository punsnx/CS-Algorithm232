#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

// Custom min function to avoid using algorithm library
int min(int a, int b) {
    return (a < b) ? a : b;
}

// Function to find maximum flow from source to sink
int maxFlow(vector<vector<int>>& graph, int source, int sink, int V) {
    // Create residual graph with same capacities as original graph
    vector<vector<int>> residualGraph = graph;
    
    // Create parent array to store BFS paths
    vector<int> parent(V, -1);
    
    int maxFlow = 0; // Initialize max flow to 0
    
    // Augment the flow while there is a path from source to sink
    while (true) {
        // Use BFS to find an augmenting path
        queue<int> q;
        for (int i = 0; i < V; i++) {
            parent[i] = -1;
        }
        parent[source] = -2; // Mark source as visited with special value
        q.push(source);
        
        // BFS loop to find a path with available capacity
        while (!q.empty() && parent[sink] == -1) {
            int u = q.front();
            q.pop();
            
            // Try all adjacent vertices
            for (int v = 0; v < V; v++) {
                // If there is capacity and v is not visited yet
                if (residualGraph[u][v] > 0 && parent[v] == -1) {
                    parent[v] = u;
                    q.push(v);
                }
            }
        }
        
        // If we can't reach sink in BFS, we're done
        if (parent[sink] == -1) {
            break;
        }
        
        // Find the minimum capacity in the augmenting path
        int pathFlow = INT_MAX;
        for (int v = sink; v != source; v = parent[v]) {
            int u = parent[v];
            pathFlow = min(pathFlow, residualGraph[u][v]);
        }
        
        // Update residual capacities of the edges and reverse edges
        for (int v = sink; v != source; v = parent[v]) {
            int u = parent[v];
            residualGraph[u][v] -= pathFlow;
            residualGraph[v][u] += pathFlow; // Add reverse edge for residual graph
        }
        
        // Add path flow to overall flow
        maxFlow += pathFlow;
    }
    
    return maxFlow;
}

int main() {
    int V, E; // Number of vertices and edges
    cin >> V >> E;
    
    int source, sink;
    cin >> source >> sink;
    
    // Initialize graph with all capacities as 0
    vector<vector<int>> graph(V, vector<int>(V, 0));
    
    // Read the edges and capacities
    for (int i = 0; i < E; i++) {
        int u, v, capacity;
        cin >> u >> v >> capacity;
        graph[u][v] = capacity;
    }
    
    // Calculate and output maximum flow
    cout << maxFlow(graph, source, sink, V) << endl;
    
    return 0;
}