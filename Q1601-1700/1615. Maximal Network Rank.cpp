class Solution{
public:
    int maximalNetworkRank(int n, vector<vector<int>> &roads){
        int res = 0;
        vector<int> count(n, 0);
        unordered_map<int, int> umap;
        for (int i = 0; i < roads.size(); ++i)
        {
            int a = roads[i][0], b = roads[i][1];
            ++count[a];
            ++count[b];
            ++umap[index(a, b, n)];
        }
        vector<int> v(n);
        iota(v.begin(), v.end(), 0);
        sort(v.begin(), v.end(), [&](int i, int j)
             { return count[i] > count[j]; });
        int second = 0;
        for (int i = 0; i < n; ++i){
            int i1 = v[i];
            if (second > count[i1])
                break;
            for (int j = i + 1; j < n; ++j){
                int j1 = v[j];
                int rank = count[i1] + count[j1];
                if (umap.find(index(i1, j1, n)) == umap.end()){
                    res = max(res, rank);
                }
                else{
                    res = max(res, rank - 1);
                }
                if (second == 0){
                    second = count[j1];
                }
                else{
                    if (second > count[j1])
                        break;
                }
            }
        }
        return res;
    }
    int index(int i, int j, int n){
        if (i < j)
            return i * n + j;
        return j * n + i;
    }
};