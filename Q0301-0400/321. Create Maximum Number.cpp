class Solution {
public:
  vector<int> solveMs(const vector<int> &nums, int k) {
    vector<int> vS;
    int rem = nums.size() - k;
    for (int i : nums) {
      while (!vS.empty() && vS.back() < i && rem > 0) {
        vS.pop_back();
        rem--;
      }
      if (vS.size() < k) {
        vS.push_back(i);
      } else {
        rem--;
      }
    }
    return vS;
  }

  vector<int> merge(const vector<int> &nums1, const vector<int> &nums2) {
    vector<int> ans;
    int i = 0, j = 0;
    while (i < nums1.size() || j < nums2.size()) {
      if (solveG(nums1, i, nums2, j)) {
        ans.push_back(nums1[i++]);
      } else {
        ans.push_back(nums2[j++]);
      }
    }
    return ans;
  }

  bool solveG(const vector<int> &nums1, int i, const vector<int> &nums2,
              int j) {
    while (i < nums1.size() && j < nums2.size()) {
      if (nums1[i] != nums2[j]) {
        return nums1[i] > nums2[j];
      }
      i++;
      j++;
    }
    return (nums1.size() - i) > (nums2.size() - j);
  }
  vector<int> maxNumber(vector<int> &nums1, vector<int> &nums2, int k) {
    vector<int> ans(k, 0);
    int n = nums1.size(), m = nums2.size();
    for (int i = max(0, k - m); i <= min(k, n); ++i) {
      vector<int> s1 = solveMs(nums1, i);
      vector<int> s2 = solveMs(nums2, k - i);
      vector<int> mrg = merge(s1, s2);
      if (solveG(mrg, 0, ans, 0)) {
        ans = mrg;
      }
    }
    return ans;
  }
};