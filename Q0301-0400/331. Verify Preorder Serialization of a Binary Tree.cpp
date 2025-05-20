class Solution {
public:
  bool isValidSerialization(string preorder) {
    stack<pair<int, int>> s;
    s.push({-1, 0});
    for (int i = 0; i < preorder.length(); i++) {
      if (preorder[i] == ',')
        continue;
      string st = "";
      while (i < preorder.length() && preorder[i] >= '0' &&
             preorder[i] <= '9') {
        st += preorder[i];
        i++;
      }

      if (!st.empty())
        i--;

      if (!s.empty()) {
        if (s.top().first == -1) {
          s.pop();
        } else {
          s.top().second++;
        }
      } else {
        return false;
      }

      if (!s.empty() && s.top().second == 2) {
        s.pop();
      }

      if (st.empty())
        continue;

      int val = stoi(st);
      s.push({val, 0});
    }

    return s.empty();
  }
};