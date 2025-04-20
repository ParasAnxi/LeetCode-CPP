using umii = unordered_map<int, int> ;
class Solution {
public:
  int numRabbits(vector<int> &answers) {
    umii mp;
    for (int i = 0; i < answers.size(); i++) {
      mp[answers[i]]++;
    }
    int ans = 0;
    auto i = mp.begin();
    while (i != mp.end()) {
      if (i->first == 0) {
        ans += i->second;
        i++;
        continue;
      }
      if (i->second != 0) {
        if (i->second > i->first + 1) {
          ans += i->first + 1;
          i->second -= (i->first + 1);
        } else if (i->second <= i->first + 1) {
          ans += i->first + 1;
          i->second = 0;
        }

      } else {
        i++;
      }
    }
    return ans;
  }
};