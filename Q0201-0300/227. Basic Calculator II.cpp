class sT {
  vector<int> tree;
  int n;

public:
  sT(int n) {
    this->n = n;
    tree.resize(4 * n + 1);
  }

  void init(int index, int i, int j, vector<string> &v, map<string, int> &mp) {
    if (i == j) {
      if (v[i] == "+" || v[i] == "-" || v[i] == "*" || v[i] == "/")
        tree[index] = i;
      else
        tree[index] = -1;

      return;
    }

    int mid = i + (j - i) / 2;
    init(index * 2, i, mid, v, mp);
    init(index * 2 + 1, mid + 1, j, v, mp);
    if (tree[index * 2] == -1)
      tree[index] = tree[index * 2 + 1];
    else if (tree[index * 2 + 1] == -1)
      tree[index] = tree[index * 2];
    else {
      if (mp[v[tree[index * 2]]] < mp[v[tree[index * 2 + 1]]])
        tree[index] = tree[index * 2];
      else
        tree[index] = tree[index * 2 + 1];
    }

    return;
  }

  int qry(int i, int j, int qs, int qe, int index, vector<string> &v,
          map<string, int> &mp) {
    if (i >= qs && j <= qe)
      return tree[index];
    if (j < qs || i > qe)
      return -1;
    int mid = i + (j - i) / 2;
    int x = qry(i, mid, qs, qe, index * 2, v, mp);
    int y = qry(mid + 1, j, qs, qe, index * 2 + 1, v, mp);
    if (x == -1)
      return y;
    if (y == -1)
      return x;

    return mp[v[x]] < mp[v[y]] ? x : y;
  }
};
class Solution {
public:
  int solve(int s, int e, vector<string> &v, map<string, int> &mp, sT &st) {
    if (s == e)
      return stoi(v[s]);

    int opInd = st.qry(0, v.size() - 1, s, e, 1, v, mp);

    int x = solve(s, opInd - 1, v, mp, st);
    int y = solve(opInd + 1, e, v, mp, st);

    int ans = 0;
    if (v[opInd] == "+") {
      ans = x + y;
    } else if (v[opInd] == "-") {
      ans = x - y;
    } else if (v[opInd] == "*") {
      ans = x * y;
    } else if (v[opInd] == "/") {
      ans = x / y;
    }

    return ans;
  }

  int calculate(string s) {
    map<string, int> mp;
    mp["+"] = 1;
    mp["-"] = 1;
    mp["*"] = 2;
    mp["/"] = 2;

    vector<string> v;
    string temp = "";

    for (int i = 0; i < s.size(); i++) {
      if (s[i] == ' ')
        continue;

      if (s[i] == '*' || s[i] == '/' || s[i] == '+' || s[i] == '-') {
        if (!temp.empty()) {
          v.push_back(temp);
          temp = "";
        }
        v.push_back(string(1, s[i]));
      } else {
        temp.push_back(s[i]);
      }
    }

    if (!temp.empty())
      v.push_back(temp);

    sT st(v.size());
    st.init(1, 0, v.size() - 1, v, mp);

    return solve(0, v.size() - 1, v, mp, st);
  }
};