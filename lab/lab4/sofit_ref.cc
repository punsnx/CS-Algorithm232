#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int minKey(int V,vector<int> &key, vector<bool> &mstSet) {
    int min = INT_MAX, min_index;
    for(int v = 0; v < V; v++)
        if (mstSet[v] == false && key[v] < min)
            min = key[v], min_index = v;

    return min_index;
}


int primMST(vector<vector<int> > &graph) {
    int V = graph.size();
    vector<int> parent(V);
    vector<int> key(V, INT_MAX);
    vector<bool> mstSet(V, false);

    //root MST
    key[0] = 0;
    parent[0] = -1; 

    for (int count = 0; count < V - 1; count++) {
        int u = minKey(V,key, mstSet);
        mstSet[u] = true;
        for (int v = 0; v < V; v++)
            if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v]){
                parent[v] = u;
                key[v] = graph[u][v];
            }
    }
    int mstWeight = 0;
    for(int i = 1;i < V;i++)
        mstWeight += graph[parent[i]][i];

    return mstWeight;
}

int main(){
    int nv,ne,s,d,c;
    cin >> nv >> ne;

    vector<vector<int> > g(nv,vector<int>(nv,0));//for adj matrix
    int graphWeight = 0;
    while( (cin >> s >> d) && (s != 0 || d != 0)){
        cin >> c;
        g[s][d] = c;
        g[d][s] = c; //undirected g
        graphWeight += c;
    }
    // cout << "  "; 
    // for(int i = 0;i<nv;i++)cout << i << " ";
    // cout << endl;
    // for(int i = 0;i<nv;i++){
    //     cout << i << " " ;
    //     for(int &e : g[i]){
    //         cout << e << " ";
    //     }
    //     cout << endl;
    // }
    cout << graphWeight - primMST(g) << endl;




}