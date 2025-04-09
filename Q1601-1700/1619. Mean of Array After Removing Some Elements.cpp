class Solution {
public:
  double trimMean(vector<int> &arr) {
    sort(arr.begin(), arr.end());
    int n = arr.size();
    double sum = 0;
    for (int i = 0; i < n; i++) {
      sum += arr[i];
    }
    int x = n / 20;
    for (int i = 0; i < x; i++){
        sum -= arr[i];
    }
    int a = n - x;
    for (int i = a; i < n; i++){
        sum -= arr[i];
    }
    n -= x * 2;
    double ans = sum / (n);
    return ans;
  }
};