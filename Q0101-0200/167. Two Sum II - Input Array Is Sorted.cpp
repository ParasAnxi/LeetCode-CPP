class Solution {
public:
  vector<int> twoSum(vector<int> &numbers, int target) {
    int n = numbers.size();
    int s = 0, e = n - 1;
    int sum = 0;
    while (s <= e) {
      sum = numbers[s] + numbers[e];
      if (sum > target) {
        e--;
      } else if (sum < target) {
        s++;
      } else {
        return {s + 1, e + 1};
      }
    }
    return {0, 0};
  }
};