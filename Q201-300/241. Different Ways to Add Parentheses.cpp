class Solution
{

private:
    bool isNumber(const string &s)
    {
        for (char c : s)
        {
            if (!isdigit(c))
                return false;
        }
        return true;
    }

    unordered_map<string, vector<int>> dp;

    vector<int> solve(const string &exp)
    {
        vector<int> result;

        if (dp.count(exp))
            return dp[exp];

        if (isNumber(exp))
        {
            result.push_back(stoi(exp));
            return result;
        }

        int n = exp.size();

        for (int i = 0; i < n; i++)
        {
            char c = exp[i];

            if (c == '+' || c == '-' || c == '*')
            {
                vector<int> leftAns = solve(exp.substr(0, i));
                vector<int> rightAns = solve(exp.substr(i + 1));

                for (int left : leftAns)
                {
                    for (int right : rightAns)
                    {
                        if (c == '+')
                            result.push_back(left + right);
                        else if (c == '-')
                            result.push_back(left - right);
                        else
                            result.push_back(left * right);
                    }
                }
            }
        }
        dp[exp] = result;
        return result;
    }

public:
    vector<int> diffWaysToCompute(string expression)
    {
        return solve(expression);
    }
};