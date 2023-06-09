class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
    vector<pair<string, string>>v;
    for(int i=0; i<strs.size(); i++){
        string s=strs[i];
        sort(s.begin(), s.end());
        v.push_back({s, strs[i]});
    }
    sort(v.begin(), v.end());
    unordered_map<string, vector<string>>m;
    for(int i=0; i<v.size(); i++){
        m[v[i].first].push_back(v[i].second);
    }
    vector<vector<string>>ans;
    for(auto it: m){
        ans.push_back(it.second);
    }
    return ans;
}
};