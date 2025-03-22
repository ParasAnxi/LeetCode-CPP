class Solution
{
private:
    vector<long long> solve(string &n)
    {
        int len = n.length();
        vector<long long> ans;

        ans.push_back(pow(10, len - 1) - 1);

        ans.push_back(pow(10, len) + 1);

        long long prefix = stoll(n.substr(0, (len + 1) / 2));

        for (int i = -1; i <= 1; i++)
        {
            string prefixStr = to_string(prefix + i);
            string res = prefixStr;
            if (len % 2 == 0)
            {
                res += string(prefixStr.rbegin(), prefixStr.rend());
            }
            else
            {
                res += string(prefixStr.rbegin() + 1, prefixStr.rend());
            }
            ans.push_back(stoll(res));
        }

        return ans;
    }

public:
    string nearestPalindromic(string n)
    {
        long long num = stoll(n);
        if (num <= 10)
            return to_string(num - 1);
        if (num == 11)
            return "9";

        vector<long long> ans = solve(n);
        long long maxi = LLONG_MAX;
        long long mini = LLONG_MAX;

        for (long long i : ans)
        {
            if (i == num)
                continue;
            long long diff = abs(i - num);
            if (diff < mini || (diff == mini && i < maxi))
            {
                maxi = i;
                mini = diff;
            }
        }

        return to_string(maxi);
    }


};