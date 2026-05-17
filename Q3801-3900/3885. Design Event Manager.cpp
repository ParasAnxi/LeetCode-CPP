using ll = long long;
using ull = unsigned long long;
using ld = long double;
using cd = complex<double>;
using pii = pair<int, int>;
using psi = pair<string, int>;
using pll = pair<ll, ll>;
using ppii = pair<int, pii>;
using vi = vector<int>;
using vd = vector<double>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using vc = vector<char>;
using vpii = vector<pii>;
using vpll = vector<pll>;
using pis = pair<int, string>;
using vs = vector<string>;
using mii = map<int, int>;
using mll = map<ll, ll>;
using pli = pair<ll, int>;
using umii = unordered_map<int, int>;
using umcvi = unordered_map<char, vi>;
using umsi = unordered_map<string, int>;
using mivi = map<int, vi>;
using umci = unordered_map<char, int>;
#define pb push_back
#define MOD 1000000007
#define LMOD 1000000000000000007LL
class EventManager {
public:
  struct cmp {
    bool operator()(const pii &a, const pii &b) const {
      if (a.first == b.first)
        return a.second < b.second;
      return a.first > b.first;
    }
  };
  umii mp;
  multiset<pii, cmp> ms;
  EventManager(vector<vector<int>> &events) {
    for (auto i : events) {
      int j = i[0];
      int p = i[1];
      mp[j] = p;
      ms.insert({p, j});
    }
  }

  void updatePriority(int eventId, int newPriority) {
    if (mp.find(eventId) != mp.end()) {
      ms.erase(ms.find({mp[eventId], eventId}));
    }
    mp[eventId] = newPriority;
    ms.insert({newPriority, eventId});
  }

  int pollHighest() {
    if (ms.empty()) {
      return -1;
    }
    auto [p, j] = *ms.begin();
    ms.erase(ms.begin());
    return j;
  }
};

/**
 * Your EventManager object will be instantiated and called as such:
 * EventManager* obj = new EventManager(events);
 * obj->updatePriority(eventId,newPriority);
 * int param_2 = obj->pollHighest();
 */