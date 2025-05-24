class Solution {
public:
  bool isRectangleCover(vector<vector<int>> &rectangles) {
    int x1 = INT_MAX;
    int y1 = INT_MAX;
    int x2 = INT_MIN;
    int y2 = INT_MIN;
    unordered_set<string> mp;
    long long area = 0;
    for (auto &i : rectangles) {
      x1 = min(x1, i[0]);
      y1 = min(y1, i[1]);
      x2 = max(x2, i[2]);
      y2 = max(y2, i[3]);
      area += abs((i[2] - i[0]) * 1LL * (i[3] - i[1]));
      string p1 = to_string(i[0]) + " " + to_string(i[1]);
      string p2 = to_string(i[0]) + " " + to_string(i[3]);
      string p3 = to_string(i[2]) + " " + to_string(i[1]);
      string p4 = to_string(i[2]) + " " + to_string(i[3]);
      if (mp.count(p1))
        mp.erase(p1);
      else
        mp.insert(p1);
      if (mp.count(p2))
        mp.erase(p2);
      else
        mp.insert(p2);
      if (mp.count(p3))
        mp.erase(p3);
      else
        mp.insert(p3);
      if (mp.count(p4))
        mp.erase(p4);
      else
        mp.insert(p4);
    }
    string a = to_string(x1) + " " + to_string(y1);
    string b = to_string(x2) + " " + to_string(y1);
    string c = to_string(x1) + " " + to_string(y2);
    string d = to_string(x2) + " " + to_string(y2);
    if (mp.size() != 4 || !mp.count(a) || !mp.count(b) || !mp.count(c) ||
        !mp.count(d)) {
      return 0;
    }
    if (area != abs((x2 - x1) * 1LL * (y2 - y1)))
      return 0;

    return 1;
  }
};