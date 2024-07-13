class Solution
{
public:
    int maximumGain(string s, int x, int y)
    {
        stack<char> st;
        stack<char> st2;
        const char fc = (x > y) ? 'a' : 'b';
        const char sc = (x < y) ? 'a' : 'b';
        unsigned int ans = 0;

        for (char c : s)
        {
            if (c == sc && st.size())
            {
                if (st.top() == fc)
                {
                    st.pop();
                    ans += max(x, y);
                    continue;
                }
            }
            st.push(c);
        }

        while (st.size())
        {
            char c = st.top();
            st.pop();
            if (c == sc && st2.size())
            {
                if (st2.top() == fc)
                {
                    st2.pop();
                    ans += min(x, y);
                    ;
                    continue;
                }
            }
            st2.push(c);
        }
        return ans;
    }
};