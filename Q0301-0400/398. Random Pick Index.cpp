class Solution {
public:
  vector<int> v;
  Solution(vector<int> &nums) { v = nums; }

  int pick(int target) {
    int count = 0;
    int index = 0;
    for (int i = 0; i < v.size(); i++) {
      if (v[i] == target) {
        count += 1;

        if (rand() % count == 0)
          index = i;
      }
    }
    return index;
  }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */