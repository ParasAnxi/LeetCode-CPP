class Solution {
public:
    int lengthOfLastWord(string s) { 
        int j = s.size() - 1;
        int count = 0;
        while(s[j] == ' ') j--;
        while(j >= 0) {
            if(s[j] == ' ') 
            return count;
            count++;
            j--;
        }
        return count;
    }
};