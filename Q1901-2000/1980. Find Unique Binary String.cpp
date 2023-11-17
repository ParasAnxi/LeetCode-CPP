class Solution{
public:
    string solve(int i){
        string ans;
        while (i != 1){
            if (i & 1){
                ans.push_back('1');
                i = (i | 0) >> 1;
            }
            else{
                ans.push_back('0');
                i = i >> 1;
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
    string findDifferentBinaryString(vector<string> &nums){
        int h = nums[0].size();
        int n = pow(2, h + 1);
        vector<int> tree(n, 0);
        for (string &s : nums){
            int root = 1;
            for (auto &c : s){
                if (c == '0'){
                    root = root << 1;
                }
                else{
                    root = root << 1 | 1;
                }
            }
            tree[root] = 1;
        }
        int l = n / 2;
        for (int i = l; i < n; i++){
            if (tree[i] == 0)
                return solve(i);
        }
        return "";
    }
};