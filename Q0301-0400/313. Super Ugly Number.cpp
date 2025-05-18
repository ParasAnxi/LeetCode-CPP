class Solution {
public:
  int nthSuperUglyNumber(int n, vector<int> &primes) {
    vector<long long> uN(n);
    uN[0] = 1;

    int N = primes.size();

    vector<int> lInd(N, 0);
    vector<long long> nxtM(N);
    for (int i = 0; i < N; i++) {
      nxtM[i] = primes[i];
    }

    for (int i = 1; i < n; i++) {
      long long nxtUn = INT_MAX;
      for (int j = 0; j < N; j++) {
        nxtUn = min(nxtUn, nxtM[j]);
      }

      uN[i] = nxtUn;

      for (int j = 0; j < N; j++) {
        if (nxtUn == nxtM[j]) {
          lInd[j]++;
          nxtM[j] = uN[lInd[j]] * primes[j];
        }
      }
    }
    return uN[n - 1];
  }
};