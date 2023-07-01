class Solution {
public:
    int distributeCookies(vector<int>& cookies, int k) {
        vector<int> distributor(k, 0);
        solve<int(int, int)> go = [&](auto i, auto maxi) {
            if (i == cookies.size())
             return maxi;
            int res = INT_MAX;
            for (auto &d: distributor) 
                d += cookies[i],
                res = min(res, go(i + 1, max(maxi, d))),
                d -= cookies[i];
            return res;
        };
        return go(0, 0);
    }
};