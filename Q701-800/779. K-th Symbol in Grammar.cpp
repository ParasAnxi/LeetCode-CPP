class Solution
{
public:
    int kthGrammar(int n, int k)
    {
        stack<int> s;
        s.push(k);
        for (int i = 0; i < n - 2; i++)
        {
            int curr = s.top();
            if (curr % 2 == 0)
            {
                s.push(curr / 2);
            }
            else
            {
                s.push(curr / 2 + 1);
            }
        }
        int curr;
        if (s.top() == 1)
        {
            curr = 0;
        }
        else
        {
            curr = 1;
        }
        s.pop();
        while (!s.empty())
        {
            int temp = s.top();
            if (curr == 1)
            {
                if (temp % 2 == 0)
                {
                    curr = 0;
                }
                else
                {
                    curr = 1;
                }
            }
            else
            {
                if (temp % 2 == 0)
                {
                    curr = 1;
                }
                else
                {
                    curr = 0;
                }
            }
            s.pop();
        }
        return curr;
    }
};