class Solution {
public:
  int finalValueAfterOperations(vector<string> &op) {
    int count = 0;

    for (int i = 0; i < op.size(); i++) {
      if (op[i] == "--X" || op[i] == "X--") {
        count -= 1;
      } else {
        count += 1;
      }
    }
    return count;
  }
};