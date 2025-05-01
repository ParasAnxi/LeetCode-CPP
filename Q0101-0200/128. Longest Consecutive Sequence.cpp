class Solution {
public:
  int longestConsecutive(vector<int> &nums) {
    unordered_set<int> st(nums.begin(), nums.end());
    int maxi = 0;
    for (int i : st) {
      if (st.find(i - 1) == st.end()) {
        int n = 0;
        while (st.find(n + i) != st.end())
          n++;
        maxi = max(n, maxi);
      }
    }
    return maxi;
  }
};