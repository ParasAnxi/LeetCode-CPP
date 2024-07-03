class Solution
{
public:
    bool threeConsecutiveOdds(vector<int> &arr)
    {
        for (int i = 0; i < arr.size(); i++)
        {
            if (arr[i] % 2 == 0)
            {
                arr[i] = 0;
            }
            else
                arr[i] = 1;
        }
        if (arr.size() < 3)
        {
            return false;
        }

        for (int i = 0; i <= arr.size() - 3; i++)
        {
            int sum = 0;
            sum = arr[i] + arr[i + 1] + arr[i + 2];
            if (sum == 3) 
            {
                return true;
            }
        }
        return false;
    }
};