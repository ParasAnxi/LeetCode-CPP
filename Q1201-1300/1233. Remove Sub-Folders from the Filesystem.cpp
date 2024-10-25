
class Solution
{
public:
    vector<string> removeSubfolders(vector<string> &folder)
    {
        sort(folder.begin(), folder.end());
        vector<string> ans;
        for (const string &st : folder)
        {
            if (ans.empty() || st.find(ans.back() + "/") != 0)
            {
                ans.push_back(st);
            }
        }
        return ans;
    }
};