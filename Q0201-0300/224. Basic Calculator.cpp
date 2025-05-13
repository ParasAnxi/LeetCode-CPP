class Solution {
public:
  int calculate(string s) {
    stack<int> st;
    st.push(1);
    int x = 0;
    int ans = 0;
    int sign = 1;
    for (int i = 0; i < s.size(); i++) {
      char c = s[i];
      if (isdigit(c)) {
        x = x * 10 + (c - '0');
      } else if (c == '+' || c == '-') {
        ans = ans + (sign * x);
        if ((c == '-' && st.top() == -1) || (c == '+' && st.top() == 1)) {
          x = 0;
          sign = 1;
        } else {
          x = 0;
          sign = -1;
        }
      } else if (c == ' ') {
        continue;
      } else if (c == '(') {
        st.push(sign);
      } else if (c == ')') {
        st.pop();
      }
    }
    ans = ans + sign * x;
    return ans;
  }
};