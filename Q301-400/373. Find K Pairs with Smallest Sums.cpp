class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<array<int,3>,vector<array<int,3>>,greater<array<int,3>>> pq;
        for(int i=0;i<nums1.size();i++)
            pq.push({nums1[i]+nums2[0],i,0});
        vector<vector<int>> ans;
         while(k-- and !pq.empty()){
             array<int,3> t=pq.top();
             pq.pop();
             ans.push_back({nums1[t[1]],nums2[t[2]]});
             if(t[2]<nums2.size()-1)
                 pq.push({nums1[t[1]]+nums2[t[2]+1],t[1],t[2]+1});
         }
        return ans;
    }
};