using ll = long long;

class Solution {
public:
  unordered_set<string> visited;
  vector<ll> fact;

  void facto() {
    fact.resize(11, 1);
    for (int i = 2; i <= 10; i++) {
      fact[i] = fact[i - 1] * i;
    }
  }

  ll count(int n, vector<int> &freq) {
    ll ans = fact[n];
    for (auto x : freq) {
      ans /= fact[x];
    }

    return ans;
  }

  ll allPermutations(string st) {
    sort(st.begin(), st.end());
    if (visited.count(st) > 0) {
      return 0;
    }
    int n = st.size();
    visited.insert(st);
    vector<int> freq(10, 0);
    for (auto x : st) {
      freq[x - '0']++;
    }
    ll val = 0, inval = 0;
    val = count(n, freq);
    if (freq[0] > 0) {
      freq[0]--;
      inval = count(n - 1, freq);
    }

    return val - inval;
  }

  ll solve(int i, int n, int k, string st) {
    if (i == (n + 1) / 2) {
      if (stoll(st) % k == 0)
        return allPermutations(st);
      return 0;
    }

    char ch = (i == 0) ? '1' : '0';
    ll ans = 0;
    while (ch <= '9') {
      st[i] = ch;
      st[n - i - 1] = ch;
      ans += solve(i + 1, n, k, st);
      ch++;
    }

    return ans;
  }

  long long countGoodIntegers(int n, int k) {
    facto();
    string st(n, '0');
    return solve(0, n, k, st);
  }
};