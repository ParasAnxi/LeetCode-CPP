class Solution {
public:
  int addedInteger(vector<int> &nums1, vector<int> &nums2) {
    int n = nums1.size();
    int m = nums2.size();
    int s1 = 0;
    int s2 = 0;
    for (auto i : nums1)
      s1 += i;
    for (auto j : nums2)
      s2 += j;
    return (s2 - s1) / n;
  }
};