#include <iostream>
#include <vector>
using namespace std;

void findPaths(vector<vector<int> >& graph, vector<int>& path, vector<bool>& visited, 
               int current, int m, int n) {
    // Add current vertex to path
    path.push_back(current + 1);
    visited[current] = true;
    
    // If path length reaches m, print the path
    if (path.size() == m + 1) {
        cout << "(";
        for (int i = 0; i < path.size(); i++) {
            cout << path[i];
            if (i < path.size() - 1) cout << ", ";
        }
        cout << ")\n";
    } else {
        // Try all possible next vertices
        for (int next = 0; next < n; next++) {
            if (!visited[next] && graph[current][next]) {
                findPaths(graph, path, visited, next, m, n);
            }
        }
    }
    
    // Backtrack
    visited[current] = false;
    path.pop_back();
}

int main() {
    int n, m;
    
    while (cin >> n >> m) {
        // Read adjacency matrix
        vector<vector<int> > graph(n, vector<int>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> graph[i][j];
            }
        }
        
        // Initialize path and visited array
        vector<int> path;
        vector<bool> visited(n, false);
        
        // Find all paths starting from vertex 0 (vertex 1 in output)
        findPaths(graph, path, visited, 0, m, n);
        
        // Check if any paths were found
        bool found = false;
        for (int i = 0; i < n; i++) {
            if (graph[0][i]) {
                found = true;
                break;
            }
        }
        
        if (!found) {
            cout << "No Walk Of Length " << m << "\n";
        }
        
        cout << "\n";
        
        // Check for end of test case
        int end;
        if (cin >> end && end == -999) {
            continue;
        } else {
            break;
        }
    }
    
    return 0;
}