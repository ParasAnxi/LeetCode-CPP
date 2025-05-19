class Solution {
public:
  void wiggleSort(vector<int> &nums) {
    int n = nums.size();
    sort(nums.begin(), nums.end());
    deque<int> q;
    for (auto i : nums) {
      q.push_back(i);
    }
    int i = 0;
    for (i = 1; i < n; i += 2) {
      nums[i] = q.back();
      q.pop_back();
    }
    for (i = 0; i < n; i += 2) {
      nums[i] = q.back();
      q.pop_back();
    }
  }
};