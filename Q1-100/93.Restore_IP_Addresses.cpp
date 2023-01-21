class Solution {
 public:
  vector<string> restoreIpAddresses(const string& s) {
    vector<string> a;
    x(s, 0, {}, a);
    return a;
  }

 private:
  void x(const string& s, int start, vector<string>&& path,
           vector<string>& a) {
    if (path.size() == 4 && start == s.length()) {
      ans.push_back(path[0] + "." + path[1] + "." + path[2] + "." + path[3]);
      return;
    }
    if (path.size() == 4 || start == s.length())
      return;

    for (int length = 1; length <= 3; ++length) {
      if (start + length > s.length())
        return;
      if (length > 1 && s[start] == '0')
        return; 
      const string& num = s.substr(start, length);
      if (stoi(num) > 255)
        return;
      path.push_back(num);
      x(s, start + length, move(path), a);
      path.pop_back();
    }
  }
};
