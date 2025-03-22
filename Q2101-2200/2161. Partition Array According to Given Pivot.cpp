class Solution
{
public:
    vector<int> pivotArray(vector<int> &nums, int pivot)
    {
        vector<int> small, equal, large;

        for (int i : nums)
        {
            if (i < pivot)
                small.push_back(i);
            else if (i == pivot)
                equal.push_back(i);
            else
                large.push_back(i);
        }

        small.insert(small.end(), equal.begin(), equal.end());
        small.insert(small.end(), large.begin(), large.end());

        return small;
    }
};