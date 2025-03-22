class Solution
{
public:
    vector<int> solve(vector<set<int>> &v, int mid)
    {
        int n = v.size();
        int pivot = -1e5;
        while (true)
        {
            int next = 1e5;
            int maxi = pivot;
            for (int i = 0; i < n; i++)
            {
                auto it = v[i].lower_bound(pivot);
                auto ub = v[i].upper_bound(pivot);
                if (it == v[i].end()) return {0, -1};

                if (ub != v[i].end()) next = min(next, *ub);

                maxi = max(maxi, *it);
            }

            if (maxi - pivot <= mid)
                return {pivot, maxi};
            pivot = next;
        }

        return {0, -1};
    }

    vector<int> smallestRange(vector<vector<int>> &nums)
    {
        int n = nums.size();
        vector<set<int>> v(n);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < nums[i].size(); j++)
            {
                v[i].insert(nums[i][j]);
            }
        }

        vector<int> ans;

        int left = 0, right = 1e7;
        while (left <= right)
        {
            int mid = (left + right) / 2;
            vector<int> temp = solve(v, mid);
            if (temp[1] >= temp[0])
            {
                ans = temp;
                right = mid - 1;
            }
            else
                left = mid + 1;
        }
        return ans;
    }
};