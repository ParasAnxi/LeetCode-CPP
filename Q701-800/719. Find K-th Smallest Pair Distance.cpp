class Solution
{
public:
    int countPairs(map<int, int>& mp, int target, int k)
    {
        int count = 0;
        int curr = 0;
        for (auto i = mp.begin(), j = mp.begin(); i != mp.end(); ++i)
        {
            while (j->first < i->first - target)
            {
                curr -= j->second;
                ++j;
            }
            count += curr * i->second;
            count += (i->second - 1) * i->second / 2;
            curr += i->second;
            if (count >= k){
                return k;
            }
        }
        return count;
    }
    int smallestDistancePair(vector<int> &nums, int k)
    {
        map<int, int> mp;
        for (auto n : nums){
            mp[n]++;
        }
        int left = 0;
        int right = 10e6;
        int ans = -1;
        while (left <= right)
        {
            int mid = (left + right) / 2;
            if (countPairs(mp, mid, k) < k){
                left = mid + 1;
            }
            else
            {
                ans = mid;
                right = mid - 1;
            }
        }
        return ans;
    }
};