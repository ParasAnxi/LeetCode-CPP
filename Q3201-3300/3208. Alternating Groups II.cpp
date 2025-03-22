class Solution{
public:
    int numberOfAlternatingGroups(vector<int> &colors, int k){
        int clr = -1;
        int n = colors.size();
        int ans = 0;
        for (int i = 1; i < n + k; i++){
            if (colors[i % n] == colors[(i - 1) % n]){
                clr = i;
            }
            else if (i >= k && (clr == -1 || clr <= i - k + 1)){
                ans++;
            }
        }
        return ans;
    }
};