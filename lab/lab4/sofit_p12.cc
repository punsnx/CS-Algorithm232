#include <iostream>
#include <vector>
#include <climits>
using namespace std;

typedef struct _Edge{
    int dest;
    int weight;
}Edge;

int minKey(int V,vector<int> &key, vector<bool> &mstSet) {
    int min = INT_MAX, min_index;
    for(int v = 0; v < V; v++)
        if (mstSet[v] == false && key[v] < min)
            min = key[v], min_index = v;

    return min_index;
}


long primMST(vector<vector<Edge> > &adjList) {
    int V = adjList.size();
    vector<int> key(V, INT_MAX);
    vector<bool> mstSet(V, false);

    //root MST
    key[0] = 0;

    long mstWeight = 0;
    for (int count = 0; count < V-1; count++) {
        int u = minKey(V,key, mstSet);
        mstSet[u] = true;
        for (const Edge &edge : adjList[u]) {
            int v = edge.dest;
            if (mstSet[v] == false && edge.weight < key[v]){
                key[v] = edge.weight;
            }
        }
    }

    for (int i = 0; i < V; i++) {
        if (key[i] != INT_MAX) {
        mstWeight += key[i];
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