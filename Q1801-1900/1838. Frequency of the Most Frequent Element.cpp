class Solution{
public:
    int maxFrequency(vector<int> &nums, int k){
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<long> v(n + 1);
        v[0] = 0;
        for (int i = 1; i <= n; i++){
            v[i] = nums[i - 1] + v[i - 1];
        }
        long ans = 0;
        for (int i = 0; i < n; i++){
            while (i + 1 < n && nums[i + 1] == nums[i]){
                i++;
            }

            int left = 0, right = i;
            while (left <= right){
                int mid = (left + right) / 2;
                long sum = v[i + 1] - v[mid];
                long t = i + 1 - mid;
                long predi = t * nums[i];
                if (predi <= sum + k){
                    ans = max(ans, t);
                    right = mid - 1;
                }
                else{
                    left = mid + 1;
                }
            }
        }
        return ans;
    }
};