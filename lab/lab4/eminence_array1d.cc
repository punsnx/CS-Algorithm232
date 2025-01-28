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

void dijkstra(Node* graph, int n, int m) {
    priority_queue<pair<int, pair<int,int> >, 
                  vector<pair<int, pair<int,int> > >,
                  greater<pair<int, pair<int,int> > > > pq;
    
    //top, right, bottom, left
    int dr[] = {-1, 0, 1, 0};
    int dc[] = {0, 1, 0, -1};

    int start_idx = 0;
    graph[start_idx].key = graph[start_idx].weight;
    pq.push(pair<int,pair<int,int> > (graph[start_idx].key, pair<int,int> (0,0)));

    while(!pq.empty()) {
        int cur_cost = pq.top().first;
        int ur = pq.top().second.first;
        int uc = pq.top().second.second;
        int u_idx = ur * m + uc; 
        pq.pop();
        
        if(graph[u_idx].visited || cur_cost > graph[u_idx].key) continue;
        graph[u_idx].visited = true;

        if(ur == n-1 && uc == m-1) {
            cout << graph[(n-1)*m + (m-1)].key << endl;
            return;
        }

        for(int i = 0; i < 4; i++) {
            int sr = ur + dr[i];
            int sc = uc + dc[i];
            if(sr >= 0 && sr < n && sc >= 0 && sc < m) {
                int s_idx = sr * m + sc;  
                if(!graph[s_idx].visited && graph[u_idx].key != INT_MAX && 
                   graph[u_idx].key + graph[s_idx].weight < graph[s_idx].key) {
                    graph[s_idx].key = graph[u_idx].key + graph[s_idx].weight;
                    pq.push(pair<int,pair<int,int> > (graph[s_idx].key, pair<int,int>(sr,sc)));
                }
            }
        }
    }
    cout << graph[(n-1)*m + (m-1)].key << endl;
}

int main() {
    int room;
    cin >> room;
    
    for(int i = 0; i < room; i++) {
        int n, m;
        cin >> n >> m;

        Node* graph = new Node[n * m];
        for(int r = 0; r < n; r++) {
            for(int c = 0; c < m; c++) {
                int idx = r * m + c;  
                cin >> graph[idx].weight;
                graph[idx].visited = false;
                graph[idx].key = INT_MAX;
            }
        }
        
        dijkstra(graph, n, m);
        delete[] graph;
    }

    return 0;
}