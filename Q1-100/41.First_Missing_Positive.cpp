class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n=nums.size();
        set<int>s;
        for(int i=0;i<n;i++){
            s.insert(nums[i]);
        }
        int i=1;

        while(i<=n){
            if(s.find(i)!=s.end()){
                i++;
            }
            else{
                return i;
            }
          
        }
          return n+1;
    }
};