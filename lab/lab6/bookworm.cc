// PASS 
#include <iostream>
#include <vector>
#include <string>
using namespace std;

void addNode(vector<vector<int> > &adjList,int source, int dest){
    for(int i = 0;i<adjList[source].size();++i) if(adjList[source][i] == dest)return;
    //have source destination also have too
    adjList[source].push_back(dest);
    adjList[dest].push_back(source);
}


bool DFS(vector<vector<int> > &adjList,vector<char> &node,string &line,int s,vector<bool> visited,int t){
    if(t >= line.length()) return false;
    else{
        if(visited[s])return false;
        visited[s] = true;
        // cout << t << " " << node[s] << " - " << line[t] << endl;
        if(node[s] != line[t])return false;
        if(t == line.length() - 1 && node[s] == line[t])return true;
        for(int i = 0;i < adjList[s].size();++i){
            if(DFS(adjList,node,line,adjList[s][i],visited,t+1))return true;
        }
        
    }
    return false;
}

bool search(vector<vector<int> > &adjList,vector<char> &node,string &line){
    for(int i = 0;i < adjList.size();++i){
        vector<bool> visited(adjList.size(),0);
        if(DFS(adjList,node,line,i,visited,0))return true;
    }
    return false;
}
int main(){

    int w,h;
    cin >> w >> h;
    
    int n = h * w;
    vector<char> node(n);
    vector<vector<int> > adjList(n);


    string line;
    int i = 0;
    while(i < h && cin >> line){
        for(int j = 0;j < w;++j){
            int k = i*w+j;
            node[k] = line[j];
            //othogonal
            if(i-1 >= 0 && j-1 >= 0){
                int oLoc = (i-1) * w + j-1;
                addNode(adjList,k,oLoc);
            }
            //invert othogonal
            if(i-1 >= 0 && j+1 < w){
                int oiLoc = (i-1) * w + j+1;
                addNode(adjList,k,oiLoc);
            }
            //up
            if(i-1 >= 0){
                int uLoc = (i-1) * w + j;
                addNode(adjList,k,uLoc);
            }
            //left
            if(j-1 >= 0){
                int lLoc = i * w + j-1;
                addNode(adjList,k,lLoc);
            }
            //right
            if(j+1 < w){
                int rLoc = i * w + j+1;
                addNode(adjList,k,rLoc);

            }


        }

        ++i;

    }

    while(cin >> line){
        bool result = search(adjList,node,line);
        cout << (result ? "EXIST" : "NOT EXIST") << endl; 
    }
    // cin >> line;
    // bool result = search(adjList,node,line);
    // cout << line << " : " << result << endl; 

    // for(int i = 0;i < n;++i){
    //     cout << i << " (" << node[i] << ") : ";
    //     for(int j =0;j < adjList[i].size();++j){
    //         cout << adjList[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    


    




    return 0;
}