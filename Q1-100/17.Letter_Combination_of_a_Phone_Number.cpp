class Solution {
private:
    void solve(string dig, vector<string>& ans,int i,string map[],string out){
        if(i>=dig.length()){
            ans.push_back(out);
            return ;
        }
        int number = dig[i] - '0';
        string value = map[number];
        for(int i =0;i<value.length();i++){
            out.push_back(value[i]);
            solve(dig,ans,i+1,map,out);
            out.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string dig) {
        vector<string> ans;
        if(dig.length()==0){
            return ans;
        }
        int i =0;
        string map[10] = { "" ,"", "abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        string out="";
        solve(dig, ans,i,map,out);
        return ans;
    }
};