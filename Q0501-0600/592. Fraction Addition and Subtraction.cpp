class Solution
{
public:
    string fractionAddition(string expression)
    {
        int d = 0;
        expression = '+' + expression;
        for (int i = 0; i < expression.length(); i++)
        {
            if (expression[i] == '/')
            {
                int temp = i + 1;
                string toDel = "";
                while (temp < expression.length() && expression[temp] != '+' && expression[temp] != '-')
                {
                    toDel += expression[temp];
                    temp++;
                }

                int del = stoi(toDel);
                if (!d)
                {
                    d = del;
                }
                else
                {
                    d = lcm(d, del);
                }
            }
        }
        int n = 0;
        for (int i = 0; i < expression.length(); i++)
        {
            if (expression[i] == '/')
            {
                string num = "";
                string toDel = "";

                int temp = i + 1;
                while (temp < expression.length() && expression[temp] != '+' && expression[temp] != '-')
                {
                    toDel += expression[temp];
                    temp++;
                }
                temp = i - 1;
                while (expression[temp] != '+' && expression[temp] != '-')
                {
                    num = expression[temp] + num;
                    temp--;
                }
                int mul = stoi(num) * (d / stoi(toDel));

                if (expression[temp] == '+')
                {
                    n += mul;
                }
                else
                {
                    n -= mul;
                }
            }
        }
        return to_string(n / gcd(n, d)) + "/" + to_string(d / gcd(n, d));
    }
};