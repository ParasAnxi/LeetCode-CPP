class Solution
{
public:
    int garbageCollection(vector<string> &garbage, vector<int> &travel)
    {
        int ans = 0;
        int n = garbage.size();
        int i = 0;
        int dism = 0, disg = 0, disp = 0;
        for (auto it : garbage)
        {
            string s = it;
            for (int j = 0; j < s.size(); j++)
            {
                if (s[j] == 'M')
                {
                    ans++;
                    ans += dism;
                    dism = 0;
                }
                if (s[j] == 'G')
                {
                    ans++;
                    ans += disg;
                    disg = 0;
                }
                if (s[j] == 'P')
                {
                    ans++;
                    ans += disp;
                    disp = 0;
                }
            }
            if (i != n - 1)
            {
                dism += travel[i];
                disp += travel[i];
                disg += travel[i];
            }
            i++;
        }
        return ans;
    }
};