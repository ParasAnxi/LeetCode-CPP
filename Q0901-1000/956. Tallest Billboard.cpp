class Solution {
public:
    int tallestBillboard(vector<int>& rods) {
      unordered_map<int, int> m;
      m[0] = 0;  
      for(int i = 0; i < rods.size(); i++) {
        auto v = m;
        for(const auto &p : m) {
          v[p.first + rods[i]] = max(v[p.first + rods[i]], p.second + rods[i]);
          v[p.first - rods[i]] = max(v[p.first - rods[i]], p.second);  
        }
        swap(m, v);  
      }
      return m[0];  
    }
};