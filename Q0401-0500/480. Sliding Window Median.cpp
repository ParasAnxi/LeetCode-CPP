class Solution {
public:
  vector<double> medianSlidingWindow(vector<int> &nums, int k) {
    int e = k / 2;
    int s = e;
    if (k & 1) {
      s++;
    }
    int n = nums.size();
    vector<double> ans;
    priority_queue<vector<int>> mPq;
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

    auto median = [&]() {
      if (s == e)
        ans.push_back((1LL * mPq.top()[0] + 1LL * pq.top()[0]) * 0.5);
      else {
        ans.push_back(mPq.top()[0]);
      }
    };
    for (int i = 0; i < k; i++) {
      mPq.push({nums[i], i});
      if (mPq.size() > s) {
        auto top = mPq.top();
        mPq.pop();
        pq.push(top);
      }
    }
    median();
    for (int i = k; i < n; i++) {
      int eN = nums[i - k];
      if (eN <= mPq.top()[0]) {
        if (nums[i] < mPq.top()[0]) {
          mPq.push({nums[i], i});
        } else {
          pq.push({nums[i], i});
          mPq.push(pq.top());
          pq.pop();
        }
      } else {
        if (nums[i] > pq.top()[0]) {
          pq.push({nums[i], i});
        } else {
          mPq.push({nums[i], i});
          pq.push(mPq.top());
          mPq.pop();
        }
      }
      while (mPq.top()[1] <= i - k) {
        mPq.pop();
      }
      while (!pq.empty() && pq.top()[1] <= i - k) {
        pq.pop();
      }
      median();
    }
    return ans;
  }
};