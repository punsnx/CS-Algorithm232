#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool match_pattern(string& line, string& pattern, int line_pos, int pattern_pos) {
    if (pattern_pos >= pattern.length()) return line_pos >= line.length();
    
    bool first_match = (line_pos < line.length() && 
                       (pattern[pattern_pos] == line[line_pos] || 
                        pattern[pattern_pos] == '.'));
                        
    if (pattern_pos + 1 < pattern.length() && pattern[pattern_pos + 1] == '*') {
        return match_pattern(line, pattern, line_pos, pattern_pos + 2) || 
               (first_match && match_pattern(line, pattern, line_pos + 1, pattern_pos));
    }
    
    return first_match && match_pattern(line, pattern, line_pos + 1, pattern_pos + 1);
}

bool find_pattern(string& line, string& pattern) {
    return match_pattern(line, pattern, 0, 0);
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
            string current_line = lines[i];
            for (int j = 0; j < current_line.length(); j++) {
                string substring = current_line.substr(j);
                if (find_pattern(substring, pattern)) {
                    found = true;
                    matching_lines.push_back(i + 1);
                    break;
                }
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