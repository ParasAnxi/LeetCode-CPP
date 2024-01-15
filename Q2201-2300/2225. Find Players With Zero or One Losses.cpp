class Solution
{
public:
    vector<vector<int>> findWinners(vector<vector<int>> &matches)
    {
        unordered_map<int, int> win;
        unordered_map<int, int> lose;
        for (int i = 0; i < matches.size(); i++){
            lose[matches[i][1]]++;
            win[matches[i][0]]++;
        }
        vector<vector<int>> ans(2);
        for (auto it = lose.begin(); it != lose.end(); it++){
            if ((*it).second == 0 || (*it).second == 1){
                ans[(*it).second].push_back((*it).first);
            }
        }
        for (auto it = win.begin(); it != win.end(); it++){
            if (lose.count((*it).first) < 1) {
                ans[0].push_back((*it).first);
            }
        }
        sort(ans[0].begin(), ans[0].end());
        sort(ans[1].begin(), ans[1].end());
        return ans;
    }
};