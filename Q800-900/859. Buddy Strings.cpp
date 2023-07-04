class Solution {
public:
    bool buddyStrings(string s, string goal) {
        int first = -1; 
        int second = -1; 
        int count = 0;

        if (s.size() != goal.size()) {
            return false;
        }

        for (int i = 0; i < s.size(); i++) {
            if (s[i] != goal[i]) {
                if (count == 0) {
                    first = i;
                    count++;
                } else if (count == 1) {
                    second = i;
                    count++;
                } else {
                    return false;
                }
            }
        }

        if (count == 0) {
            unordered_set<char> uniqueChars(s.begin(), s.end());
            return uniqueChars.size() < s.size();
        }

        if (count == 2) {
            swap(s[first], s[second]);
            return s == goal;
        }

        return false;
    }
};