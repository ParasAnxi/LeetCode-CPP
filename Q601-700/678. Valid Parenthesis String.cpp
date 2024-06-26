class Solution
{
public:
    bool checkValidString(string s)
    {
        stack<int> st, st2;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '(')
            {
                st.push(i);
            }
            else if (s[i] == '*')
            {
                st2.push(i);
            }
            else
            {
                if (!st.empty())
                {
                    st.pop();
                }
                else if (!st2.empty())
                {
                    st2.pop();
                }
                else
                {
                    return false;
                }
            }
        }
        while (!st.empty())
        {
            if (st2.empty())
            {
                return false;
            }
            else if (st.top() < st2.top())
            {
                st.pop();
                st2.pop();
            }
            else
            {
                return false;
            }
        }
        return true;
    }
};