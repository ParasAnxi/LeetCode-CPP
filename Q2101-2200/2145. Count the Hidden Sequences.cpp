using ll = long long;
class Solution {
public:
  int numberOfArrays(vector<int> &differences, int lower, int upper) {
    ll mini = INT_MAX;
    ll maxi = INT_MIN;
    ll sum = 0;
    for (auto i : differences) {
      sum += i;
      mini = min(mini, sum);
      maxi = max(maxi, sum);
    }

    ll ans = upper - lower + 1;
    if (mini < 0) {
      ans = max(0LL, ans + mini);
    }
    if (maxi > 0) {
      ans = max(0LL, ans - maxi);
    }
    return (int)ans;
  }
};