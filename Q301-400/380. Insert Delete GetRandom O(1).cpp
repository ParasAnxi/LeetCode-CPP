class RandomizedSet
{
private:
    unordered_map<int, int> m;
    vector<int> v;

public:
    RandomizedSet() {}

    bool insert(int val)
    {
        if (m.find(val) == m.end())
        {
            v.push_back(val);
            m[val] = v.size() - 1;
            return true;
        }
        return false;
    }

    bool remove(int val)
    {
        if (m.find(val) != m.end())
        {
            m[v[v.size() - 1]] = m[val];
            v[m[val]] = v[v.size() - 1];
            m.erase(val);
            v.pop_back();
            return true;
        }
        return false;
    }

    int getRandom()
    {
        return v[rand() % v.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */