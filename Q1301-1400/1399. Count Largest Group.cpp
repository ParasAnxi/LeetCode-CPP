class Solution {
public:
  int countLargestGroup(int n) {
    unordered_map<int, int> mp;
    int count = 0;
    int maxi = 0;
    for (int i = 1; i <= n; i++) {
      int temp = i;
      int sum = 0;
      while (temp > 0) {
        sum += temp % 10;
        temp /= 10;
      }
      mp[sum]++;
    }
    for (auto &i : mp) {
      if (i.second > maxi) {
        count = 1;
        maxi = i.second;
      } else if (i.second == maxi) {
        count++;
      }
    }
    return count;
  }
};