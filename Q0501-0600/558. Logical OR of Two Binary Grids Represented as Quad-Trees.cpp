/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;

    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node*
_bottomLeft, Node* _bottomRight) { val = _val; isLeaf = _isLeaf; topLeft =
_topLeft; topRight = _topRight; bottomLeft = _bottomLeft; bottomRight =
_bottomRight;
    }
};
*/
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
using umii = unordered_map<int, int>;
using umcvi = unordered_map<char, vi>;
using umci = unordered_map<char, int>;
#define pb push_back
#define MOD 1000000007
#define LMOD 1000000000000000007LL
class Solution {
public:
  Node *solve(Node *first, Node *second) {
    if (first->isLeaf)
      return first->val ? first : second;
    if (second->isLeaf)
      return second->val ? second : first;

    Node *tL = solve(first->topLeft, second->topLeft);
    Node *tR = solve(first->topRight, second->topRight);
    Node *bL = solve(first->bottomLeft, second->bottomLeft);
    Node *bR = solve(first->bottomRight, second->bottomRight);

    if (tL->isLeaf && tR->isLeaf && bL->isLeaf && bR->isLeaf && tL->val == tR->val && tR->val == bL->val && bL->val == bR->val)
      return new Node(tL->val, true);
    return new Node(0, 0, tL, tR, bL, bR);
  }

  Node *intersect(Node *quadTree1, Node *quadTree2) {
    return solve(quadTree1, quadTree2);
  }
};
