class Solution {
public:
  long long countGood(vector<int> &nums, int k) {
    int n = nums.size();
    unordered_map<int, int> mp;
    int s = 0;
    int e = -1;
    long long ans = 0LL;
    for (int i = 0; i < n; i++) {
      while (s < k && e + 1 < n) {
        e++;
        s += mp[nums[e]];
        mp[nums[e]]++;
      }
      if (s >= k) {
        ans += n - e;
      }
      mp[nums[i]]--;
      s -= mp[nums[i]];
    }
    return ans;
  }
};