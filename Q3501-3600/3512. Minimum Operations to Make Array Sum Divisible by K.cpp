#define ll long long
class Solution {
public:
  int minOperations(vector<int> &nums, int k) {
    ll sum = accumulate(nums.begin(), nums.end(), 0LL);
    int rem = sum % k;
    return rem == 0 ? 0 : rem;
  }
};