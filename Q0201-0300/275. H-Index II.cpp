class Solution {
public:
  int hIndex(vector<int> &citations) {
    int n = citations.size();
    int s = 0;
    int e = n;
    while (s < e) {
      int mid = (s + e) / 2;
      if (citations[mid] >= n - mid)
        e = mid;
      else
        s = mid + 1;
    }
    return n - s;
  }
};