class Solution
{
public:
    vector<int> sequentialDigits(int low, int high)
    {
        vector<int> ans;
        vector<int> temp;
        for (int i = 1; i <= 9; i++){
            int nums = i;
            for (int j = i + 1; j <= 9; j++){
                nums = (nums * 10) + j;
                temp.push_back(nums);
            }
        }
        sort(temp.begin(), temp.end());
        for (int i = 0; i < temp.size(); i++){
            if (temp[i] >= low && high >= temp[i]){
                ans.push_back(temp[i]);
            }
        }
        return ans;
    }
};