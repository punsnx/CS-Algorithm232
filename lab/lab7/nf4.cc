//Pass
#include <iostream>
#include <vector>
#include <queue>
using namespace std;



int main(){
    int V,E,u,v,c;
    cin >> V >> E;

    vector<vector<int> > adjList(V,vector<int>());
    vector<int> in = vector<int>(V,0);
    vector<int> out =vector<int>(V,0);

    for(int i = 0;i<E;++i){
        cin >> u >> v >> c;
        if(u == v)
        {
            cout << "FALSE" << endl;
            return 0;
        }
        if(c < 0)
        {
            cout << "FALSE" << endl;
            return 0;
        }

        adjList[u].push_back(v);
        out[u]++;
        in[v]++;

    }
    int s = -1,scount = 0;
    int t = -1,tcount = 0;
    for(int i = 0;i<V;++i){
        if(out[i] && !in[i])
        {
            s = i;
            ++scount;
        }
        if(!out[i] && in[i])
        {
            t = i;
            ++tcount;
        }
    }
    if(scount != 1 || tcount != 1)
    {
        cout << "FALSE" << endl;
        return 0;
    }

    //BFS search from source s
    int visitedCount = 0;
    vector<bool> visited(V, false);
    queue<int> q;
    visited[s] = true;
    ++visitedCount;
    q.push(s);

    while (!q.empty()) {
        int current = q.front();
        q.pop();
        for (int e : adjList[current]) {
            if (!visited[e]) {
                visited[e] = true;
                ++visitedCount;
                q.push(e);
            }
        }
    }
    if(visitedCount != V)
    {
        cout << "FALSE" << endl;
        return 0;
    }


    cout << "TRUE" << endl;
    return 0;    














    return 0;
}