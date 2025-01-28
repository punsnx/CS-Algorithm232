#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

typedef struct _Edge{
    int dest;
    int weight;
}Edge;

// Using priority queue to optimize finding minimum key
long primMST(vector<vector<Edge> > &adjList) {
    int V = adjList.size();
    vector<int> key(V, INT_MAX);
    vector<bool> mstSet(V, false);
    
    // Using pair<weight, vertex> for priority queue
    // First element is negative weight to make it a min-heap
    priority_queue<pair<int, int> > pq;
    
    key[0] = 0;
    pair<int,int> init_pair(0,0);
    pq.push(init_pair);  // {-weight, vertex}
    
    long mstWeight = 0;
    while(!pq.empty() && V > 0) {
        int u = pq.top().second;
        pq.pop();
        
        if(mstSet[u]) continue;  // Skip if already processed
        
        mstSet[u] = true;
        mstWeight += key[u];
        V--;  // Decrease remaining vertices count
        
        for(const Edge &edge : adjList[u]) {
            int v = edge.dest;
            int weight = edge.weight;
            
            if(!mstSet[v] && weight < key[v]) {
                key[v] = weight;
                pair<int,int> p(-weight, v);
                pq.push(p);  // Negative weight for min-heap
            }
        }
    }
    
    return mstWeight;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int nv, ne, s, d, c;
    while(true) {
        cin >> nv >> ne;
        if(nv == 0 && ne == 0) break;
        
        vector<vector<Edge> > adjList(nv);
        long graphWeight = 0;
        
        for(int i = 0; i < ne; i++) {
            cin >> s >> d >> c;
            Edge e1 = {d,c};
            Edge e2 = {s,c};
            adjList[s].push_back(e1);
            adjList[d].push_back(e2);
            graphWeight += c;
        }
        
        cout << graphWeight - primMST(adjList) << endl;
    }
    return 0;
}