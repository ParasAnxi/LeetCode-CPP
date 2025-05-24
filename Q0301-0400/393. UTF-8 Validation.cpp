class Solution {
public:
  bool check(vector<int> &data, int i, int len) {
    int s = i;
    while (i < len + s) {
      if (i == data.size())
        return 0;
      if (data[i] > 191 || data[i] < 128)
        return 0;
      i++;
    }
    return 1;
  }
  bool validUtf8(vector<int> &data) {
    int i = 0;
    while (i < data.size()) {
      if (data[i] < 128) {
        i++;
      } else if (data[i] <= 223 && data[i] >= 192) {
        i++;
        bool full = check(data, i, 1);
        if (full == 0)
          return 0;
        i += 1;
      } else if (data[i] <= 239 && data[i] >= 224) {
        i++;
        bool full = check(data, i, 2);
        if (full == 0)
          return 0;
        i += 2;
      } else if (data[i] <= 247 && data[i] >= 240) {
        i++;
        bool full = check(data, i, 3);
        if (full == 0)
          return 0;
        i += 3;
      } else
        return 0;
    }
    return 1;
  }
};