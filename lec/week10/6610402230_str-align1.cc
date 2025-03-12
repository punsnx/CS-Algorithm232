//6610402230 ศิริสุข ทานธรรม
#include <iostream>
using namespace std;

int score(char a, char b) {
    return (a == b ? 2 : -1);
}

int max(int a,int b){
    return (a > b ? a : b);
}

void align(string &s1, string &s2) {
    int VR = s1.length() + 1;
    int VC = s2.length() + 1;
    int V[VR][VC];
    int trace[VR][VC]; // 0: diagonal, 1: up, 2: left

    for (int i = 0; i < VR; ++i) {
        for (int j = 0; j < VC; ++j) {
            if (!i && !j) { 
                V[i][j] = 0;//no score match 2-empty string
            } else if (!i) {
                V[i][j] = V[i][j - 1] + score(0, s2[j - 1]); //insert spaces B[j...] 
                trace[i][j] = 2; 
            } else if (!j) { 
                V[i][j] = V[i - 1][j] + score(s1[i - 1], 0); //delete sub-string A[i...]
                trace[i][j] = 1;
            } else {
                int o1 = V[i - 1][j - 1] + score(s1[i - 1], s2[j - 1]); //score match Ai,Bj
                int o2 = V[i - 1][j] + score(s1[i - 1], 0); //delete Ai
                int o3 = V[i][j - 1] + score(0, s2[j - 1]); //insert Bj

                V[i][j] = max(o1,max(o2,o3));
                trace[i][j] = (V[i][j] == o1) ? 0 : (V[i][j] == o2) ? 1 : 2;
            }
            cout << V[i][j] << " ";
        }
        cout << endl;
    }

    string res1 = "", res2 = "";
    int i = VR - 1, j = VC - 1;

    while (i || j) {
        if (i && j && trace[i][j] == 0) {
            res1 = s1[i - 1] + res1;
            res2 = s2[j - 1] + res2;
            --i, --j;
        } else if (i && trace[i][j] == 1) {
            res1 = s1[i - 1] + res1;
            res2 = "_" + res2;
            --i;
        } else {
            res1 = "_" + res1;
            res2 = s2[j - 1] + res2;
            --j;
        }
    }

    cout << "\n" << res1 << "\n" << res2 << "\n";
}

int main() {
    string A = "ACAATCC";
    string B = "AGCATGC";

    align(A, B);

    return 0;
}