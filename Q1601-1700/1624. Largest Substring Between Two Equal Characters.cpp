class Solution
{
public:
    int maxLengthBetweenEqualCharacters(string s)
    {
        int n = s.size();
        vector<int> chars(26, -1);
        int maxi = -1;

        for (int i = 0; i < n; i++)
        {
            int cI = s[i] - 'a';
            if (chars[cI] == -1)
            {
                chars[cI] = i;
            }
            else
            {
                maxi = max(maxi, i - chars[cI] - 1);
            }
        }
        return maxi;
    }
};
