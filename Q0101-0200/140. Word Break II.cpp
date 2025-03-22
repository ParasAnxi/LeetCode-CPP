class Solution {
public:
      vector<string>res;
      void solve(string s, vector<string>& words,int i,string st){
        if(i >= s.length()){
            st.pop_back();
            res.push_back(st);
            return;
        }
        string temp;
        for(int j=i;j<s.length();j++){
            temp.push_back(s[j]);
          auto it = std::find(words.begin(),words.end(), temp);
      if (it != words.end()) {
          solve(s,words,j+1,st+temp+" ");
      }
        }
      }
        vector<string> wordBreak(string s, vector<string>& words) {
            solve(s,words,0,"");
            return res;
    }
};