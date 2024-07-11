class Solution
{
public:
    string reverseParentheses(string st)
    {
        stack<char> s;
        for (auto i : st)
        {
            if (i == ')')
            {
                vector<char> temp;
                while (s.top() != '(')
                {
                    char tp = s.top();
                    s.pop();
                    temp.push_back(tp);
                }
                s.pop();
                for (auto j : temp)
                {
                    s.push(j);
                }
            }
            else
            {
                s.push(i);
            }
        }
        string ans = "";
        while (!s.empty())
        {
            ans += s.top();
            s.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};