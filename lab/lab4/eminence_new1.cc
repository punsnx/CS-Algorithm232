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

typedef struct _Queue {
    int cost;
    int r;
    int c;

    _Queue(int cost, int r, int c) : cost(cost), r(r), c(c) {}
    bool operator<(const _Queue& other) const {
        return cost > other.cost;
    }
}Queue;

void dijkstra(vector<vector<Node> > &graph, int n, int m) {
    priority_queue<Queue> pq;
    
    graph[0][0].key = graph[0][0].weight;
    pq.push(Queue(graph[0][0].key, 0, 0));

    while(!pq.empty()) {
        Queue current = pq.top();
        int cur_cost = current.cost;
        int uc = current.c;
        int ur = current.r;
        pq.pop();

        if(graph[ur][uc].visited || cur_cost > graph[ur][uc].key) continue;
        graph[ur][uc].visited = true;

        if(ur == n-1 && uc == m-1) {
            cout << graph[n-1][m-1].key << endl;
            return;
        }               

        //top
        if(ur - 1 >= 0){
            int sr = ur -1;
            int sc = uc;
            if(!graph[sr][sc].visited && graph[ur][uc].key != INT_MAX && 
            graph[ur][uc].key + graph[sr][sc].weight < graph[sr][sc].key) {
                graph[sr][sc].key = graph[ur][uc].key + graph[sr][sc].weight;
                pq.push(Queue(graph[sr][sc].key, sr, sc));
            }   
        }
        //bottom
        if(ur + 1 < n){
            int sr = ur +1;
            int sc = uc;
            if(!graph[sr][sc].visited && graph[ur][uc].key != INT_MAX && 
            graph[ur][uc].key + graph[sr][sc].weight < graph[sr][sc].key) {
                graph[sr][sc].key = graph[ur][uc].key + graph[sr][sc].weight;
                pq.push(Queue(graph[sr][sc].key, sr, sc));
            }   
        }
        //left
        if(uc - 1 >= 0){
            int sr = ur;
            int sc = uc-1;
            if(!graph[sr][sc].visited && graph[ur][uc].key != INT_MAX && 
            graph[ur][uc].key + graph[sr][sc].weight < graph[sr][sc].key) {
                graph[sr][sc].key = graph[ur][uc].key + graph[sr][sc].weight;
                pq.push(Queue(graph[sr][sc].key, sr, sc));
            }   
        }
        //right
        if(uc + 1 < m){
            int sr = ur;
            int sc = uc +1;
            if(!graph[sr][sc].visited && graph[ur][uc].key != INT_MAX && 
            graph[ur][uc].key + graph[sr][sc].weight < graph[sr][sc].key) {
                graph[sr][sc].key = graph[ur][uc].key + graph[sr][sc].weight;
                pq.push(Queue(graph[sr][sc].key, sr, sc));
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
        vector<vector<Node> > graph(n, vector<Node>(m));
        for(int r = 0; r < n; r++) {
            for(int c = 0; c < m; c++) {
                cin >> graph[r][c].weight;
                graph[r][c].visited = false;
                graph[r][c].key = INT_MAX;
            }
        }
        
        dijkstra(graph, n, m);
    }

    return 0;
}