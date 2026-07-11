class Solution {
public:
    bool rotateString(string s, string goal) {
        // Lengths must be equal
        if (s.length() != goal.length()) 
            return false;
        
        // Check if goal is substring of s+s
        string doubled = s + s;
        
        return doubled.contains(goal);
    }
};