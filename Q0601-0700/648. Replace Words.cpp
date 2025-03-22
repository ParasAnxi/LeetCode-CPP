class Trie {
public:
    class Node {
    public:
        Node* children[26] = {NULL};
        bool isTerminal = false;
    };

    Node* root;

    Trie() {
        root = new Node();
    }

    void add(string& word) {
        Node* temp = root;
        for (char c : word) {
            int index = c - 'a';
            if (temp->children[index] == NULL) {
                temp->children[index] = new Node();
            }
            temp = temp->children[index];
        }
        temp->isTerminal = true;
    }

    string getRoot(string& word) {
        Node* temp = root;
        for (int i = 0; i < word.size(); ++i) {
            if (temp->isTerminal) return word.substr(0, i);
            int index = word[i] - 'a';
            if (temp->children[index] == NULL) return "";
            temp = temp->children[index];
        }
        return word;
    }
};

class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        Trie trie;
        for (string& word : dictionary) {
            trie.add(word);
        }

        istringstream iss(sentence);
        string word;
        string ans;
        while (iss >> word) {
            string root = trie.getRoot(word);
            if (!root.empty()) {
                ans += root + " ";
            } else {
                ans += word + " ";
            }
        }

        if (!ans.empty()) {
            ans.pop_back();
        }
        return ans;
    }
};