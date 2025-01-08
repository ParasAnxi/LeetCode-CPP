class Solution
{
public:
    int countPrefixSuffixPairs(vector<string> &words)
    {
        int count = 0;
        bool check = true;
        for (int i = 0; i < words.size(); i++)
        {
            string target = words[i];
            for (int j = i + 1; j < words.size(); j++)
            {
                string temp = words[j];
                if (temp.size() >= target.size())
                {
                    int k = 0;
                    check = true;
                    while (k < target.size() && k < temp.size())
                    {
                        if (target[k] != temp[k])
                        {
                            check = false;
                            break;
                        }
                        k++;
                    }
                    if (check)
                    {
                        int t = target.size() - 1;
                        int e = temp.size() - 1;
                        while (t >= 0)
                        {
                            if (temp[e] != target[t])
                            {
                                check = false;
                                break;
                            }
                            t--;
                            e--;
                        }
                        if (check)
                            count++;
                    }
                }
            }
        }
        return count;
    }
};