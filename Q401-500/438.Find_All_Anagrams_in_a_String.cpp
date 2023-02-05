class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int sL = s.length();
        int pL = p.length();
        
        if(s.size() < p.size()) 
            return {};
        
        vector<int> freq_p(26,0);
        vector<int> window(26,0);
        
     
        for(int i=0;i<pL;i++){
            freq_p[p[i]-'a']++;
            window[s[i]-'a']++;
        }
        
        vector<int> ans;
        if(freq_p == window) 
            ans.push_back(0);
        
        for(int i=pL;i<sL;i++){
            window[s[i-pL] - 'a']--;
            window[s[i] - 'a']++;
            
            if(freq_p == window) 
                ans.push_back(i-L+1);
        }
        return ans;
    }
};