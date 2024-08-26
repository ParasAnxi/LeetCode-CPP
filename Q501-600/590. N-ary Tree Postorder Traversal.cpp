/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution
{
public:
    vector<int> postorder(Node *root)
    {
        if (!root) return {};
        vector<int> ans;
        stack<Node *> st;
        st.push(root);
        st.push(root);
        while (!st.empty())
        {
            Node *curr = st.top();
            st.pop();
            if (!st.empty() && st.top() == curr)
            {
                for (int i = curr->children.size() - 1; i >= 0; --i)
                {
                    Node *r = curr->children[i];
                    st.push(r);
                    st.push(r);
                }
            }
            else
            {
                ans.push_back(curr->val);
            }
        }
        return ans;
    }
};