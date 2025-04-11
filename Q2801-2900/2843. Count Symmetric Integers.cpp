class Solution {
public:
  int solve(string st) {
    int nums = stoi(st);
    int s = 0;
    while (nums) {
      s += nums % 10;
      nums /= 10;
    }
    return s;
  }
  int countSymmetricIntegers(int low, int high) {
    int count = 0;
    for (int i = low; i <= high; i++) {
      string st = to_string(i);
      int n = st.size();
      if (n % 2)
        continue;
      if (solve(st.substr(0, n / 2)) == solve(st.substr(n / 2, n / 2)))
        count++;
    }
    return count;
  }
};