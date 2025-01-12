class Solution
{
public:
    bool canBeValid(string s, string locked)
    {
        vector<int> arr1, arr2;

        for (int i = 0; s[i] != '\0'; i++)
        {
            if (locked[i] == '0')
                arr2.push_back(i);
            else if (s[i] == '(')
                arr1.push_back(i);
            else
            {
                if (arr1.size())
                    arr1.pop_back();
                else if (arr2.size())
                    arr2.pop_back();
                else
                    return false;
            }
        }

        while (arr1.size() || arr2.size())
        {
            if (arr1.size())
            {
                if (arr2.size())
                {
                    if (arr1.back() > arr2.back())
                        return false;
                    arr1.pop_back();
                    arr2.pop_back();
                }
                else
                    return false;
            }
            else
            {
                if (arr2.size() > 1)
                {
                    arr2.pop_back();
                    arr2.pop_back();
                }
                else
                    return false;
            }
        }

        return true;
    }
};