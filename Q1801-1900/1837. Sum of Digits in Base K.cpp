class Solution {
public:
  int sumBase(int n, int k) {
    vector<int> v;
    int sum = 0;
    while (n != 0) {
      v.push_back(n % k);
      n = n / k;
    }
    for (int i = 0; i < v.size(); i++) {
      sum += v[i];
    }

    return sum;
  }
};