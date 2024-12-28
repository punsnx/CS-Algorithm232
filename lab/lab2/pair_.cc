#include <iostream>
#include <iomanip>
using namespace std;


typedef struct _Coordinate{
    double x;
    double y;
}Coordinate;


double pairDistance(Coordinate *p,int i,int j){
    return sqrt((pow(abs(p[i].x - p[j].x),2) + pow(abs(p[i].y - p[j].y),2)));
}
double closestPair(Coordinate *p,int n){
    double closest = INFINITY;
    for(int i = 0;i<n;++i){
        for(int j = 0;j<n;++j){
            if(i != j){
                double distance = pairDistance(p,i,j);
                // cout << distance << endl;
                if(distance < closest)closest = distance;

            }
        }   
    }
    return closest;
}
int main(){
    int t;
    cin >> t;
    for(int i = 0;i<t;i++){
        int n;
        cin >> n;
        cin.ignore();
        Coordinate pair[n];
        // double minX=INFINITY,minY=INFINITY,maxX=-INFINITY,maxY=-INFINITY;
        for(int j=0;j<n;j++){
            scanf("(%lf, %lf)",&pair[j].x,&pair[j].y);
            cin.ignore();
            // if(pair[j].x < minX)minX = pair[j].x;
            // if(pair[j].x > maxX)maxX = pair[j].x;
            // if(pair[j].y < minY)minY = pair[j].y;
            // if(pair[j].y > maxY)maxY = pair[j].y;
        }
        cout << fixed << setprecision(6) << closestPair(pair,n) << endl;


    }


    return 0;
}