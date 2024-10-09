class Solution
{
public:
    int minAddToMakeValid(string s)
    {
        int n = s.length();
        int ans = 0;
        stack<char> st;

        for (int i = 0; i < n; i++)
        {
            if (s[i] == '(')
            {
                st.push(s[i]);
            }
            else if (s[i] == ')')
            {
                if (!st.empty() && st.top() == '(')
                {
                    st.pop();
                }
                else
                {
                    ans++;
                }
            }
        }
        return ans + st.size();
    }
};