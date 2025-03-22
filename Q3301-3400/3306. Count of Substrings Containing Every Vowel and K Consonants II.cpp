class Solution
{
public:
    long long countOfSubstrings(string word, int k)
    {
        return atleast(word, k) - atleast(word, k + 1);
    }

    long long atleast(string word, int k)
    {
        vector<int> freq(26, 0);
        int count = 0;
        int cons = 0;
        int l = 0;
        long long ans = 0;
        string vowels = "aeiou";
        for (int r = 0; r < word.size(); r++)
        {
            if (vowels.contains(word[r]))
            {
                if (freq[word[r] - 'a'] == 0)
                {
                    count++;
                }
                freq[word[r] - 'a']++;
            }
            else
            {
                cons++;
            }
            while (count == 5 && cons >= k)
            {
                ans += word.size() - r;
                if (vowels.contains(word[l]))
                {
                    freq[word[l] - 'a']--;
                    if (freq[word[l] - 'a'] == 0)
                    {
                        count--;
                    }
                }
                else
                {
                    cons--;
                }
                l++;
            }
        }
        return ans;
    }
};