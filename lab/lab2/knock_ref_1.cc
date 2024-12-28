#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

// Function to compute NPV for a given IRR
double computeNPV(const vector<int>& cashFlows, double irr) {
    double npv = 0.0;
    for (int i = 0; i < cashFlows.size(); ++i) {
        npv += cashFlows[i] / pow(1 + irr, i);
    }
    return npv;
}

// Bisection method to find IRR
double findIRR(const vector<int>& cashFlows, double tolerance = 1e-6) {
    double a = -0.99; // Starting lower bound (IRR > -1)
    double b = 1.0;   // Starting upper bound
    double c;         // Midpoint
    while (b - a > tolerance) {
        c = (a + b) / 2;
        double npv = computeNPV(cashFlows, c);
        
        if (abs(npv) < tolerance) {
            return c; // Close enough to root
        }
        if (computeNPV(cashFlows, a) * npv < 0) {
            b = c;
        } else {
            a = c;
        }
    }
    return (a + b) / 2;
}

int main() {
    while (true) {
        int n;
        cin >> n;
        if (n == 0) break; // Exit condition

        vector<int> cashFlows(n + 1);
        for (int i = 0; i <= n; ++i) {
            cin >> cashFlows[i];
        }

        // Calculate IRR
        double irr = findIRR(cashFlows);

        // Print IRR to 2 decimal places
        cout << fixed << setprecision(2) << irr << endl;
    }
    return 0;
}