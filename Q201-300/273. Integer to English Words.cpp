class Solution
{
public:
    vector<string> units{"", "One", "Two", "Three",
                              "Four", "Five", "Six", "Seven",
                              "Eight", "Nine", "Ten", "Eleven",
                              "Twelve", "Thirteen", "Fourteen", "Fifteen",
                              "Sixteen", "Seventeen", "Eighteen", "Nineteen"};

    vector<string> tens{"", "", "Twenty", "Thirty", "Forty",
                        "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};

    vector<string> thousands{"", "Thousand", "Million", "Billion"};

    string solve(int num)
    {
        if (num == 0)
        {
            return "";
        }
        else if (num < 20)
        {
            return units[num] + " ";
        }
        else if (num < 100)
        {
            return tens[num / 10] + " " + solve(num % 10);
        }
        else
        {
            return units[num / 100] + " Hundred " + solve(num % 100);
        }
    }
    string numberToWords(int num)
    {
        if (num == 0)
        {
            return "Zero";
        }

        string ans;
        int i = 0;

        while (num > 0)
        {
            if (num % 1000 != 0)
            {
                ans = solve(num % 1000) + thousands[i] + " " + ans;
            }
            num /= 1000;
            i++;
        }

        while (ans.back() == ' ')
        {
            ans.pop_back();
        }

        return ans;
    }
};