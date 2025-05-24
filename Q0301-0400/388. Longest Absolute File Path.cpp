class Solution {
public:
  int lengthLongestPath(string input) {
    vector<int> v;
    int sum = 0;
    int n = input.size();
    int ans = 0;

    for (int s = 0, e; s < n; s = e + 1) {
      int depth = 0;
      while (s + 1 < n && input[s] == '\t')
        s++, depth++;
      while (v.size() > depth) {
        sum -= v.back();
        v.pop_back();
      }

      e = s;
      bool file = false;
      while (e < n && input[e] != '\n') {
        if (input[e++] == '.')
          file = true;
      }

      int currL = e - s;
      v.push_back(currL);
      sum += currL;
      if (file)
        ans = max(ans, sum + ((int)v.size() - 1));
    }

    return ans;
  }
};