class Solution
{
public:
    int longestCommonSubsequence(string text1, string text2)
    {
        int arr[1001][1001];
        memset(arr, 0, sizeof(arr));
        int n1 = text1.size();
        int n2 = text2.size();
        for (int i = 1; i <= n1; i++){
            for (int j = 1; j <= n2; j++){
                if (text1[i - 1] == text2[j - 1]){
                    arr[i][j] = 1 + arr[i - 1][j - 1];
                }
                else{
                    arr[i][j] = max(arr[i - 1][j], arr[i][j - 1]);
                }
            }
        }
        return arr[n1][n2];
    }
};