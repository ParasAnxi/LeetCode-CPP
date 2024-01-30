class Solution
{
public:
    int evalRPN(vector<string> &tokens)
    {
        stack<int> s;
        for (auto i : tokens)
        {
            if (i == "*" || i == "+" || i == "-" || i == "/")
            {
                int b = s.top(), a;
                s.pop();
                a = s.top();
                s.pop();
                if (i == "*")
                    a *= b;
                else if (i == "+")
                    a += b;
                else if (i == "-")
                    a -= b;
                else
                    a /= b;
                s.push(a);
            }
            else
                s.push(stoi(i));
        }
        return s.top();
    }
};