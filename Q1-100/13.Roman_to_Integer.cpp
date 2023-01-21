class Solution {
public:
    int romanToInt(string s) {
        int z=0;
        unordered_map <char,int> x{
        {'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};
    for(int i=0;i<s.size();i++){
        if(x[s[i]]<x[s[i+1]]){
            z=z-x[s[i]];
        }
        else{
            z=z+x[s[i]];
        }
    }
        return z;
    }
};