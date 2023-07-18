class LRUCache
{
public:
    int cap;
    unordered_map<int, list<pair<int, int>>::iterator> m;
    list<pair<int, int>> l;

    LRUCache(int capacity)
    {
        cap = capacity;
    }

    int get(int key)
    {
        if (m.find(key) == m.end())
        {
            return -1;
        }
        l.splice(l.begin(), l, m[key]);
        return m[key]->second;
    }

    void put(int key, int value)
    {
        if (m.find(key) != m.end())
        {
            m[key]->second = value;
            l.splice(l.begin(), l, m[key]);
            return;
        }

        if (l.size() == cap)
        {
            auto d_key = l.back();
            l.pop_back();
            m.erase(d_key.first);
        }

        l.push_front({key, value});
        m[key] = l.begin();
        return;
    }
};