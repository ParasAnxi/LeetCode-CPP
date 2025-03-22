class Solution
{
public:
    string compressedString(string word)
    {
        string st = "";
        int n = word.length();
        int i = 0;
        while (i < n)
        {
            char curr = word[i];
            int count = 0;

            while (i < n && word[i] == curr && count < 9)
            {
                count++;
                i++;
            }
            st += to_string(count) + curr;
        }
        return st;
    }
};