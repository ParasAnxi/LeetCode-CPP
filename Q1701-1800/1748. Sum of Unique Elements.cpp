class Solution {
public:
  int sumOfUnique(vector<int> &nums) {
    unordered_map<int, int> mp;
    for (auto i : nums) {
      mp[i]++;
    }
    int sum = 0;
    for (auto i : mp) {
      if (i.second == 1) {
        sum += i.first;
      }
    }
    return sum;
  }
};