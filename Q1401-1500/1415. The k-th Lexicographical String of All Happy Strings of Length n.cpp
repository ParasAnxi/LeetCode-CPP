class Solution
{
    string dfs(string prefix, int n, int k)
    {
        int n2 = n;
        if (n == 0) return prefix;
        for (char ch = 'a'; ch <= 'c'; ch++){
            if (!prefix.empty() && ch == prefix.back()) continue;
            int count = (1 << (n2 - prefix.length() - 1));
            if (count >= k)
                return dfs(prefix + ch, n - 1, k);
            else
                k -= count;
        }
        return "";
    }

public:
    string getHappyString(int n, int k)
    {
        return dfs("", n, k);
    }
};