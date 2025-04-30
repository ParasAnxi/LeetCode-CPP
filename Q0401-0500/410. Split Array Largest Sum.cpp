class Solution {
public:
  bool isPossible(int mid, vector<int> &nums, int k) {
    int currS = 0;
    int x = 1;
    for (int i : nums) {
      if (currS + i > mid) {
        x++;
        currS = i;
        if (x > k)
          return 0;
      } else {
        currS += i;
      }
    }
    return 1;
  }
  int splitArray(vector<int> &nums, int k) {
    int sum = 0, s = 0;
    for (int i : nums) {
      sum += i;
      s = max(s, i);
    }
    int e = sum, ans = e;
    while (s <= e) {
      int mid = s + (e - s) / 2;
      if (isPossible(mid, nums, k)) {
        ans = mid;
        e = mid - 1;
      } else {
        s = mid + 1;
      }
    }
    return ans;
  }
};