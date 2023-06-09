class Solution {
public:
    string removeDuplicates(string s) {
        // int x = s.size();
        // if(x==1) return s;
        // for(auto i=0;i<x-1;i++){
        //     if(s[i]==s[i+1]){
        //         s.erase(i,2);
        //         break;
        //     }
        // }
        // if(x==s.size()) return s;
        // return removeDuplicates(s);
        
       
        // string ans = "";
        // for (int i=0; i < s.size(); i++) {
        //     if (s[i] == s[i+1])
        //         i++;
        //     else
        //         ans += s[i];
        // }
        // if (s.length() != ans.length())
        //     ans = removeDuplicates(ans);
        // return ans;
        int i=1;
        string ans;
        
        ans.push_back(s[0]);
        while(i<s.length())
        {
            if(ans.empty() == 0)
            {
                if(ans.back()==s[i])
                {
                    ans.pop_back();
                }
                else
                {
                    ans.push_back(s[i]);
                }
            }
            else
            {
                ans.push_back(s[i]);
            }
            i++; 
        }
        return ans;
    
    }
};