class Solution {
public:
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        if(arr1.size() == 1) 
            return 0;
        sort(arr2.begin(), arr2.end());
        
        unordered_map<int, int> mp;
        mp[0] = arr1[0];
        mp[1] = *arr2.begin();
        
        for(int i=1; i<arr1.size(); ++i) {
            unordered_map<int, int> next_mp;
            for(auto& [moves, val] : mp) {
                if(arr1[i] > val) {
                    if(next_mp.count(moves)) next_mp[moves] = min(next_mp[moves], arr1[i]);
                    else next_mp[moves] = arr1[i];
                }                 
                auto it = upper_bound(arr2.begin(), arr2.end(), val);
                if(it == arr2.end()) continue;
                if(!next_mp.count(moves+1)) next_mp[moves+1] = *it;
                else next_mp[moves+1] = min(next_mp[moves+1], *it);
                
            }
            mp = next_mp;
            if(mp.empty()) 
                return -1;
        }
        int ans = INT_MAX;
        for(auto& [k, v]: mp) {
            ans = min(ans, k);
        }
        return ans;
    }
};