class Solution{
public:
    int maxDepth(string s){
        int n = s.length();
        int c = 0;
        int count = 0;
        for (int i = 0; i < n; i++){
            if (s[i] == '('){
                c++;
                count = max(count, c);
            }
            else if (s[i] == ')'){
                c--;
            }
        }
        return count;
    }
};