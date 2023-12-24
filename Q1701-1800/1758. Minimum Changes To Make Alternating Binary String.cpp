class Solution
{
private:
    int count(string s, char ch)
    {
        int count = 0;
        for (int i = 1; i < s.length(); i++)
        {
            char current = s[i];
            if (current == ch)
            {
                count++;
                ch = ch == '0' ? '1' : '0';
            }
            else
            {
                ch = current;
            }
        }
        return count;
    }

public:
    int minOperations(string s)
    {
        char ch = s[0];
        int count1 = count(s, ch);
        int count2 = count(s, ch == '0' ? '1' : '0') + 1;
        return min(count1, count2);
    }
};