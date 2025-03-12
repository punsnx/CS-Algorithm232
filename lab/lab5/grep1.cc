#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool match_pattern(string& line, string& pattern, int line_pos, int pattern_pos) {
    if (pattern_pos == pattern.length()) return true;
    if (line_pos == line.length()) return false;
    
    char p = pattern[pattern_pos];
    
    if (pattern_pos + 1 < pattern.length() && pattern[pattern_pos + 1] == '*') {
        if (match_pattern(line, pattern, line_pos, pattern_pos + 2)) return true;    
        if (p == '.' || p == line[line_pos]) {
            if (match_pattern(line, pattern, line_pos + 1, pattern_pos)) return true;
        }
        return false;
    }
    
    if (p == '.' || p == line[line_pos]) {
        return match_pattern(line, pattern, line_pos + 1, pattern_pos + 1);
    }
    
    return false;
}

bool find_pattern(string& line, string& pattern) {
    for (int i = 0; i <= line.length(); i++) {
        if (match_pattern(line, pattern, i, 0)) return true;
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
    
    for (string& pattern : patterns) {
        bool found = false;
        vector<int> matching_lines;
        
        for (int i = 0; i < lines.size(); i++) {
            if (find_pattern(lines[i], pattern)) {
                found = true;
                matching_lines.push_back(i + 1);
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