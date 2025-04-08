class Solution {
public:
  int trdMax(vector<int> &nums) {
    long fst = LONG_MIN, sec = LONG_MIN, trd = LONG_MIN;

    for (int num : nums) {
      if (num == fst || num == sec || num == trd)
        continue;
      if (num > fst) {
        trd = sec;
        sec = fst;
        fst = num;
      } else if (num > sec) {
        trd = sec;
        sec = num;
      } else if (num > trd) {
        trd = num;
      }
    }
    return trd == LONG_MIN ? fst : trd;
  }
};