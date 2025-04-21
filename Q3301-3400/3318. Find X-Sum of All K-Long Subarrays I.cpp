using umii = unordered_map<int, int>;
using pii = pair<int, int>;
using spii = set<pii>;
using vi = vector<int>;
#define pb push_back
class Solution {
public:
  vector<int> findXSum(vector<int> &nums, int k, int x) {
    umii mp;
    spii st;

    int l = 0, r = k - 1;
    for (int i = 0; i < k; i++) {
      mp[nums[i]]++;
    }
    for (auto it : mp) {
      st.insert({it.second, it.first});
    }
    vi ans;

    while (r < nums.size()) {
      int s = x, sum = 0;
      for (auto i = st.rbegin(); i != st.rend() && s > 0; i++, s--) {
        int num = i->second;
        int freq = i->first;
        sum += num * freq;
      }

      ans.pb(sum);

      int oN = nums[l], f = mp[nums[l]];
      st.erase({f, oN});
      mp[oN]--;
      if (mp[oN] > 0) {
        st.insert({mp[oN], oN});
      } else
        mp.erase(oN);

      if (r + 1 >= nums.size())
        break;
      int iN = nums[r + 1];
      if (mp.find(iN) != mp.end()) {
        st.erase({mp[iN], iN});
      }
      mp[iN]++;
      st.insert({mp[iN], iN});
      l++;
      r++;
    }

    return ans;
  }
};