class Solution {
public:
    int ways(vector<string>& pizza, int k) {
        vector<vector<vector<int> > > dp(k, vector<vector<int> >(pizza.size(), vector<int>(pizza[0].size(), 0)));
        for (int i = 0; i < pizza.size(); ++i) {
            for (int j = 0; j < pizza[0].size(); ++j) {
                dp[0][i][j] = 1;
            }
        }
        vector<vector<int> > appleNum(pizza.size() + 1, vector<int>(pizza[0].size() + 1, 0));
        for (int i = pizza.size() - 1; i >= 0; --i) {
            for (int j = pizza[0].size() - 1; j >= 0; --j) {
                appleNum[i][j] = (int)(pizza[i][j] == 'A') + appleNum[i + 1][j] + appleNum[i][j + 1] - appleNum[i + 1][j + 1];
            }
        }
        for (int k = 1; k < dp.size(); ++k) {
            for (int i = 0; i < dp[0].size(); ++i) {
                for (int j = 0; j < dp[0][0].size(); ++j) {
                    for (int row = i + 1; row < dp[0].size(); ++row) {
                        if (appleNum[i][j] - appleNum[row][j] < 1 || appleNum[row][j] < k)
                            continue;
                        dp[k][i][j] = (dp[k][i][j] + dp[k - 1][row][j]) % (int)(1e9 + 7);
                    }
                    for (int col = j + 1; col < appleNum[0].size() - 1; ++col) {
                        if (appleNum[i][j] - appleNum[i][col] < 1 || appleNum[i][col] < k)
                            continue;
                        dp[k][i][j] = (dp[k][i][j] + dp[k - 1][i][col]) % (int)(1e9 + 7);
                    }
                }
            }
        }
        return dp[k - 1][0][0] % (int)(1e9 + 7);
    }
};