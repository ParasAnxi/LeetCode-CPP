class Solution {
public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
        int n=nums.size();
        vector<pair<long,long>> temp;
        temp.reserve(n);
        for (int i=0; i<n; ++i)
            temp.push_back({nums[i], cost[i]});
        sort(temp.begin(), temp.end());
        
        long long ans=0;
        int target=0;
        queue<pair<long,long>> Q;
        for (long i=0, less=0, more=0; i<n; ++i) {
            ans+=(temp[i].first-target)*temp[i].second;
            Q.push(temp[i]);
            more+=temp[i].second;
            while(more>less) {
                ans+=(less-more)*(Q.front().first-target);
                target=Q.front().first;
                less+=Q.front().second;
                more-=Q.front().second;
                Q.pop();
            }
        }
        
        return ans;
    }
};