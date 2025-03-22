class Solution
{
public:
    bool ispresent(string &s1, vector<string> &s2)
    {
        for (int i = 0; i < s2.size(); i++)
        {
            if (s2[i] == s1)
                return true;
        }
        return false;
    }

    int count(string &s1, vector<string> &s3)
    {
        int count = 0;
        for (int i = 0; i < s3.size(); i++)
        {
            if (s3[i] == s1)
                count++;
        }
        return count;
    }

    vector<string> get_words(string &s1)
    {
        vector<string> ans;
        string temp = "";
        for (int i = 0; i < s1.size(); i++)
        {
            if (i == s1.size() - 1)
            {
                temp.push_back(s1[i]);
                ans.push_back(temp);
            }
            else if (s1[i] != ' ')
            {
                temp.push_back(s1[i]);
            }
            else
            {
                ans.push_back(temp);
                temp = "";
            }
        }
        return ans;
    }
    vector<string> intersection(vector<string> &s1, vector<string> &s2)
    {
        vector<string> ans;
        for (int i = 0; i < s1.size(); i++)
        {
            if (ispresent(s1[i], s2) == false && count(s1[i], s1) == 1)
            {
                ans.push_back(s1[i]);
            }
        }

        for (int i = 0; i < s2.size(); i++)
        {
            if (ispresent(s2[i], s1) == false && count(s2[i], s2) == 1)
            {
                ans.push_back(s2[i]);
            }
        }

        return ans;
    }
    vector<string> uncommonFromSentences(string s1, string s2)
    {
        vector<string> res = get_words(s1);
        vector<string> ans = get_words(s2);

        ans = intersection(res, ans);

        return ans;
    }
};