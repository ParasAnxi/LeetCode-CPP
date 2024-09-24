class Solution
{
public:
    int longestCommonPrefix(vector<int> &arr1, vector<int> &arr2)
    {
        unordered_set<string> st;
        for (auto x : arr1)
        {
            string str = to_string(x);
            string s;
            for (int i = 0; i < str.size(); i++)
            {
                s += str[i];
                st.insert(s);
            }
        }
        int length = 0;
        for (auto x : arr2)
        {
            string str = to_string(x);
            string s;
            for (int i = 0; i < str.size(); i++)
            {
                s += str[i];
                if (st.find(s) != st.end() && s.size() > length)
                    length = s.size();
            }
        }
        return length;
    }
};