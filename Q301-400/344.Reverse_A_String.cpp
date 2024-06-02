class Solution {
public:
    void reverseString(vector<char>& s) {
        int start=0;
        int end=s.size()-1;
        
        while(start<end){
            swap(s[start++],s[end--]);
        }
    }
};
class Solution
{
public:
    void reverseString(vector<char> &s)
    {
        reverse(s.begin(), s.end());
    }
};