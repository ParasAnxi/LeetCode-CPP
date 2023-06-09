class Solution {
public:
    int intersect(unordered_set<string> &one,unordered_set<string> &two){
        int i=0;
        for(auto x : one){
            i+=two.count(x);
        }
        return i;
    }
    long long distinctNames(vector<string>& list) {
        vector<unordered_set<string> > one(26);
        for(auto x : list){
                one[x[0]-'a'].insert(x.substr(1));
        }
        long long int ans=0;
        for(int i=0;i<one.size();i++){
            for(int j=0;j<one.size();j++){
                if(i==j) continue;
                int io=intersect(one[i],one[j]);
                io=(one[i].size()-io)*(one[j].size()-io);
                ans+=io;
            }
        }
        return ans;
    }
};