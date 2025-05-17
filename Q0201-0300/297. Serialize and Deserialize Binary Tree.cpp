/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
  TreeNode *init(vector<string> &vS, int &idx) {
    if (idx == vS.size())
      return NULL;
    if (vS[idx] == "#") {
      idx++;
      return NULL;
    }
    TreeNode *node = new TreeNode(stoi(vS[idx++]));
    node->left = init(vS, idx);
    node->right = init(vS, idx);
    return node;
  }
  void solve(TreeNode *root, string &s) {
    if (!root) {
      s.append("# ");
      return;
    }
    s.append(to_string(root->val));
    s.append(" ");
    solve(root->left, s);
    solve(root->right, s);
  }
  // Encodes a tree to a single string.
  string serialize(TreeNode *root) {
    string st;
    solve(root, st);
    return st;
  }

  // Decodes your encoded data to tree.
  TreeNode *deserialize(string data) {
    if (data.empty())
      return NULL;
    vector<string> vS;
    int i = 0;
    int n = data.size();
    while (i < n) {
      int j = i;
      while (j < n && data[j] != ' ')
        j++;
      vS.push_back(data.substr(i, j - i));
      i = j + 1;
    }
    int idx = 0;
    return init(vS, idx);
  }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));