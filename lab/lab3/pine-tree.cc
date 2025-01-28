#include <iostream>
#include <cmath>
using namespace std;

struct Sprinkler {
    double x, r;
};

void merge(double ranges[][2], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    double leftHalf[n1][2], rightHalf[n2][2];

    for (int i = 0; i < n1; i++) {
        leftHalf[i][0] = ranges[left + i][0];
        leftHalf[i][1] = ranges[left + i][1];
    }
    for (int i = 0; i < n2; i++) {
        rightHalf[i][0] = ranges[mid + 1 + i][0];
        rightHalf[i][1] = ranges[mid + 1 + i][1];
    }

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (leftHalf[i][0] <= rightHalf[j][0]) {
            ranges[k][0] = leftHalf[i][0];
            ranges[k][1] = leftHalf[i][1];
            i++;
        } else {
            ranges[k][0] = rightHalf[j][0];
            ranges[k][1] = rightHalf[j][1];
            j++;
        }
        k++;
    }

    while (i < n1) {
        ranges[k][0] = leftHalf[i][0];
        ranges[k][1] = leftHalf[i][1];
        i++;
        k++;
    }

    while (j < n2) {
        ranges[k][0] = rightHalf[j][0];
        ranges[k][1] = rightHalf[j][1];
        j++;
        k++;
    }
}

void mergeSort(double ranges[][2], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(ranges, left, mid);
        mergeSort(ranges, mid + 1, right);
        merge(ranges, left, mid, right);
    }
}

int minimumSprinklers(double l, double w, int n, Sprinkler sprinklers[]) {
    double ranges[n][2];
    int rangeCount = 0;
    double halfWidth = w / 2.0;

    for (int i = 0; i < n; i++) {
        if (sprinklers[i].r > halfWidth) {
            double reach = sqrt(sprinklers[i].r * sprinklers[i].r - halfWidth * halfWidth);
            ranges[rangeCount][0] = sprinklers[i].x - reach;
            ranges[rangeCount][1] = sprinklers[i].x + reach;
            rangeCount++;
        }
    }

    mergeSort(ranges, 0, rangeCount - 1);

    double covered = 0;
    int count = 0;
    int i = 0;

    while (covered < l) {
        double maxReach = covered;
        while (i < rangeCount && ranges[i][0] <= covered) {
            if (ranges[i][1] > maxReach) {
                maxReach = ranges[i][1];
            }
            i++;
        }

        if (maxReach == covered) {
            return -1;
        }

        covered = maxReach;
        count++;
    }

    return count;
}

int main() {
    double l, w;
    int n;

    while (cin >> l >> w) {
        cin >> n;

        Sprinkler sprinklers[n];
        for (int i = 0; i < n; i++) {
            cin >> sprinklers[i].x >> sprinklers[i].r;
        }

        int result = minimumSprinklers(l, w, n, sprinklers);
        cout << result << endl;
    }

    return 0;
}