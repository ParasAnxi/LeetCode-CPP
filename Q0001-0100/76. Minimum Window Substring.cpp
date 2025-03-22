class Solution
{
public:
    string minWindow(string s, string t)
    {
        if (s.length() < t.length())
            return "";

        unordered_map<char, int> mp1, mp2, required;
        unordered_set<char> st;

        for (char ch : t)
        {
            mp1[ch]++;
            st.insert(ch);
            required[ch]++;
        }

        int maxDiff = INT_MAX;
        int start = 0, end = 0;
        bool flag = true;
        int i = 0;

        for (int j = 0; j < s.length(); ++j)
        {
            char ch = s[j];

            if (st.count(ch))
            {
                if (mp1.count(ch))
                {
                    mp1[ch]--;
                    if (mp1[ch] == 0)
                        mp1.erase(ch);
                }

                mp2[ch]++;

                while (mp1.empty() && i <= j)
                {
                    if (j - i + 1 < maxDiff)
                    {
                        flag = false;
                        start = i;
                        end = j;
                        maxDiff = j - i + 1;
                    }
                    char temp = s[i];
                    if (st.count(temp))
                    {
                        mp2[temp]--;
                        if (mp2[temp] < required[temp])
                        {
                            ++mp1[temp];
                        }
                    }
                    ++i;
                }
            }
        }

        if (flag)
            return "";

        return s.substr(start, maxDiff);
    }
};