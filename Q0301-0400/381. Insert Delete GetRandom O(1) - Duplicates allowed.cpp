class RandomizedCollection {
public:
  vector<int> vV;
  unordered_map<int, unordered_set<int>> mp;
  RandomizedCollection() { srand(time(0)); }

  bool insert(int val) {
    bool fnd = (mp.find(val) != mp.end());
    vV.push_back(val);
    mp[val].insert(vV.size() - 1);
    return !fnd;
  }
  void exg(int i, int j) {
    int val1 = vV[i], val2 = vV[j];
    if (val1 != val2) {
      mp[val1].erase(i);
      mp[val1].insert(j);
      mp[val2].erase(j);
      mp[val2].insert(i);
      swap(vV[i], vV[j]);
    }
  }
  bool remove(int val) {
    if (mp.find(val) == mp.end())
      return 0;
    exg(*mp[val].begin(), vV.size() - 1);
    mp[val].erase(vV.size() - 1);
    if (mp[val].empty())
      mp.erase(val);
    vV.pop_back();
    return 1;
  }

  int getRandom() { return vV[rand() % vV.size()]; }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */