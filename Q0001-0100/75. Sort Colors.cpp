class Solution {
public:
    void sortColors(vector<int>& arr) {
        for(int i = 0 ; i< arr.size();i++){
            for(int j = i+1;j<arr.size();j++){
                if(arr[i]>arr[j]){
                    int temp = arr[i];
                    arr[i]=arr[j];
                    arr[j]=temp;
                }      
            }
        }
    }
};
class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        int n = nums.size();
        int s = 0;
        int e = n - 1;
        int mid = 0;
        while (mid <= e)
        {
            if (nums[mid] == 0)
            {
                swap(nums[mid], nums[s]);
                s++;
                mid++;
            }
            else if (nums[mid] == 1)
            {
                mid++;
            }
            else if (nums[mid] == 2)
            {
                swap(nums[mid], nums[e]);
                e--;
            }
        }
    }
};