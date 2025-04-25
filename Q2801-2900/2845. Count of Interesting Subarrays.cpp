class Solution {
public:
  using ll = long long;
  long long countInterestingSubarrays(vector<int> &nums, int modulo, int k) {
    int n = nums.size();
    unordered_map<ll, ll> mp;
    ll count = 0;
    ll ans = 0;
    for (int i = 0; i < n; i++) {
      if (nums[i] % modulo == k)
        count++;
      ll x = count % modulo;
      if (x == k)
        ans++;
      ll md = (count - k + modulo) % modulo;
      ans += mp[md];
      mp[x]++;
    }
    return ans;
  }
};