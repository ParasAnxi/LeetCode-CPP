class Solution {
public:
  int solve(vector<long long> &vP, int s, int e, int low, int up) {
    if (s >= e)
      return 0;
    int mid = s + (e - s) / 2;
    int count = solve(vP, s, mid, low, up) + solve(vP, mid + 1, e, low, up);
    int i = s;
    int j = mid + 1;
    int k = mid + 1;
    while (i <= mid) {
      while (j <= e && vP[j] - vP[i] < low)
        j++;
      while (k <= e && vP[k] - vP[i] <= up)
        k++;
      count += k - j;
      i++;
    }
    vector<long long> v;
    i = s, j = mid + 1;
    while (i <= mid && j <= e) {
      if (vP[i] <= vP[j]) {
        v.push_back(vP[i++]);
      } else {
        v.push_back(vP[j++]);
      }
    }
    while (i <= mid)
      v.push_back(vP[i++]);
    while (j <= e)
      v.push_back(vP[j++]);
    for (int idx = 0; idx < v.size(); ++idx) {
      vP[s + idx] = v[idx];
    }

    return count;
  }
  int countRangeSum(vector<int> &nums, int lower, int upper) {
    int n = nums.size();
    vector<long long> vP(n + 1, 0);
    for (int i = 0; i < n; i++) {
      vP[i + 1] = vP[i] + nums[i];
    }
    return solve(vP, 0, n, lower, upper);
  }
};