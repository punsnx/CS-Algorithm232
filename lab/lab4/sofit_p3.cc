#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

typedef struct _Edge{
    int dest;
    int weight;
}Edge;

long primMST(vector<vector<Edge> > &adjList) {
    int V = adjList.size();
    vector<int> key(V, INT_MAX);
    vector<bool> mstSet(V, false);
    priority_queue<pair<int, int> > pq;

    //root MST
    key[0] = 0;
    pq.push(pair<int,int>(0,0));

    long mstWeight = 0;
    while(!pq.empty() && V > 0){
        int u = pq.top().second;
        pq.pop();
        if(mstSet[u]) continue;
        mstSet[u] = true;
        mstWeight += key[u];
        V--;
        for (const Edge &edge : adjList[u]) {
            int v = edge.dest;
            if (mstSet[v] == false && edge.weight < key[v]){
                key[v] = edge.weight;
                pq.push(pair<int,int>(-edge.weight,v));
            }
        }

    }
    return mstWeight;
}

int main(){
    int nv,ne,s,d,c;
    while(true){
        cin >> nv >> ne;
        if (nv == 0 && ne == 0) break;
        vector<vector<Edge> > adjList(nv);
        long graphWeight = 0;
        for(int i = 0 ;i<ne;i++){
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