class Solution {
public:
  vector<int> stableMountains(vector<int> &height, int threshold) {
    int n = height.size();
    vector<int> ans;
    for (int i = 1; i < n; ++i) {
      if (threshold < height[i - 1]) {
        ans.push_back(i);
      }
    }
    return ans;
  }
};