#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

// Function to calculate NPV for a given IRR
double calculateNPV(const vector<int>& cashFlows, double irr) {
    double npv = 0.0;
    for (size_t i = 0; i < cashFlows.size(); ++i) {
        npv += cashFlows[i] / pow(1 + irr, i);
    }
    return npv;
}

// Function to find IRR using the Bisection Method
double findIRR(const vector<int>& cashFlows) {
    double low = -0.99, high = 10000.0, mid;
    while (high - low > 1e-7) { // Precision up to 2 decimal points
        mid = (low + high) / 2;
        double npv = calculateNPV(cashFlows, mid);
        if (npv > 0) {
            low = mid;
        } else {
            high = mid;
        }
    }
    return mid;
}

int main() {
    while (true) {
        int n;
        cin >> n;

        if (n == 0) break;

        vector<int> cashFlows(n + 1);
        for (int i = 0; i <= n; ++i) {
            cin >> cashFlows[i];
        }

        // Find IRR and print with 2 decimal precision
        double irr = findIRR(cashFlows);
        cout << fixed << setprecision(2) << irr << endl;
    }

    return 0;
}