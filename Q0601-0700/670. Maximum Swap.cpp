class Solution
{
public:
    int maximumSwap(int num)
    {
        vector<int> v(10, -1);
        vector<int> digits;
        int temp = num;
        int index = 0;
        while (temp != 0)
        {
            int unit = temp % 10;
            digits.push_back(unit);
            if (v[unit] == -1)
            {
                v[unit] = index;
            }

            temp = temp / 10;
            index++;
        }
        int n = digits.size();
        int i = n - 1;

        while (i >= 0)
        {

            for (int d = 9; d > digits[i]; d--)
            {
                if (v[d] != -1 && v[d] < i)
                {
                    swap(digits[i], digits[v[d]]);
                    int ans = 0;
                    for (int j = n - 1; j >= 0; j--)
                    {
                        ans = ans * 10 + digits[j];
                    }
                    return ans;
                }
            }
            i--;
        }

        return num;
    }
};