#include <iostream>
using namespace std;

struct Elf {
    int time;
    int cost;
};

void merge(Elf elves[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    Elf L[n1], R[n2];

    for (int i = 0; i < n1; i++) {
        L[i] = elves[left + i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = elves[mid + 1 + j];
    }

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        double ratioLeft = (double)L[i].cost/L[i].time;
        double ratioRight = (double)R[j].cost/R[j].time;

        if (ratioLeft > ratioRight) { 
            elves[k++] = L[i++];
        } else {
            elves[k++] = R[j++];
        }
    }

    while (i < n1) elves[k++] = L[i++];
    while (j < n2) elves[k++] = R[j++];
}

void mergeSort(Elf elves[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(elves, left, mid);
        mergeSort(elves, mid + 1, right);
        merge(elves, left, mid, right);
    }
}

int main() {
    int n;
    cin >> n;

    Elf elves[n];
    for (int i = 0; i < n; i++) {
        cin >> elves[i].time >> elves[i].cost;
    }

    mergeSort(elves, 0, n - 1);

    int totalTime = 0;
    long long totalCost = 0;

    for (int i = 0; i < n; i++) {
        totalCost += elves[i].cost * totalTime;
        totalTime += elves[i].time;
    }

    cout << totalCost << endl;

    return 0;
}