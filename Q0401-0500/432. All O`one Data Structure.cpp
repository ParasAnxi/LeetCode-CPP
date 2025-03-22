class AllOne
{
public:
    unordered_map<string, int> count;
    priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>> minHeap;
    priority_queue<pair<int, string>, vector<pair<int, string>>> maxHeap;
    
    AllOne()
    {
    }

    void inc(string key)
    {
        count[key]++;
        minHeap.push({count[key], key});
        maxHeap.push({count[key], key});
    }

    void dec(string key)
    {
        count[key]--;
        if (count[key] == 0)
            return;
        minHeap.push({count[key], key});
        maxHeap.push({count[key], key});
    }

    string getMaxKey()
    {
        if (maxHeap.empty())
            return "";

        while (!maxHeap.empty() and count[maxHeap.top().second] != maxHeap.top().first)
        {
            maxHeap.pop();
        }

        if (maxHeap.empty())
            return "";

        return maxHeap.top().second;
    }

    string getMinKey()
    {
        if (minHeap.empty())
            return "";

        while (!minHeap.empty() and count[minHeap.top().second] != minHeap.top().first)
        {
            minHeap.pop();
        }
        if (minHeap.empty())
            return "";
        return minHeap.top().second;
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */