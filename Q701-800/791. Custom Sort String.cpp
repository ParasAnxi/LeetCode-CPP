class Solution{
public:
    string customSortString(string order, string s){
        string ans = "";
        string res = "";
        unordered_map<char, int> mp;
        for (char ch : s){
            mp[ch] += 1;
        }
        for (int i = 0; i < order.size(); i++){
            auto x = mp.find(order[i]);
            if (x != mp.end()){
                while (x->second--){
                    ans += x->first;
                }
            }
        }
        for (auto i : mp){
            while (i.second > 0){
                res += i.first;
                i.second--;
            }
        }
        return ans + res;
    }
};