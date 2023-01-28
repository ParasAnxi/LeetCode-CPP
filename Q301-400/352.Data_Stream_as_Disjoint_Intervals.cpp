class SummaryRanges {
public:
    SummaryRanges() {
        
    }
    
    void addNum(int x) {
        auto i = _map.lower_bound(x);
        bool merge = false;
        if(i != _map.begin()) {
            auto prev = i;
            --prev;
            if(prev->second + 1 >= x) {
                merge = true;
                prev->second = max(prev->second, x);
            }
        }

        if(i != _map.end()) {
            if(i->first - 1 <= x) {
                if(merge) {
                    auto prev = i;
                    --prev;
                    if(prev->second >= i->first - 1) {
                        prev->second = max(prev->second, i->second);
                        _map.erase(i);
                    }
                } else {
                    merge = true;
                    if(i->first != x) {
                        pair<int, int> p = *i;
                        p.first = min(p.first, x);
                        i = _map.insert(i, p);
                        ++i;
                        if(i != _map.end())
                            _map.erase(i);
                    }
                }
            }
        }
        if(!merge)
            _map.insert(i, {x, x});
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>> intervals;
        for(auto const & p : _map)
            intervals.push_back({p.first, p.second});
        return intervals;
    }

    map<int, int> _map;
};