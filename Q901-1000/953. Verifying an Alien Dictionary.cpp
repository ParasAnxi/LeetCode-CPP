class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        int k = 0;
        for(const char c : order) {
            char_rank[c - 'a'] = k++;
        }
        for(int i = 0; i < words.size() - 1; ++i) {
            if(!compareWords(words[i], words[i+1])) {
                return false;
            }
        }
        return true;
    }
private:
    bool compareWords(const string &word1, const string &word2) {
        int size = min(word1.size(), word2.size());
        for(int i = 0; i < size; ++i) { 
            if(word1[i] != word2[i]) {
                return char_rank[word1[i] - 'a'] < char_rank[word2[i] - 'a'] ? true : false;
            }
        }
        return word1.size() > word2.size() ? false : true;
    }
    static constexpr int N = 26;
    std::array<int, N> char_rank{0};
};