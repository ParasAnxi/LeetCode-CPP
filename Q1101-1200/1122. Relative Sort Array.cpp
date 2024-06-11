class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int, int> mp;
        vector<int> ans;
        
        for (int num : arr1) {
            mp[num]++;
        }
        
        for (int num : arr2) {
            if (mp.find(num) != mp.end()) {
                while (mp[num] > 0) {
                    ans.push_back(num);
                    mp[num]--;
                }
                mp.erase(num);
            }
        }
        vector<int> res;
        for (auto& pair : mp) {
            while (pair.second > 0) {
                res.push_back(pair.first);
                pair.second--;
            }
        }
        
        sort(res.begin(), res.end());
        ans.insert(ans.end(), res.begin(), res.end());
        
        return ans;
    }
};