class Solution {
public:

    void Sum(vector<int>& candidates, int target, vector<vector<int> >& ans, vector<int>& v, int i)
    {
        if(target == 0)
        {
            ans.push_back(v);   
        }
        
        while(i < candidates.size() && target - candidates[i] >= 0)
        {
            v.push_back(candidates[i]);
            Sum(candidates,target - candidates[i],ans,v,i);
            ++i;
            v.pop_back();
        }
}
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end()); 
       
        candidates.erase(unique(candidates.begin(),candidates.end()),candidates.end());
        
        vector<int> v;
        vector<vector<int> > ans;
        
        Sum(candidates,target,ans,v,0);
        
        return ans;
    }
};