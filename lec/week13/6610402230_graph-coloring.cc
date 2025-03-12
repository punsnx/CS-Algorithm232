// 6610402230 ศิริสุข ทานธรรม
#include <iostream>
#include <vector>
using namespace std;

class Map{
public:
    vector<vector<int> > adjList;
    vector<int> mapColors;
    vector<int> colors;
    Map(int n){
        adjList = vector<vector<int> >(n);
        mapColors = vector<int> (n,-1);//-1 NO COLOR
    }

    void addEdge(int s,int d){
        int n = adjList.size();
        if(s < 0 || s >= n)return;
        if(d < 0 || d >= n)return;

        adjList[s].push_back(d);
        // adjList[d].push_back(s); 
    }

    void setupColor(int n){
        colors = vector<int>(n);
        for(int i = 0;i<n;++i){
            colors[i] = i;
        }
        mapColors = vector<int> (adjList.size(),-1);
        
    }

    void printMap(){
        for(int i = 0;i<adjList.size();++i){
            cout << i << " (Color " << mapColors[i] << ") : ";
            int adjSize = adjList[i].size();
            for(int j = 0;j<adjSize;++j){
                cout << adjList[i][j] << " -> ";
            }
            cout << (adjSize ? "NULL" : "-> NULL") << endl;
        }
    }

    bool okToColor(int country,int color){
        for(int i = 0;i < adjList[country].size();++i){
            int adjCountry = adjList[country][i];
            if(mapColors[adjCountry] == color){
                return false;
            }
        }
        return true;
        
    }

    bool explore(int country,int color){
        if(country >= adjList.size())return true;
        if(okToColor(country,color)){
            mapColors[country] = color;
            for(int i = 0; i < colors.size();++i){
                if(explore(country+1,i))return true;
            }

        }
        return false;
        
    }



};


int main(){
    Map m = Map(7);
    m.addEdge(0,1);
    m.addEdge(0,4);
    m.addEdge(0,2);
    m.addEdge(0,5);

    m.addEdge(1,0);
    m.addEdge(1,4);
    m.addEdge(1,6);
    m.addEdge(1,5);

    m.addEdge(2,0);
    m.addEdge(2,4);
    m.addEdge(2,3);
    m.addEdge(2,6);
    m.addEdge(2,5);

    m.addEdge(3,2);
    m.addEdge(3,4);
    m.addEdge(3,6);

    m.addEdge(4,0);
    m.addEdge(4,1);
    m.addEdge(4,6);
    m.addEdge(4,3);
    m.addEdge(4,2);

    m.addEdge(5,2);
    m.addEdge(5,6);
    m.addEdge(5,1);
    m.addEdge(5,0);

    m.addEdge(6,2);
    m.addEdge(6,3);
    m.addEdge(6,4);
    m.addEdge(6,1);
    m.addEdge(6,5);

    m.setupColor(4);//RED YELLOW GREEN BLUE 
    bool result = m.explore(0,0);
    cout << "Result : " << result << endl;
    m.printMap();
    return 0;
}

