class Solution
{
public:
    string minRemoveToMakeValid(string s)
    {
        stack<int> st;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(')
            {
                st.push(i);
            }
            if (s[i] == ')' && !st.empty())
            {
                st.pop();
            }
            else if (s[i] == ')' && st.empty())
            {
                s[i] = ' ';
            }
        }
        while (!st.empty())
        {
            s[st.top()] = ' ';
            st.pop();
        }

        s.erase(remove(s.begin(), s.end(), ' '), s.end());
        return s;
    }
};