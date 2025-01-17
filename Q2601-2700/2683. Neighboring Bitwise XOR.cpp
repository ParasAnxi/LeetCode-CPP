class Solution
{
public:
    bool doesValidArrayExist(vector<int> &derived)
    {

        int sum = 0;
        for (auto &i : derived)
        {
            sum ^= i;
        }
        return !sum;
    }
};