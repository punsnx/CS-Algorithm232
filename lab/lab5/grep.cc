// pass
#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool match(string &line, string &reg, int lpos, int rpos) {
    if (rpos == reg.length()) return true;
    if (lpos == line.length()) {
        if (rpos + 1 < reg.length() && reg[rpos + 1] == '*')
            return match(line, reg, lpos, rpos + 2);
        return false;
    }

    char p = reg[rpos];

    if (rpos + 1 < reg.length() && reg[rpos + 1] == '*') {
        if (match(line, reg, lpos, rpos + 2)) return true;  
        if (p == '.' || p == line[lpos]) {
            if (match(line, reg, lpos + 1, rpos)) return true;  
        }
        return false;
    }

    if (p == '.' || p == line[lpos]) {
        return match(line, reg, lpos + 1, rpos + 1);
    }

    return false;
}

bool find_pattern(string &line, string &reg) {
    for (int i = 0; i <= line.length(); i++) {
        if (match(line, reg, i, 0)) return true;
    }
    return false;
}

int main() {
    vector<string> lines, patterns;
    string line;

    while (getline(cin, line)) {
        if (line == "---") break;
        lines.push_back(line);
    }
    while (getline(cin, line)) {
        if (line == "---") break;
        patterns.push_back(line);
    }

    for (string &pattern : patterns) {
        bool found = false;
        vector<int> matching_lines;

        for (int i = 0; i < lines.size(); i++) {
            if (find_pattern(lines[i], pattern)) {
                matching_lines.push_back(i + 1);
                found = true;
            }
        }

        if (!found) {
            cout << "-";
        } else {
            for (int i = 0; i < matching_lines.size(); i++) {
                if (i > 0) cout << " ";
                cout << matching_lines[i];
            }
        }
        cout << endl;
    }

    return 0;
}