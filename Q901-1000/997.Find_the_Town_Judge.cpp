class Solution {
public:
    int findJudge(int n, vector<vector<int>> trust) {
        if (trust.size() == 0 && n == 1) 
            return 1;
        vector<int> count(n + 1);
        for (auto x : trust) {
            count[x[0]]--;
            count[x[1]]++;
        }
        for (int x = 0; x < count.size(); x++) {
            if (count[x] == n - 1) return x;
        }
        return -1;
    }
};