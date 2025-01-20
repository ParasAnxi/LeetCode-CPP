class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        vector <int> rows(mat.size(), 0);
        vector <int> cols(mat[0].size(), 0);

        unordered_map < int, pair<int, int>> mp;
        int n = mat.size();
        int m = mat[0].size();
        for (int i = 0 ; i < n ; i++) {
            for (int j = 0 ; j < m ; j++) {
                mp[mat[i][j]] = make_pair(i, j);
            }
        }

        for (int i = 0 ; i < arr.size() ; i++) {
            auto x = mp[arr[i]];
            rows[x.first]++;
            cols[x.second]++;
            if (rows[x.first] == m)
                return i;
            if (cols[x.second] == n)
                return i;
        }

        return 0;
    }
};