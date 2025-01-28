#include <iostream>
#include <vector>
#include <climits>
#include <queue>
using namespace std;

void dijkstra(vector<vector<int> > &graph, int n, int m) {
    vector<vector<bool> > SSet(n, vector<bool>(m, false));
    vector<vector<int> > key(n, vector<int>(m, INT_MAX));
    priority_queue<pair<int, pair<int,int> >, 
                    vector<pair<int, pair<int,int> > >, 
                    greater<pair<int, pair<int,int> > > > pq;
    
    //top, right, bottom, left
    int dr[] = {-1, 0, 1, 0};
    int dc[] = {0, 1, 0, -1};

    // key[0][0] = 0; 
    key[0][0] = graph[0][0]; 
    pq.push(pair<int,pair<int,int> > (key[0][0], pair<int,int> (0,0)));

    while(!pq.empty()) {
        int cost = pq.top().first;
        int ur = pq.top().second.first;
        int uc = pq.top().second.second;
        pq.pop();
        
        if(SSet[ur][uc]) continue;
        SSet[ur][uc] = true;

        for(int i = 0; i < 4; i++) {
            int sr = ur + dr[i];
            int sc = uc + dc[i];
            if(sr >= 0 && sr < n && sc >= 0 && sc < m) {
                if(!SSet[sr][sc] && 
                   cost + graph[sr][sc] < key[sr][sc]) {
                    key[sr][sc] = cost + graph[sr][sc];
                    pq.push(pair<int,pair<int,int> > (key[sr][sc], pair<int,int> (sr, sc)));
                }
            }
        }
    }
    // for(int r = 0; r < n; r++) {
    //     for(int c = 0; c < m; c++) {
    //         cout << key[r][c] << " ";
    //     }
    //     cout << endl;
    // }
    cout << key[n-1][m-1] << endl;
}

int main() {
    int room;
    cin >> room;
    
    for(int i = 0; i < room; i++) {
        int n, m;
        cin >> n >> m;
        vector<vector<int> > g(n, vector<int>(m));
        
        for(int r = 0; r < n; r++) {
            for(int c = 0; c < m; c++) {
                int value;
                cin >> value;
                g[r][c] = value;
            }
        }
        
        dijkstra(g, n, m);
    }

    return 0;
}