class Solution {
public:
  int m, n;
  map<pair<int, int>, int> map;
  Solution(int m, int n) {
    this->m = m;
    this->n = n;
  }

  vector<int> flip() {
    int x = rand() % m;
    int y = rand() % n;

    while (map[{x, y}] > 0) {
      x = rand() % m;
      y = rand() % n;
    }
    map[{x, y}]++;
    return {x, y};
  }

  void reset() { map.clear(); }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(m, n);
 * vector<int> param_1 = obj->flip();
 * obj->reset();
 */