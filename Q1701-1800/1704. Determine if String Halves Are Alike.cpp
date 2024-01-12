class Solution
{
public:
    bool isVowel(char c){
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
            return true;
        else
            return false;
    }
    bool halvesAreAlike(string s){
        int a = 0, b = 0;
        int i = 0, j = s.length() - 1;
        while (i < j){
            a += isVowel(s[i++]);
            b += isVowel(s[j--]);
        }
        return a == b;
    }
};