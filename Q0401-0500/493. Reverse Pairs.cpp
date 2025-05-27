class Solution {
public:
  void merge(vector<int> &nums, int s, int mid, int e, long long &count) {
    int j = mid + 1;
    for (int i = s; i <= mid; i++) {
      while (j <= e && (long long)nums[i] > 2ll * nums[j]) {
        j++;
      }
      count += j - (mid + 1);
    }

    vector<int> vM;
    int left = s, right = mid + 1;

    while (left <= mid && right <= e) {
      if (nums[left] <= nums[right]) {
        vM.push_back(nums[left]);
        left++;
      } else {
        vM.push_back(nums[right]);
        right++;
      }
    }

    while (left <= mid) {
      vM.push_back(nums[left]);
      left++;
    }

    while (right <= e) {
      vM.push_back(nums[right]);
      right++;
    }

    for (int i = s; i <= e; i++) {
      nums[i] = vM[i - s];
    }
  }

  void mS(vector<int> &nums, int s, int e, long long &count) {
    if (s >= e)
      return;
    int mid = (s + e) / 2;
    mS(nums, s, mid, count);
    mS(nums, mid + 1, e, count);
    merge(nums, s, mid, e, count);
  }
  int reversePairs(vector<int> &nums) {
    long long count = 0;
    mS(nums, 0, nums.size() - 1, count);
    return count;
  }
};