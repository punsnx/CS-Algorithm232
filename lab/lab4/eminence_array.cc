#include <iostream>
#include <climits>
#include <vector>
#include <queue>
using namespace std;

typedef struct _Node {
    int weight;
    bool visited;
    int key;
} Node;

void dijkstra(Node** graph, int n, int m) {
    priority_queue<pair<int, pair<int,int> >, 
                  vector<pair<int, pair<int,int> > >,
                  greater<pair<int, pair<int,int> > > > pq;
    
    //top, right, bottom, left
    int dr[] = {-1, 0, 1, 0};
    int dc[] = {0, 1, 0, -1};

    graph[0][0].key = graph[0][0].weight;
    pq.push(pair<int,pair<int,int> > (graph[0][0].key, pair<int,int> (0,0)));

    while(!pq.empty()) {
        int cur_cost = pq.top().first;
        int ur = pq.top().second.first;
        int uc = pq.top().second.second;
        pq.pop();
        
        if(graph[ur][uc].visited || cur_cost > graph[ur][uc].key) continue;
        graph[ur][uc].visited = true;

        if(ur == n-1 && uc == m-1) {
            cout << graph[n-1][m-1].key << endl;
            return;
        }               

        for(int i = 0; i < 4; i++) {
            int sr = ur + dr[i];
            int sc = uc + dc[i];
            if(sr >= 0 && sr < n && sc >= 0 && sc < m) {
                if(!graph[sr][sc].visited && graph[ur][uc].key != INT_MAX && 
                   graph[ur][uc].key + graph[sr][sc].weight < graph[sr][sc].key) {
                    graph[sr][sc].key = graph[ur][uc].key + graph[sr][sc].weight;
                    pq.push(pair<int,pair<int,int> > (graph[sr][sc].key, pair<int,int>(sr,sc)));
                }
            }
        }
    }
    cout << graph[n-1][m-1].key << endl;
}

int main() {
    int room;
    cin >> room;
    
    for(int i = 0; i < room; i++) {
        int n, m;
        cin >> n >> m;
        
        Node** graph = new Node*[n];
        for(int r = 0; r < n; r++) {
            graph[r] = new Node[m];
        }
        
        for(int r = 0; r < n; r++) {
            for(int c = 0; c < m; c++) {
                cin >> graph[r][c].weight;
                graph[r][c].visited = false;
                graph[r][c].key = INT_MAX;
            }
        }
        
        dijkstra(graph, n, m);
        
        for(int r = 0; r < n; r++) {
            delete[] graph[r];
        }
        delete[] graph;
    }

    return 0;
}