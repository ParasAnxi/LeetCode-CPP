class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        vector<pair<int, int>> v(0);
        vector<double> frac(v.size());
        for(int i = 0; i < arr.size()-1; i++) {
          for(int j = i+1; j < arr.size(); j++) {
            v.emplace_back(arr[i], arr[j]);
            frac.push_back(double(arr[i])/arr[j]);
          }
        }
        vector<int> order(v.size());
        iota(order.begin(), order.end(), 0);
        sort(order.begin(), order.end(), [&](int i, int j) {
          return frac[i] < frac[j];
        });
        return {v[order[k-1]].first, v[order[k-1]].second};
    }
};