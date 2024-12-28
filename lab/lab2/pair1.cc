#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>
using namespace std;

struct Coordinate {
    double x, y;
};

void merge(vector<Coordinate>& arr, int left, int mid, int right, bool byX) {
    vector<Coordinate> L(arr.begin() + left, arr.begin() + mid + 1);
    vector<Coordinate> R(arr.begin() + mid + 1, arr.begin() + right + 1);
    
    int i = 0, j = 0, k = left;
    while (i < L.size() && j < R.size()) {
        if (byX ? (L[i].x <= R[j].x) : (L[i].y >= R[j].y)) {
            arr[k] = L[i++];
        } else {
            arr[k] = R[j++];
        }
        k++;
    }
    
    while (i < L.size()) arr[k++] = L[i++];
    while (j < R.size()) arr[k++] = R[j++];
}

void mergeSort(vector<Coordinate>& arr, int left, int right, bool byX) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid, byX);
        mergeSort(arr, mid + 1, right, byX);
        merge(arr, left, mid, right, byX);
    }
}

// Euclidean distance
double dist(const Coordinate& p1, const Coordinate& p2) {
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

double closestPair(vector<Coordinate>& points) {
    if (points.size() == 2) return dist(points[0], points[1]);
    if (points.size() == 1) return INFINITY;

    mergeSort(points, 0, points.size()-1, true);
    
    int mid = points.size()/2;
    double L = points[mid].x; 
    
    vector<Coordinate> left(points.begin(), points.begin() + mid);
    vector<Coordinate> right(points.begin() + mid, points.end());
    
    double d = min(closestPair(left), closestPair(right));
    
    vector<Coordinate> strip;
    for (const Coordinate& p : points) {
        if (abs(p.x - L) < d) strip.push_back(p);
    }
    
    mergeSort(strip, 0, strip.size()-1, false);
    
    for (int i = 0; i < strip.size(); i++) {
        for (int j = 1; j <= min(15, (int)strip.size()-i-1); j++) {
            d = min(d, dist(strip[i], strip[i+j]));
        }
    }
    
    return d;
}

int main() {
    int t;
    cin >> t;  
    
    while (t--) {
        int n;
        cin >> n;  
        cin.ignore();
    
        vector<Coordinate> points(n);
        for (Coordinate &p : points) {
            scanf("(%lf, %lf)", &p.x, &p.y);
            cin.ignore();
        }
        
        cout << fixed << setprecision(6) << closestPair(points) << endl;
    }
    return 0;
}