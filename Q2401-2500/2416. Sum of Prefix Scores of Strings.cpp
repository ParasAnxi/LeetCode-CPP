class Node
{
public:
    Node *children[26];
    bool isTerminal;
    int c;
    Node()
    {
        c = 0;
        isTerminal = false;
        for (int i = 0; i < 26; i++)
        {
            children[i] = nullptr;
        }
    }
};
class Trie
{
private:
    void insert(Node *root, string s)
    {
        Node *curr = root;
        for (char c : s)
        {
            int i = c - 'a';
            if (curr->children[i] == nullptr)
            {
                curr->children[i] = new Node();
            }
            curr = curr->children[i];
            curr->c += 1;
        }
        curr->isTerminal = true;
    }
    int startsWith(Node *root, string s)
    {
        int cnt = 0;
        Node *curr = root;
        for (char c : s)
        {
            int i = c - 'a';
            if (curr->children[i] == nullptr)
                return 0;
            curr = curr->children[i];
            cnt += curr->c;
        }
        return cnt;
    }

public:
    Node *root;
    Trie()
    {
        root = new Node();
    }
    void insert(string s)
    {
        insert(root, s);
    }
    int startWith(string s)
    {
        return startsWith(root, s);
    }
};
class Solution
{
public:
    vector<int> sumPrefixScores(vector<string> &words)
    {
        Trie t;
        for (string str : words)
        {
            t.insert(str);
        }
        vector<int> ans;
        for (string s : words)
        {
            ans.push_back(t.startWith(s));
        }
        return ans;
    }
};