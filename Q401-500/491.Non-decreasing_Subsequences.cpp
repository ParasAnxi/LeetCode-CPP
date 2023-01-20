class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& n) {
        set<vector<int>> result;
        
        for(int a : n) {
            auto c = result;
            for(auto sequence : c) {
                if(sequence.back() <= a) {
                    sequence.emplace_back(a);
                    result.insert(sequence);
                }
            }
            result.insert({a});
        }
        
        vector<vector<int>> ans;
        for(auto &sequence : result) {
            if(sequence.size() >= 2) ans.push_back(sequence);
        }

        return ans;
    }
};