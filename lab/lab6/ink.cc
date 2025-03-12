#include <iostream>
#include <vector>
using namespace std;

void findPaths(vector<vector<int> >& graph, vector<int>& path, vector<bool>& visited, 
               int current, int m, int n) {
    path.push_back(current + 1);
    visited[current] = true;

    if (path.size() == m + 1) {
        cout << "(";
        for (int i = 0; i < path.size(); i++) {
            cout << path[i];
            if (i < path.size() - 1) cout << ", ";
        }
        cout << ")\n";
    } else {
        for (int next = 0; next < n; next++) {
            if (!visited[next] && graph[current][next]) {
                findPaths(graph, path, visited, next, m, n);
            }
        }
    }
    
    visited[current] = false;
    path.pop_back();
}

int main() {
    int n, m;
    
    while (cin >> n >> m) {
        vector<vector<int> > graph(n, vector<int>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> graph[i][j];
            }
        }
        
        vector<int> path;
        vector<bool> visited(n, false);
        
        findPaths(graph, path, visited, 0, m, n);
        
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
        
        int end;
        if (cin >> end && end == -999) {
            continue;
        } else {
            break;
        }
    }
    
    return 0;
}