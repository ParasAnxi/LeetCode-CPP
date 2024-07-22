class Solution
{
public:
    vector<string> sortPeople(vector<string> &names, vector<int> &heights){
        vector<string> ans;
        int n = names.size();
        vector<int> v(n);
        for (int i = 0; i < n; i++){
            v[i] = i;
        }
        sort(v.begin(), v.end(), [&heights](int s1, int s2){ 
            return heights[s1] > heights[s2];
        });
        for (int i = 0; i < n; i++){
            ans.push_back(names[v[i]]);
        }
        return ans;
    }
};