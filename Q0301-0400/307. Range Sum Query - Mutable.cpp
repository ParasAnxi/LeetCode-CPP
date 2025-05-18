class NumArray {
public:
  int n;
  vector<int> tree;

  void build(int i, int s, int e, vector<int> &arr) {
    if (s == e) {
      tree[i] = arr[s];
      return;
    }
    int mid = s + (e - s) / 2;
    build(2 * i + 1, s, mid, arr);
    build(2 * i + 2, mid + 1, e, arr);
    tree[i] = tree[2 * i + 1] + tree[2 * i + 2];
  }

  NumArray(vector<int> &arr) {
    n = arr.size();
    tree.resize(4 * n);
    build(0, 0, n - 1, arr);
  }

  void up(int index, int val, int i, int s, int e) {
    if (s == e) {
      tree[i] = val;
      return;
    }
    int mid = s + (e - s) / 2;
    if (index <= mid) {
      up(index, val, 2 * i + 1, s, mid);
    } else {
      up(index, val, 2 * i + 2, mid + 1, e);
    }
    tree[i] = tree[2 * i + 1] + tree[2 * i + 2];
  }

  void update(int indexx, int val) { up(indexx, val, 0, 0, n - 1); }

  int qry(int start, int end, int i, int s, int e) {
    if (s > end || e < start) {
      return 0;
    }
    if (s >= start && e <= end) {
      return tree[i];
    }
    int mid = s + (e - s) / 2;
    return qry(start, end, 2 * i + 1, s, mid) +
           qry(start, end, 2 * i + 2, mid + 1, e);
  }

  int sumRange(int left, int right) { return qry(left, right, 0, 0, n - 1); }
};