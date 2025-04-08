class Solution {
public:
  vector<string> readBinaryWatch(int turnedOn) {
    vector<string> ans;
    for (int i = 0; i < 12; i++) {
      for (int j = 0; j < 60; j++) {
        int bits = bitset<4>(i).count() + bitset<6>(j).count();
        if (bits == turnedOn) {
          ans.push_back(to_string(i) + ":" + (j < 10 ? "0" : "") + to_string(j));
        }
      }
    }
    return ans;
  }
};