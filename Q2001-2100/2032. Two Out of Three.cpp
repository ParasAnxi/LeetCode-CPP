class Solution {
public:
  vector<int> twoOutOfThree(vector<int> &nums1, vector<int> &nums2, vector<int> &nums3) {
    set<int> st1(nums1.begin(), nums1.end());
    set<int> st2(nums2.begin(), nums2.end());
    set<int> st3(nums3.begin(), nums3.end());

    set<int> st;

    for (auto it : st1) {
      if (st2.find(it) != st2.end() || st3.find(it) != st3.end()) {
        st.insert(it);
      }
    }

    for (auto it : st2) {
      if (st1.find(it) != st1.end() || st3.find(it) != st3.end()) {
        st.insert(it);
      }
    }

    for (auto it : st3) {
      if (st1.find(it) != st1.end() || st2.find(it) != st2.end()) {
        st.insert(it);
      }
    }

    vector<int> ans(st.begin(), st.end());
    return ans;
  }
};