class Solution
{
public:
    vector<string> solve(string &sentence)
    {
        vector<string> ans;
        string st;
        stringstream ch(sentence);
        while (ch >> st)
        {
            ans.push_back(st);
        }
        return ans;
    }

    bool areSentencesSimilar(string sentence1, string sentence2)
    {
        vector<string> words1 = solve(sentence1);
        vector<string> words2 = solve(sentence2);

        int n1 = words1.size();
        int n2 = words2.size();
        int i = 0;
        int j = 0;
        int mini = min(n1, n2);

        while (i < n1 && i < n2 && words1[i] == words2[i])
        {
            i++;
        }

        while (j < n1 - i && j < n2 - i &&
               words1[n1 - 1 - j] == words2[n2 - 1 - j])
        {
            j++;
        }

        return i + j == mini;
    }
}