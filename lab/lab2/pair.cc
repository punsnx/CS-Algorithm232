#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>
#include <climits>
using namespace std;


typedef struct _Point{
    float x;
    float y;
}Point;


// Euclidean distance
float dist(Point &p1,Point &p2){
    return sqrt(pow(p1.x - p2.x,2)+pow(p1.y - p2.y,2));
}
float minof(float x,float y){
    return (x < y ? x : y);
}


//combine step
void merge(vector<Point> &arr,int l,int m,int r,bool sortByX){
    vector<Point> L(arr.begin() + l,arr.begin() + m + 1);
    vector<Point> R(arr.begin() + m  + 1,arr.begin() + r + 1);

    int i = 0, j = 0, k = l;
    while (i < L.size() && j < R.size()) {
        if (sortByX ? (L[i].x <= R[j].x) : (L[i].y >= R[j].y)) {
            arr[k] = L[i++];
        } else {
            arr[k] = R[j++];
        }
        k++;
    }
    
    while (i < L.size()) arr[k++] = L[i++];
    while (j < R.size()) arr[k++] = R[j++];

}
//devide step
void mergeSort(vector<Point> &arr,int l,int r,bool sortByX){
    if(l < r){
        int m = (l+r)/2;
        mergeSort(arr,l,m,sortByX);
        mergeSort(arr,m+1,r,sortByX);
        merge(arr,l,m,r,sortByX);
    }
}

float closestPair(vector<Point> &points){
    if(points.size()==2)return dist(points[0],points[1]);
    if(points.size()==1)return INT_MAX;
    //must sort points by x
    mergeSort(points,0,points.size()-1,true);

    int mid = points.size()/2;
    float L = points[mid].x;
    vector<Point> left(points.begin(), points.begin() + mid);
    vector<Point> right(points.begin() + mid, points.end());
    float d1 = closestPair(left);
    float d2 = closestPair(right);
    float d = minof(d1,d2);
    //S vector store points within d from the middle L
    vector<Point> S;
    for(Point &p : points){
        if(abs(p.x - L) < d) S.push_back(p);
    }
    //must sort points by y
    mergeSort(S,0,S.size()-1,false);

    //find min dist with in d from middle L
    for(int i = 0;i< S.size();++i){
        for(int j = 1;j<=minof(15,S.size()-1-i);++j){
            d = minof(d,dist(S[i],S[i+j]));
        }
    }
    return d;

}



int main(){
    int t;
    cin >> t;
    for(int i = 0;i<t;i++){
        int n;cin >> n;
        cin.ignore();
        vector<Point> points(n);
        for (Point &p : points) {
            scanf("(%f, %f)", &p.x, &p.y);
            cin.ignore();
        }
        cout << fixed << setprecision(6) << closestPair(points) << endl;


    }


    return 0;
}