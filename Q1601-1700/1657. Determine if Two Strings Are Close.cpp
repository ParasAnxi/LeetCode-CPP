class Solution
{
public:
    bool closeStrings(string word1, string word2)
    {
        int n = word1.size();
        int m = word2.size();
        if (n != m)
            return false;
        set<char> s1;
        set<char> s2;
        int temp = 0;
        vector<int> freq1(26, 0);
        vector<int> freq2(26, 0);
        for (int i = 0; i < n; i++)
        {
            s1.insert(word1[i]);
            s2.insert(word2[i]);
            freq1[word1[i] - 'a']++;
            freq2[word2[i] - 'a']++;
        }
        sort(freq1.begin(), freq1.end());
        sort(freq2.begin(), freq2.end());
        if (s1 == s2 && freq1 == freq2)
            return true;
        return false;
    }
};