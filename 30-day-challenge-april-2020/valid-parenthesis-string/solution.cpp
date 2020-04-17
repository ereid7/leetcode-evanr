// https://leetcode.com/problems/valid-parenthesis-string/

// greedy solution
// O(n)
class Solution {
public:
    bool checkValidString(string s) {
        int low = 0;
        int high = 0;
        for (char c: s) {
            if (c == '(') {
                low++; 
                high++;
            } 
            else if (c == ')') {
                if (low > 0) {
                    low--;
                }
                high--;
            } 
            else {
                if (low > 0) {
                    low--;
                }
                high++;
            }
            if (high < 0) return false;
        }
        return low == 0;
    }
};

// simpler greedy solution
class Solution {
public:
    bool checkValidString(string s) {
       int lo = 0; 
       int hi = 0;
       for (char c: s) {
           lo += c == '(' ? 1 : -1;
           hi += c != ')' ? 1 : -1;
           if (hi < 0) break;
           lo = max(lo, 0);
       }
       return lo == 0;
    }
};

// stack solution
// O(n)
class Solution {
public:
    bool checkValidString(string s) {
        stack<int> p, star;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '*') {
                star.push(i);
            }
            else if (s[i] == '(') {
                p.push(i);
            } 
            else {
                if (p.empty() && star.empty()) {
                    return false;
                }
                
                if (!p.empty()) {
                    p.pop();
                }
                else star.pop();
            }
        }
        
        while (!p.empty() && !star.empty()) {
            if (p.top() > star.top()) {
                return false;
            }
            p.pop();
            star.pop();
        }
        
        return p.empty();
    }
};