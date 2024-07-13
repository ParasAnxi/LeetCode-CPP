class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        vector<pair<pair<int,int>,char>> ans;
        vector<int>result;
        for(int i=0;i<n;i++){
            ans.push_back({{positions[i],healths[i]},directions[i]});
        }
        sort(ans.begin(),ans.end());
        stack<pair<pair<int,int>,char>>st;
        for(int i=0;i<n;i++){
            if(st.empty() || st.top().second=='L' || ans[i].second=='R'){
                st.push(ans[i]);
            }else{
                while(!st.empty() && st.top().second=='R' && ans[i].second=='L'){
                    auto p = st.top(); 
                    if(ans[i].first.second>p.first.second){
                        st.pop();
                        ans[i].first.second--;
                    }else if(ans[i].first.second==p.first.second){
                        st.pop();
                        ans[i].first.second = -1;
                        break;
                    }else{
                        st.pop();
                        p.first.second--;
                        st.push(p);
                        ans[i].first.second = -1;
                        break;
                    }
                }
                if (ans[i].first.second > 0) {
                    st.push(ans[i]);
                }
            }
        }
        
        map<int,int>freq;
        while(!st.empty()){
            auto p = st.top();
            st.pop();
            freq[p.first.first]=p.first.second;
        }
        for(int i=0;i<n;i++){
            if(freq.find(positions[i])!=freq.end()){
                result.push_back(freq[positions[i]]);
            }            
        }
        return result;
    }
};