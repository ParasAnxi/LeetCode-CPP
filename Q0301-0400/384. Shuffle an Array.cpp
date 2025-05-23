class Solution {
public:
  vector<int> v1, v2;
  Solution(vector<int> &nums) {
    v1 = nums;
    v2 = nums;
  }

  vector<int> reset() { return v1; }

  vector<int> shuffle() {
    int k = rand() % v1.size();
    reverse(v2.begin(), v2.begin() + k);
    reverse(v2.begin(), v2.end());
    return v2;
  }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */