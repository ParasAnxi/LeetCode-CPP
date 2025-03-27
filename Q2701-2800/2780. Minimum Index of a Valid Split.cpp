class Solution{
public:
    int minimumIndex(vector<int> &nums){
        int n = nums.size();
        unordered_map<int, int> mp;
        for (auto &i : nums){
            mp[i]++;
        }
        int x = 0, y = 0;
        for (auto &i : mp){
            if (i.second > y){
                y = i.second;
                x = i.first;
            }
        }
        unordered_map<int, int> mp2;
        for (int i = 0; i < n; i++){
            mp2[nums[i]]++;
            mp[nums[i]]--;
            if ((mp2[x] * 2) > i + 1 && (mp[x] * 2) > n - 1 - i){
                return i;
            }
        }
        return -1;
    }
};