class Solution {
private:
  void smallPrimeFactor() {
    for (int i = 2; i <= 100000; i++) {
      spf[i] = i;
    }
    for (int i = 2; i * i <= 100000; i++) {
      if (spf[i] == i) {
        for (int j = i * i; j <= 100000; j += i) {
          if (spf[j] == j) {
            spf[j] = i;
          }
        }
      }
    }
  }
  int uniquePF(int num) {
    unordered_set<int> uP;
    while (num > 1) {
      uP.insert(spf[num]);
      num /= spf[num];
    }
    return uP.size();
  }
  void pS(vector<int> &nums, vector<int> &primeScore) {
    for (size_t i = 0; i < nums.size(); i++) {
      primeScore[i] = uniquePF(nums[i]);
    }
  }

  void solve(vector<int> &primeScore, vector<int> &s, vector<int> &e, int n) {
    stack<int> st;

    for (int i = 0; i < n; i++) {
      while (!st.empty() && primeScore[st.top()] < primeScore[i]) {
        st.pop();
      }
      s[i] = st.empty() ? 0 : st.top() + 1;
      st.push(i);
    }

    while (!st.empty())
      st.pop(); 
    for (int i = n - 1; i >= 0; i--) {
      while (!st.empty() && primeScore[st.top()] <= primeScore[i]) {
        st.pop();
      }
      e[i] = st.empty() ? (n - 1) : (st.top() - 1);
      st.push(i);
    }
  }

  int modPow(int base, int exp, int mod) {
    int ans = 1;
    while (exp > 0) {
      if (exp % 2 == 1)
        ans = (1LL * ans * base) % mod;
      base = (1LL * base * base) % mod;
      exp /= 2;
    }
    return ans;
  }

public:
  vector<int> spf;
  const int MOD = 1e9 + 7;

  int maximumScore(vector<int> &nums, int k) {
    int n = nums.size();
    spf.resize(100001);
    smallPrimeFactor();

    vector<int> primeScore(n), s(n), e(n);
    pS(nums, primeScore);
    solve(primeScore, s, e, n);

    vector<pair<int, int>> sNums;
    for (int i = 0; i < n; i++) {
      sNums.emplace_back(nums[i], i);
    }
    sort(sNums.rbegin(), sNums.rend());

    int ans = 1;
    for (auto &[val, index] : sNums) {
      if (k <= 0) break;

      int l = s[index], r = e[index];
      long long possOp = 1LL * (index - l + 1) * (r - index + 1);
      int ops = min((long long)k, possOp);
      k -= ops;

      ans = (1LL * ans * modPow(val, ops, MOD)) % MOD;
    }
    return ans;
  }
};
