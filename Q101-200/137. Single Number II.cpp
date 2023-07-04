class Solution {
public:
    int singleNumber(vector<int>& nums) {
        vector<int> a(32,0);
        for(auto x:nums){
            for(int i=0;i<32;++i){
                a[i] += (x>>i)&1;
            }
        }
        int ans = 0;
        for(int i=0;i<32;++i){
            if(a[i]%3){
                ans += (1<<i);
            }
        }
        return ans;
    }
};